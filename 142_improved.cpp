#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void trimLeftTrailingSpaces(string &input)
{
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
              }));
}

void trimRightTrailingSpaces(string &input)
{
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
              })
                  .base(),
              input.end());
}

vector<int> stringToIntegerVector(string input)
{
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim))
  {
    output.push_back(stoi(item));
  }
  return output;
}

ListNode *stringToListNode(string input)
{
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list)
  {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

int stringToInteger(string input)
{
  return stoi(input);
}

string listNodeToString(ListNode *node)
{
  if (node == nullptr)
  {
    return "[]";
  }

  string result;
  while (node)
  {
    result += to_string(node->val) + ", ";
    node = node->next;
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
          return NULL;
        ListNode *first = head;
        ListNode *second = head;
        int distance = 0;
        int distanceFast = 1;
        ListNode *result = NULL;
        while (first && second)
        {
          first = first->next;
          cout << first->val << ' ';
          ++distanceFast;
          if (first)
          {
            first = first->next;
            cout << first->val << ' ';
            ++distanceFast;
          }
          second = second->next;
          ++distance;
          if (first == second){
            cout << endl;
            cout << "distance: " << distance << endl;
            cout << "distanceFast: " << distanceFast << endl;
            result = first;
            break;
          }
        }
        if(!result)
          return result;

        first = head;
        distance = 1;
        while (first != second)
        {
          first = first->next;
          second = second->next;
          ++distance;
        }
        cout << "distance: " << distance << endl;
        return first;
    }
};

int main()
{
  string line = "[0,1,2,3,4,5,6,7,8,9,10,11]";
  ListNode *head = stringToListNode(line);
  int pos = 3;
  ListNode *end = head;
  ListNode *targetNode = NULL;
  int count = 0;
  while (end->next)
  {
    if(count == pos)
      targetNode = end;
    end = end->next;
    count++;
  }
  if(count == pos)
    targetNode = end;
  end->next = targetNode;

  ListNode *result = Solution().detectCycle(head);

  if(result)
    cout << result->val - pos << endl;
  else
    cout << "NULL" << endl;
  return 0;
}