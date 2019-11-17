// TODO to see the faster solution

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
  int result = 0;
  void getSet(list<int> &x, list<int> &next, int rootVal, int &sum) {
    for (auto &a : x)
    {
      if (a + rootVal == sum)
        ++result;
      next.push_back(a + rootVal);
    }
  }
  list<int> dfs(TreeNode *root, int &sum)
  {
    list<int> lChild, rChild;
    if (root->left)
      lChild = dfs(root->left, sum);
    if(root->right)
      rChild = dfs(root->right, sum);
    list<int> next;
    getSet(lChild, next,root->val, sum);
    getSet(rChild, next,root->val, sum);
    if (root->val == sum)
      ++result;
    next.push_back(root->val);

    return next;
  }

public:
  int pathSum(TreeNode *root, int sum)
  {
    result = 0;
    if(root)
      dfs(root, sum);
    return result;
  }
};

int main()
{
  cout << Solution().pathSum(stringToTreeNode("[10,5,-3,3,2,null,11,3,-2,null,1]"), 8) << endl;
  return 0;
}