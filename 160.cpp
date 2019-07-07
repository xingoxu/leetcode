#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    if(headA == NULL || headB == NULL)
      return NULL;
    // calc listA nodes
    int countA = 0;
    auto cursorA = headA;
    while (cursorA->next)
    {
      ++countA;
      cursorA = cursorA->next;
    }
    ++countA;

    // calc listB nodes and reverse listB
    int countB = 0;
    ListNode *beforeB = NULL;
    while (headB)
    {
      ++countB;
      auto node = headB;
      headB = headB->next;
      node->next = beforeB;
      beforeB = node;
    }

    if (cursorA != beforeB)
    {
      headB = beforeB;
      beforeB = NULL;
      while (headB)
      {
        auto node = headB;
        headB = headB->next;
        node->next = beforeB;
        beforeB = node;
      }
      return NULL;
    }

    // count common part
    cursorA = headA;
    int countAB = 0;
    while (cursorA)
    {
      ++countAB;
      cursorA = cursorA->next;
    }
    int finalcount = (countA + countB - countAB + 1) / 2;
    countB = 0;
    ListNode *ret = NULL;
    headB = beforeB;
    beforeB = NULL;
    while (headB)
    {
      if (++countB == finalcount)
      {
        ret = headB;
      }
      auto node = headB;
      headB = headB->next;
      node->next = beforeB;
      beforeB = node;
    }
    return ret;
  }
};

int stringToInteger(string input)
{
  return stoi(input);
}

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

int main()
{

  ListNode *listA = stringToListNode("[4,1,8,4,5]");
  ListNode *listB = stringToListNode("[5,0,1,8,4,5]");
  int skipA = 2;
  int skipB = 3;

  auto headA = listA;
  auto headB = listB;
  for (int i = 0; i < skipA;i++) {
    headA = headA->next;
  }
  for (int i = 0; i < skipB - 1; i++)
  {
    headB = headB->next;
  }
  headB->next = headA;

  string out = listNodeToString(Solution().getIntersectionNode(listA, listB));
  cout << out << endl;
  return 0;
}