#include <iostream>
#include <vector>
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
  ListNode *u;
  Solution(ListNode *head)
  {
    u = head;
  }

  int getRandom()
  {
    int res, len = 1;
    ListNode *v = u;
    while (v)
    {
      if (rand() % len == 0)
      {
        res = v->val;
      }
      len++;
      v = v->next;
    }
    return res;
  }
};
