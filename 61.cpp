#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      ListNode *end = NULL;
      ListNode *iterator = head;
      if (head == NULL)
        return head;
      int count = 1;
      while (iterator->next != NULL)
      {
        iterator = iterator->next;
        end = iterator;
        count++;
      }
      int lastK = k % count;
      if (lastK == 0)
      {
        return head;
      }
      k = count - lastK;
      count = 0;
      iterator = head;
      while (count < k - 1)
      {
        iterator = iterator->next;
        count++;
      }
      ListNode *newHead = iterator->next;
      iterator->next = NULL;
      end->next = head;

      return newHead;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  // cout << s->getPermutation(9, 54494) << endl;
  return 0;
}
