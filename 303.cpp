// Runtime: 36 ms, faster than 43.58% of C++ online submissions for Range Sum Query - Immutable.
// Memory Usage: 18.9 MB, less than 6.90% of C++ online submissions for Range Sum Query - Immutable.
// TODO: can be changed to Binary Indexed Tree

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct segment
{
  segment *left;
  segment *right;
  int start;
  int end;
  int value;
  segment(int x) : value(x), left(NULL), right(NULL){};
};

class NumArray
{
  segment *head;
  int sumRange(int i, int j, segment *root)
  {
    if (i == root->start && j == root->end)
      return root->value;
    if (root->left && i > root->left->end)
    {
      return sumRange(i, j, root->right);
    }
    if (root->right && j < root->right->start)
    {
      return sumRange(i, j, root->left);
    }
    return sumRange(i, root->left->end, root->left) + sumRange(root->right->start, j, root->right);
  }

public:
  NumArray(vector<int> &nums)
  {
    queue<segment *> thisLevel;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      auto seg = new segment(nums[i]);
      seg->start = i;
      seg->end = i;
      thisLevel.push(seg);
    }

    while (thisLevel.size() > 1)
    {
      queue<segment *> nextLevel;
      while (!thisLevel.empty())
      {
        auto segRight = thisLevel.front();
        thisLevel.pop();
        auto segLeft = thisLevel.front();
        thisLevel.pop();

        auto seg = new segment(segRight->value + segLeft->value);
        seg->left = segLeft;
        seg->right = segRight;
        seg->start = segLeft->start;
        seg->end = segRight->end;
        nextLevel.push(seg);
        if (thisLevel.size() == 1)
        {
          nextLevel.push(thisLevel.front());
          break;
        }
      }
      thisLevel = nextLevel;
    }
    head = thisLevel.front();
  }

  int sumRange(int i, int j)
  {
    return sumRange(i, j, head);
  }
};

int main()
{
  vector<int> nums{-2, 0, 3, -5, 2, -1};
  NumArray *obj = new NumArray(nums);
  cout << "test" << endl;
  cout << obj->sumRange(0, 2) << endl;
  cout << obj->sumRange(2, 5) << endl;
  cout << obj->sumRange(0, 5) << endl;
  return 0;
}