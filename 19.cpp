#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *flag = head;
    ListNode *iterator = head;
    int count = 0;
    while (iterator != NULL)
    {
      if (count < n + 1)
      {
      }
      else
      {
        flag = flag->next;
      }
      count++;
      iterator = iterator->next;
    }
    if (count == n) {
      head = head->next;
    }
    else
    {
      flag->next = flag->next->next;
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

  // cout << s->fourSum(x) << endl;
  return 0;
}
