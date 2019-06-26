#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <unordered_map>
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
  ListNode *insertionSortList(ListNode *head)
  {
    ListNode *cursor = head;
    ListNode *newHead = head;
    while (cursor)
    {
      ListNode *nextNode = cursor->next;
      ListNode *after = newHead;
      ListNode *before = NULL;
      while (after != cursor && after != NULL && after->val < cursor->val)
      {
        before = after;
        after = after->next;
      }
      if (after != cursor)
      {
        cursor->next = after;
        if (before)
          before->next = cursor;
        else
          newHead = cursor;
      } else {
        cursor->next = NULL;
      }
      cursor = nextNode;
    }
    return newHead;
  }
};

int main()
{
  ListNode *head = stringToListNode("[-1,5,3,4,0]");

  cout << listNodeToString(Solution().insertionSortList(head)) << endl;
  return 0;
}