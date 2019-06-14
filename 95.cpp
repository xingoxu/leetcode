// Runtime: 16 ms, faster than 95.27% of C++ online submissions for Unique Binary Search Trees II.
// Memory Usage: 21.1 MB, less than 5.03% of C++ online submissions for Unique Binary Search Trees II.

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<vector<TreeNode *> *> cache;

class Solution
{
public:
  vector<TreeNode *> generateTrees(int n)
  {
    return _numTrees(n, 1, n);
  }
  vector<TreeNode *> _numTrees(int n, int start, int end)
  {
    if (n == 1)
    {
      return {new TreeNode(start)};
    }

    vector<TreeNode *> result;
    for (int i = start; i <= end; i++)
    {
      if (i == start || i == end)
      {
        if (i == start)
        {
          const vector<TreeNode *> &rightResult = _numTrees(end - i, i + 1, end);
          for (int j = rightResult.size() - 1; j >= 0; j--)
          {
            TreeNode *nodeNow = new TreeNode(i);
            TreeNode *rightRoot = rightResult[j];
            nodeNow->right = rightRoot;
            nodeNow->left = NULL;
            result.push_back(nodeNow);
          }
        }
        else
        {
          const vector<TreeNode *> &leftResult = _numTrees(i - start, start, i - 1);
          for (int j = leftResult.size() - 1; j >= 0; j--)
          {
            TreeNode *nodeNow = new TreeNode(i);
            TreeNode *leftRoot = leftResult[j];
            nodeNow->left = leftRoot;
            nodeNow->right = NULL;
            result.push_back(nodeNow);
          }
        }
      }
      else
      {
        const vector<TreeNode *> &leftResult = _numTrees(i - start, start, i - 1);
        const vector<TreeNode *> &rightResult = _numTrees(end - i, i + 1, end);
        for (int j = leftResult.size() - 1; j >= 0; j--)
        {
          for (int k = rightResult.size() - 1; k >= 0; k--)
          {
            TreeNode *nodeNow = new TreeNode(i);
            TreeNode *leftRoot = leftResult[j];
            TreeNode *rightRoot = rightResult[k];
            nodeNow->left = leftRoot;
            nodeNow->right = rightRoot;
            result.push_back(nodeNow);
          }
        }
      }
    }
    return result;
  }
};

int main()
{
  vector<vector<char>> x = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  Solution().generateTrees(3);

  return 0;
}