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
    bool hasCycle(ListNode *head) {
        if(!(head && head->next))
          return false;
        ListNode *first = head->next->next;
        ListNode *second = head;
        while(first && second) {
          if (first == second)
            return true;
          first = first->next;
          if(first)
            first = first->next;
          second = second->next;
        }
        return false;
    }
};

int main()
{
  string line = "[1,2,3,4,5]";
  ListNode *head = stringToListNode(line);
  int pos = 1;
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
  end->next = targetNode;

  cout << Solution().hasCycle(head) << endl;
  return 0;
}