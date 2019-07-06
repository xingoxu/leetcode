#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MinStack
{
public:
  /** initialize your data structure here. */
  stack<ListNode *> st;
  MinStack()
  {
  }

  void push(int x)
  {
    auto node = new ListNode(x);
    if (st.empty())
    {
      node->next = node;
    }
    else
    {
      auto topNode = st.top();
      node->next = topNode->next->val < x ? topNode->next : node;
    }
    st.push(node);
  }

  void pop()
  {
    auto node = st.top();
    st.pop();
    delete node;
  }

  int top()
  {
    return st.top()->val;
  }

  int getMin()
  {
    return st.top()->next->val;
  }
};

int main()
{
  MinStack *obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);
  cout << obj->getMin() << endl; // --> Returns -3
  obj->pop();
  cout << obj->top() << endl;    //  --> Returns 0
  cout << obj->getMin() << endl; // --> Returns -2.

  return 0;
}