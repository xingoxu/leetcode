// TODO: find a faster solution
// Runtime: 32 ms, faster than 62.89% of C++ online submissions for Serialize and Deserialize BST.
// Memory Usage: 22.8 MB, less than 96.15% of C++ online submissions for Serialize and Deserialize BST.

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

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    queue<TreeNode *> level;
    level.push(root);
    string result = "";
    while (!level.empty())
    {
      auto node = level.front();
      if (node)
      {
        result += to_string(node->val) + ",";
        level.push(node->left);
        level.push(node->right);
      }
      else
        result += "null,";

      level.pop();
    }
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    string buff;
    TreeNode *header = NULL;
    queue<TreeNode *> level;
    int count = 0;
    for (auto &x : data)
    {
      if (x == ',')
      {
        TreeNode *newNode = NULL;
        TreeNode *fatherNode = level.empty() ? NULL : level.front();
        if (buff == "null")
        {
        }
        else
        {
          int val = stoi(buff);
          newNode = new TreeNode(val);
          level.push(newNode);
        }
        if(fatherNode) {
          if(count ==1) {
            fatherNode->right = newNode;
            count = 0;
            level.pop();
          }
          else
          {
            fatherNode->left = newNode;
            ++count;
          }
        }
        if (header == NULL)
          header = newNode;
        buff = "";
      }
      else
      {
        buff += x;
      }
    }
    return header;
  }
};

int main()
{
  cout << treeNodeToString(Codec().deserialize(Codec().serialize(stringToTreeNode("[1,-2,-3,1,3,-2,null,-1]")))) << endl;
  return 0;
}