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
  int getRightest(TreeNode *x) {
    while(x->right) {
      x = x->right;
    }
    return x->val;
  }
  int getLeftest(TreeNode *x) {
    while(x->left) {
      x = x->left;
    }
    return x->val;
  }

public:
  int getMinimumDifference(TreeNode *root)
  {
    int diff = INT_MAX;
    if (root->left)
    {
      diff = min(abs(root->val - getRightest(root->left)), getMinimumDifference(root->left));
    }

    if (root->right)
    {
      diff = min(diff, abs(root->val - getLeftest(root->right)));
      diff = min(diff, getMinimumDifference(root->right));
    }
    return diff;
  }
};

int main()
{

  cout << Solution().getMinimumDifference(stringToTreeNode("[1,null,4,2]")) << endl;

  return 0;
}
