// Runtime: 16 ms, faster than 88.75% of C++ online submissions for Path Sum III.
// Memory Usage: 17.7 MB, less than 19.35% of C++ online submissions for Path Sum III.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>

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
  int count = 0;
  unordered_map<int, int> prefix;
  void pathSum(TreeNode *root, int &pre, int &target)
  {
    if(!root)
      return;
    int now = root->val + pre;
    auto p = prefix.find(now - target);
    if (p != prefix.end())
    {
      count += p->second;
    }
    ++prefix[now];
    pathSum(root->left, now, target);
    pathSum(root->right, now, target);
    --prefix[now];
  }

public:
  int pathSum(TreeNode *root, int sum)
  {
    prefix[0] = 1;
    int pre = 0;
    pathSum(root, pre, sum);
    return count;
  }
};

int main()
{
  cout << Solution().pathSum(stringToTreeNode("[1,-2,-3,1,3,-2,null,-1]"), -1) << endl;
  return 0;
}