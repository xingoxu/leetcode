// Runtime: 36 ms, faster than 49.04% of C++ online submissions for Count Complete Tree Nodes.
// Memory Usage: 28.9 MB, less than 27.78% of C++ online submissions for Count Complete Tree Nodes.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
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

vector<int> stringToIntegerVector(string input)
{
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim))
  {
    output.push_back(stoi(item));
  }
  return output;
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
  int countNodes(TreeNode *root)
  {
    if(!root)
      return 0;
    auto cursor = root;
    int left = 0, right = 0;
    while (cursor->left)
    {
      ++left;
      cursor = cursor->left;
    }
    cursor = root;
    while (cursor->right)
    {
      ++right;
      cursor = cursor->right;
    }
    if (left == right)
      return (pow(2, left + 1) - 1);

    int maxLevel = left;
    // find left & right using bisection
    left = 1, right = pow(2, maxLevel);
    while (left < right - 1)
    {
      cursor = root;
      int middle = (right - left) / 2 + left;
      stack<int> directions;
      while (middle != 1)
      {
        directions.push(middle);
        middle = middle % 2 == 1 ? (middle / 2 + 1) : middle / 2;
      }
      while (directions.size() < maxLevel)
      {
        directions.push(1);
      }
      int now = 1, next = right;
      while (!directions.empty())
      {
        next = directions.top();
        directions.pop();
        if (next == now * 2)
        {
          cursor = cursor->right;
        }
        else
        {
          cursor = cursor->left;
        }
        now = next;
      }
      if (cursor == NULL)
      {
        right = next;
      } else {
        left = next;
      }
    }
    return left + (pow(2, maxLevel) - 1);
  }
};

int main()
{

  cout << Solution().countNodes(stringToTreeNode("[1,2,3,4,5,6,7,8,9,10,11]")) << endl;
  return 0;
}