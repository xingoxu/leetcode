#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
  stack<int> _stack;

public:
  /** Initialize your data structure here. */
  MyQueue()
  {
  }

  /** Push element x to the back of queue. */
  void push(int x)
  {
    stack<int> t;
    while(!_stack.empty()) {
      t.push(_stack.top());
      _stack.pop();
    }
    _stack.push(x);
    while(!t.empty()) {
      _stack.push(t.top());
      t.pop();
    }
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop()
  {
    int el = _stack.top();
    _stack.pop();
    return el;
  }

  /** Get the front element. */
  int peek()
  {
    return _stack.top();
  }

  /** Returns whether the queue is empty. */
  bool empty()
  {
    return _stack.empty();
  }
};

int main()
{
  MyQueue *obj = new MyQueue();
  obj->push(1);
  obj->push(2);
  cout << obj->peek() << endl;  // returns 1
  cout << obj->pop() << endl;   // returns 1
  cout << obj->empty() << endl; // returns false
  return 0;
}