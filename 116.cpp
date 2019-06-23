#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
  {
    val = _val;
    left = _left;
    right = _right;
    next = _next;
  }
};
class Solution
{
public:
  Node *connect(Node *root)
  {
    if (!root)
      return root;
    Node *cursor = root, *connectCursor = NULL, *nextLevelLeft = NULL;
    while (cursor)
    {
      if (cursor->left)
      {
        if (!nextLevelLeft)
          nextLevelLeft = cursor->left;
        if (connectCursor)
          connectCursor->next = cursor->left;
        connectCursor = cursor->left;
      }
      if (cursor->right)
      {
        if (!nextLevelLeft)
          nextLevelLeft = cursor->right;
        if (connectCursor)
          connectCursor->next = cursor->right;
        connectCursor = cursor->right;
      }
      if (cursor->next)
      {
        cursor = cursor->next;
      }
      else
      {
        cursor = nextLevelLeft;
        connectCursor = NULL;
        nextLevelLeft = NULL;
      }
    }
    return root;
  }
};

int main()
{

  return 0;
}