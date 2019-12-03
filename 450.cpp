// Runtime: 28 ms, faster than 93.93% of C++ online submissions for Delete Node in a BST.
// Memory Usage: 13 MB, less than 32.43% of C++ online submissions for Delete Node in a BST.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_set>

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
  TreeNode *find(TreeNode *root, char side)
  {
    if (side == 'l')
    {
      while (root->left)
        root = root->left;
    }
    else
    {
      while (root->right)
        root = root->right;
    }
    return root;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key)
  {
    if (root == NULL)
      return NULL;
    if (key < root->val)
      root->left = deleteNode(root->left, key);
    else if (key > root->val)
      root->right = deleteNode(root->right, key);
    else
    {
      TreeNode *nodeDeleted = root;
      if (root->left)
      {
        auto right = find(root->left, 'r');
        right->right = root->right;
        root = root->left;
      }
      else if (root->right)
      {
        auto left = find(root->right, 'l');
        left->left = root->left;
        root = root->right;
      }
      else
      {
        root = NULL;
      }
      delete nodeDeleted;
    }

    return root;
  }
};

int main()
{
  cout << treeNodeToString(Solution().deleteNode(stringToTreeNode("[5,3,6,2,4,null,7]"), 3)) << endl;
  return 0;
}