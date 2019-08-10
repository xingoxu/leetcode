// Runtime: 4 ms, faster than 56.00% of C++ online submissions for Implement Stack using Queues.
// Memory Usage: 8.9 MB, less than 60.00% of C++ online submissions for Implement Stack using Queues.
// TODO ?

#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
  queue<int> q;

public:
  /** Initialize your data structure here. */
  MyStack()
  {
  }

  /** Push element x onto stack. */
  void push(int x)
  {
    queue<int> nQ;
    nQ.push(x);
    while (!q.empty())
    {
      nQ.push(q.front());
      q.pop();
    }
    q = nQ;
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop()
  {
    int ret = q.front();
    q.pop();
    return ret;
  }

  /** Get the top element. */
  int top()
  {
    return q.front();
  }

  /** Returns whether the stack is empty. */
  bool empty()
  {
    return q.empty();
  }
};

int main()
{
  MyStack *obj = new MyStack();
  obj->push(1);
  // cout << obj->top() << endl;
  cout << obj->pop() << endl;
  cout << obj->empty() << endl;
  return 0;
}