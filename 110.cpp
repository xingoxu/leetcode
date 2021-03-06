// Runtime: 12 ms, faster than 92.17% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 18 MB, less than 6.38% of C++ online submissions for Balanced Binary Tree.

// non_recursive answer
// Runtime: 12 ms, faster than 90.62% of C++ online submissions for Balanced Binary Tree.
// Memory Usage: 16.6 MB, less than 92.51% of C++ online submissions for Balanced Binary Tree.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void trimLeftTrailingSpaces(string &input)
{
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
              }));
}

void trimRightTrailingSpaces(string &input)
{
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
              })
                  .base(),
              input.end());
}

TreeNode *stringToTreeNode(string input)
{
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  if (!input.size())
  {
    return nullptr;
  }

  string item;
  stringstream ss;
  ss.str(input);

  getline(ss, item, ',');
  TreeNode *root = new TreeNode(stoi(item));
  queue<TreeNode *> nodeQueue;
  nodeQueue.push(root);

  while (true)
  {
    TreeNode *node = nodeQueue.front();
    nodeQueue.pop();

    if (!getline(ss, item, ','))
    {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null")
    {
      int leftNumber = stoi(item);
      node->left = new TreeNode(leftNumber);
      nodeQueue.push(node->left);
    }

    if (!getline(ss, item, ','))
    {
      break;
    }

    trimLeftTrailingSpaces(item);
    if (item != "null")
    {
      int rightNumber = stoi(item);
      node->right = new TreeNode(rightNumber);
      nodeQueue.push(node->right);
    }
  }
  return root;
}

string boolToString(bool input)
{
  return input ? "True" : "False";
}

class Solution
{
public:
  bool isBalanced(TreeNode *root) {
    // return isBalanced_recursive(root);
    return isBalanced_nonrecursive(root);
  }
  bool isBalanced_nonrecursive(TreeNode *root)
  {
    stack<TreeNode *> parentStack;
    bool enterRemoveStack = false;
    while (root || !parentStack.empty())
    {
      if (enterRemoveStack)
      {
        while (!parentStack.empty() && root == parentStack.top()->right)
        {
          root = parentStack.top();
          // process root here
          int maxVal = 1, left = 0, right = 0;
          if (root->left){
            maxVal = max(maxVal, root->left->val + 1);
            left = root->left->val;
          }
          if (root->right){
            maxVal = max(maxVal, root->right->val + 1);
            right = root->right->val;
          }
          if (abs(left - right) >= 2)
            return false;
          root->val = maxVal;
          parentStack.pop();
        }
        if (parentStack.empty())
          break;
        root = parentStack.top()->right;
        enterRemoveStack = false;
        continue;
      }
      if (root)
      {
        parentStack.push(root);
        root = root->left;
      }
      else
      {
        TreeNode *parent = parentStack.top();
        if (root == parent->right)
        {
          enterRemoveStack = true;
          continue;
        }
        root = parent->right;
      }
    }

    return true;
  }
  bool isBalanced_recursive(TreeNode *root)
  {
    if(!root)
      return true;
    if(abs(maxDepth(root->left) - maxDepth(root->right)) >= 2)
      return false;
    return isBalanced_recursive(root->left) &&
           isBalanced_recursive(root->right);
  }
  int maxDepth(TreeNode *root) {
    if(!root)
      return 0;
    if (!(root->left || root->right))
      return 1;
    int maxDepthRet = 1;
    if (root->left)
    {
      maxDepthRet = max(maxDepthRet, 1 + maxDepth(root->left));
    }
    if(root->right) {
      maxDepthRet = max(maxDepthRet, 1 + maxDepth(root->right));
    }
    return maxDepthRet;
  }
};

int main()
{
  bool ret = Solution().isBalanced(stringToTreeNode("[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]"));

  cout << boolToString(ret) << endl;
  return 0;
}