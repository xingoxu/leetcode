
#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    stringstream ss;

    while (!q.empty())
    {
      auto current = q.front();
      q.pop();
      if (current != NULL)
      {
        ss << current->val << ',';
        q.push(current->left);
        q.push(current->right);
      }
      else
      {
        ss << "null,";
      }
    }
    return ss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data)
  {
    stringstream input;
    queue<string> q;
    for (int i = 0; i < data.size(); ++i)
    {
      if (data[i] != ',')
        input << data[i];
      else
      {
        q.push(input.str());
        input = stringstream();
      }
    }
    TreeNode *head = NULL;
    queue<TreeNode *> cursor;
    while (!q.empty())
    {
      auto current = q.front();
      q.pop();
      if (!head)
      {
        if (current != "null")
          head = new TreeNode(stoi(current));
        cursor.push(head);
      }
      else
      {
        auto currentParent = cursor.front();
        cursor.pop();
        if (current != "null")
        {
          currentParent->left = new TreeNode(stoi(current));
          cursor.push(currentParent->left);
        }

        current = q.front();
        q.pop();
        if (current != "null")
        {
          currentParent->right = new TreeNode(stoi(current));
          cursor.push(currentParent->right);
        }
      }
    }
    return head;
  }
};

int main()
{
  return 0;
}