#include <iostream>
#include <vector>
#include <stack>
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


class Solution
{
public:
  ListNode *partition(ListNode *head, int x)
  {
    ListNode *left = NULL, *beforeHead = NULL, *newHead = head;
    while (head)
    {
      if(head->val < x && left) {
        if (beforeHead != left)
        {
          beforeHead->next = head->next;
          head->next = left->next;
          left->next = head;
        }
        left = left->next;
      }
      else if (head->val < x)
      {
        if(beforeHead) {
          beforeHead->next = head->next;
          head->next = newHead;
          newHead = head;
        }
        left = head;
      }
      beforeHead = head;
      head = head->next;
    }
    return newHead;
  }
};

// Driver program to test above function
int main()
{
  ListNode *head = stringToListNode("[2,1]");

  ListNode *ret = Solution().partition(head, 2);

  cout << listNodeToString(ret) << endl;

  return 0;
}