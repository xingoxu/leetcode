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
  int smallestK(vector<ListNode*> &lists) {
    int smallestValue = INT16_MAX;
    int smallestIterator = -1;
    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i] == NULL)
        continue;
      if (lists[i]->val < smallestValue){
        smallestValue = lists[i]->val;
        smallestIterator = i;
      }
    }
    return smallestIterator;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *head = NULL;
    ListNode *cursor = NULL;
    if (lists.size() == 0)
      return head;
    // bool isAllNotNull = true;
    while (true)
    {
      int k = smallestK(lists);
      if (k<0)
        break;

      ListNode *nextNode = lists[k];
      lists[k] = lists[k]->next;
      if (cursor)
        cursor->next = nextNode;
      else
      {
        cursor = nextNode;
        head = nextNode;
      }

      cursor = nextNode;
      nextNode->next = NULL;

      // isAllNotNull = true;
    }
    if (head == NULL)
    {
      head = lists[0];
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
