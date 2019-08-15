// Runtime: 1036 ms, faster than 5.07% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 17.3 MB, less than 36.36% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
// TODO

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

string treeNodeToString(TreeNode *root)
{
  if (root == nullptr)
  {
    return "[]";
  }

  string output = "";
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *node = q.front();
    q.pop();

    if (node == nullptr)
    {
      output += "null, ";
      continue;
    }

    output += to_string(node->val) + ", ";
    q.push(node->left);
    q.push(node->right);
  }
  return "[" + output.substr(0, output.length() - 2) + "]";
}

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == p)
      return p;
    if (root == q)
      return q;

    if (root->left && findNode(root->left, p) && findNode(root->left, q))
    {
      return lowestCommonAncestor(root->left, p, q);
    }
    else if (root->right && findNode(root->right, p) && findNode(root->right, q))
    {
      return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
      return root;
    }
  }
  TreeNode *findNode(TreeNode *root, TreeNode *target)
  {
    TreeNode *ret;
    if (root == target || root->left == target || root->right == target)
      return root;
    if(root->left && (ret = findNode(root->left,target)))
      return ret;
    if(root->right && (ret = findNode(root->right,target)))
      return ret;
    return NULL;
  }
};

int main()
{
  auto root = stringToTreeNode("[3,5,1,6,2,0,8,null,null,7,4]");
  cout << Solution().lowestCommonAncestor(root, root->left, root->left->right->right)->val << endl;
  return 0;
}
