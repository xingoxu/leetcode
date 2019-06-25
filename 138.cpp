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
    while (cursor)
    {
      Node *current = cursor;
      cursor = cursor->next;

      Node *newNode = new Node(current->val, current->next, current->random);
      current->next = newNode;
    }

    if (head)
    {
      newHead = head->next;
    }
    cursor = head;
    while (cursor)
    {
      Node *newNode = cursor->next;
      if (newNode->random)
        newNode->random = newNode->random->next;

      cursor = newNode->next;
    }
    cursor = head;
    while (cursor)
    {
      Node *node = cursor;
      cursor = cursor->next;
      if(cursor)
        node->next = cursor->next;
    }

    Node *newCursor = newHead;
    cursor = head;
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
