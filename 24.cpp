// the same code as 25
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
  ListNode *swapPairs(ListNode *head)
  {
    return this->reverseKGroup(head, 2);
  }
  ListNode *reverseKGroup(ListNode *head, int k)
  {
    if (head == NULL)
      return NULL;

    int count = 1;
    ListNode *newHead = head;
    ListNode *pointer = head;
    ListNode *pointerNext = head->next;
    ListNode *pointerChange = NULL;
    while (head)
    {
      if (count % k == 0)
      {
        for (int i = 0; i < k - 1; i++)
        {
          ListNode *temp = pointerNext->next;
          pointerNext->next = pointer;
          pointer = pointerNext;
          pointerNext = temp;
        }

        if (count == k)
        {
          newHead = pointer;
        }

        ListNode *findHead = pointer;
        ListNode *pointerOrig = pointer;

        pointer = pointerNext;
        if (pointerNext != NULL)
          pointerNext = pointerNext->next;

        for (int i = 0; i < k - 1; i++)
        {
          findHead = findHead->next;
        }

        if (pointerChange == NULL)
        {
          findHead->next = pointerChange;
        }
        else
        {
          pointerChange->next = pointerOrig;
        }
        pointerChange = findHead;

        head = pointer;
        count++;
        continue;
      }

      count++;
      head = head->next;
    }

    if (pointerChange)
      pointerChange->next = pointer;

    return newHead;
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
