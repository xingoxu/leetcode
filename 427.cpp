#include <iostream>
#include <vector>
using namespace std;

// Definition for a QuadTree node.
class Node
{
public:
  bool val;
  bool isLeaf;
  Node *topLeft;
  Node *topRight;
  Node *bottomLeft;
  Node *bottomRight;

  Node() {}

  Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
  {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};

class Solution
{
  Node *construct(vector<vector<int>> &grid, int x, int y, int length)
  {
    if (length == 1)
      return new Node(grid[x][y], true, NULL, NULL, NULL, NULL);

    auto LT = construct(grid, x, y, length / 2);
    auto RT = construct(grid, x, y + (length / 2), length / 2);
    auto LD = construct(grid, x + (length / 2), y, length / 2);
    auto RD = construct(grid, x + (length / 2), y + (length / 2), length / 2);
    if (LT->isLeaf && RT->isLeaf && LD->isLeaf && RD->isLeaf)
    {
      if (LT->val && RT->val && LD->val && RD->val)
        return new Node(true, true, NULL, NULL, NULL, NULL);
      else if (!LT->val && !RT->val && !LD->val && !RD->val)
        return new Node(false, true, NULL, NULL, NULL, NULL);
    }
    return new Node(true, false, LT, RT, LD, RD);
  }

public:
  Node *construct(vector<vector<int>> &grid)
  {
    return construct(grid, 0, 0, grid.size());
  }
};