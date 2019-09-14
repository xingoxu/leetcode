// Runtime: 12 ms, faster than 97.88% of C++ online submissions for Odd Even Linked List.
// Memory Usage: 9.6 MB, less than 97.14% of C++ online submissions for Odd Even Linked List.

#include <iostream>
#include <sstream>
#include <queue>
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
  ListNode *oddEvenList(ListNode *head)
  {
    ListNode *oddHead, *evenHead, *oddCursor, *evenCursor;
    oddHead = evenHead = oddCursor = evenCursor = NULL;
    int counter = 1;
    while (head)
    {
      if ((counter++) % 2 == 1)
      {
        if (oddHead)
          oddCursor->next = head;
        else
          oddHead = head;
        oddCursor = head;
      }
      else
      {
        if (evenHead)
          evenCursor->next = head;
        else
          evenHead = head;
        evenCursor = head;
      }
      head = head->next;
    }
    if(oddCursor) {
      oddCursor->next = evenHead;
    }
    if(evenCursor) {
      evenCursor->next = NULL;
    }
    return oddHead;
  }
};

int main()
{
  cout << listNodeToString(Solution().oddEvenList(stringToListNode("[1,2,3,4,5]"))) << endl;
  return 0;
}
