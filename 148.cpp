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
  ListNode *split(ListNode *head, int num)
  {
    int count = 1;
    while (head && count < num) {
      ++count;
      head = head->next;
    }
    ListNode *nextHead = NULL;
    if (head){
      nextHead = head->next;
      head->next = NULL;
    }
    return nextHead;
  }
  ListNode *merge(ListNode *a, ListNode *b, ListNode *header)
  {
    auto cursor = header;
    while (a && b)
    {
      if(a->val < b->val) {
        cursor->next = a;
        a = a->next;
      }
      else
      {
        cursor->next = b;
        b = b->next;
      }
      cursor = cursor->next;
      cursor->next = NULL;
    }
    if (a)
    {
      cursor->next = a;
    }
    else
    {
      cursor->next = b;
    }
    while (cursor && cursor->next)
    {
      cursor = cursor->next;
    }
    // return end
    return cursor;
  }

public:
  ListNode *sortList(ListNode *head)
  {
    ListNode *cursor = head;
    int length = 0;
    // get length
    while(cursor) {
      ++length;
      cursor = cursor->next;
    }
    auto tmpNode = ListNode(0);
    tmpNode.next = head;
    int i = 1;
    for (; i < length; i = i << 1)
    {
      cursor = tmpNode.next;
      ListNode *lastEnd = &tmpNode;
      while(cursor) {
        auto left = cursor;
        auto right = split(cursor, i);
        cursor = split(right, i);
        lastEnd = merge(left, right, lastEnd);
      }
    }
    return tmpNode.next;
  }
};

int main()
{
  ListNode *head = stringToListNode("[4,2,1,3]");

  cout << listNodeToString(Solution().sortList(head)) << endl;
  return 0;
}