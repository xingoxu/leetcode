#include <iostream>
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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode *head = NULL;
    ListNode *cursor = NULL;
    while (l1 && l2)
    {
      ListNode *nextNode;
      if (l1->val < l2->val)
      {
        nextNode = l1;
        l1 = l1->next;
      }
      else
      {
        nextNode = l2;
        l2 = l2->next;
      }
      if (cursor)
        cursor->next = nextNode;
      else
      {
        cursor = nextNode;
        head = nextNode;
      }
      cursor = nextNode;
      nextNode->next = NULL;
    }
    if (l1)
    {
      if (cursor)
        cursor->next = l1;
      else
        head = l1;
    }
    if (l2)
    {
      if (cursor)
        cursor->next = l2;
      else
        head = l2;
    }
    return head;
  }
};
int main()
{
  Solution *s = new Solution();

  // vector<int> x{-1,0,1,2,-1,-4}; // -4 -1 -1 0 1 2

  // vector<vector<int>> result = s->removeNthFromEnd(x, -1);

  // for (int i = 0; i < result.size(); i++)
  // {
  //   cout << '[' << result[i][0];
  //   cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  // }

  // cout << s->isValid("({[]})") << endl;
  return 0;
}
