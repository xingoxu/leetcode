#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Node
{
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;

  Node() {}

  Node(int _val, Node *_prev, Node *_next, Node *_child)
  {
    val = _val;
    prev = _prev;
    next = _next;
    child = _child;
  }
};

class Solution
{
  Node *_flatten(Node *head)
  {
    Node *ret = head;
    while (head)
    {
      ret = head;
      if (head->child)
      {
        auto end = _flatten(head->child);
        head->child->prev = head;
        end->next = head->next;
        if(head->next)
          head->next->prev = end;
        head->next = head->child;
        head->child = NULL;

        ret = end;

        head = end->next;
      }
      else
        head = head->next;
    }
    return ret;
  }

public:
  Node *flatten(Node *head)
  {
    _flatten(head);
    return head;
  }
};

int main()
{
  return 0;
}