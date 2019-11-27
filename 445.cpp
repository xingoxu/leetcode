// TODO: find a faster solution
// Runtime: 36 ms, faster than 5.04% of C++ online submissions for Add Two Numbers II.
// Memory Usage: 13 MB, less than 51.85% of C++ online submissions for Add Two Numbers II.

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    stack<int> list1;
    stack<int> list2;
    ListNode *ret = NULL;
    while (l1)
    {
      list1.push(l1->val);
      l1 = l1->next;
    }
    while(l2) {
      list2.push(l2->val);
      l2 = l2->next;
    }
    int overflow = 0;
    while (!list1.empty() && !list2.empty())
    {
      auto top1 = list1.top();
      auto top2 = list2.top();
      list1.pop(), list2.pop();
      ListNode *now;
      if (top1 + top2 + overflow >= 10) {
        now = new ListNode(top1 + top2 + overflow - 10);
        overflow = 1;
      } else {
        now = new ListNode(top1 + top2 + overflow);
        overflow = 0;
      }
      now->next = ret;
      ret = now;
    }
    while (!list1.empty()) {
      auto top1 = list1.top();
      list1.pop();
      ListNode *now;
      if (top1 + overflow >= 10) {
        now = new ListNode(top1 + overflow - 10);
        overflow = 1;
      } else {
        now = new ListNode(top1 + overflow);
        overflow = 0;
      }
      now->next = ret;
      ret = now;
    }
    while (!list2.empty()) {
      auto top2 = list2.top();
      list2.pop();
      ListNode *now;
      if (top2 + overflow >= 10) {
        now = new ListNode(top2 + overflow - 10);
        overflow = 1;
      } else {
        now = new ListNode(top2 + overflow);
        overflow = 0;
      }
      now->next = ret;
      ret = now;
    }
    if(overflow == 1) {
      auto now = new ListNode(1);
      now->next = ret;
      return now;
    }
    return ret;
  }
};

int main()
{
  ListNode *list1 = stringToListNode("[7,2,4,3]");
  ListNode *list2 = stringToListNode("[5,6,4]");

  auto ret = Solution().addTwoNumbers(list1, list2);

  string out = listNodeToString(ret);
  cout << out << endl;

  return 0;
}
