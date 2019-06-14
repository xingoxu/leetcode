// Runtime: 4 ms, faster than 87.38% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 8.5 MB, less than 85.18% of C++ online submissions for Reverse Linked List II.

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
class Solution
{
public:
  ListNode *reverseBetween(ListNode *head, int m, int n)
  {
    ListNode *newHead = head, *beforeM = NULL, *afterN = NULL,
             *cursor = head, *pointerM = NULL, *pointerN = NULL,
             *beforeCursor = NULL;
    int count = 1;
    while (cursor)
    {
      if (count == m - 1)
      {
        beforeM = cursor;
      }
      if (count == m)
      {
        pointerM = cursor;
      }
      if (count == n)
      {
        pointerN = cursor;
        afterN = pointerN->next;
      }

      ListNode *backupNext = cursor->next;
      if (count > m && count <= n)
      {
        cursor->next = beforeCursor;
      }
      if(count == n)
        break;
      count++;
      beforeCursor = cursor;
      cursor = backupNext;
    }
    if (beforeM)
    {
      beforeM->next = pointerN;
    }
    else
    {
      newHead = pointerN;
    }
    pointerM->next = afterN;
    return newHead;
  }
};

int main()
{
  string line = "[1,2,3,4,5]";
  ListNode *head = stringToListNode(line);
  int m = 1;
  int n = 5;

  ListNode *ret = Solution().reverseBetween(head, m, n);

  cout << listNodeToString(ret) << endl;
  return 0;
}