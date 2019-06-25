#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node() {}

  Node(int _val, Node *_next, Node *_random)
  {
    val = _val;
    next = _next;
    random = _random;
  }
};
class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    Node *cursor = head;
    Node *newHead = NULL;
    Node *newCursor = NULL;
    while (cursor)
    {
      // newNode's random -> originNode
      Node *newNode = new Node(cursor->val, NULL, cursor);
      if (newCursor)
      {
        newCursor->next = newNode;
      }
      else
      {
        newHead = newNode;
      }
      newCursor = newNode;

      Node *current = cursor;
      cursor = cursor->next;
      // set current next -> newNode
      current->next = newNode;
    }

    newCursor = newHead;
    while (newCursor)
    {
      Node *originNode = newCursor->random;
      Node *randomNodeOrigin = originNode->random;
      if (randomNodeOrigin)
        newCursor->random = randomNodeOrigin->next;
      else
        newCursor->random = NULL;

      if (newCursor->next)
        originNode->next = newCursor->next->random;
      else
        originNode->next = NULL;
      newCursor = newCursor->next;
    }
    cursor = head;
    newCursor = newHead;

    while (newCursor)
    {
      cout
          << cursor->val
          << ' '
          << (cursor == newCursor)
          << ' '
          << ((cursor->random) == (newCursor->random)) << endl;

      cursor = cursor->next;
      newCursor = newCursor->next;
    }
    return newHead;
  }
};

int main()
{
  Node *two = new Node(2, NULL, NULL);
  two->random = two;
  Node *head = new Node(1, two, two);
  Solution().copyRandomList(head);
  return 0;
}
