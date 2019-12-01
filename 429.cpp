

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a Node.

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
      if(!root)
        return {};
      vector<vector<int>> ret;
      queue<Node *> level;
      level.push(root);
      while(!level.empty()) {
        queue<Node *> nextLevel;
        vector<int> levelRet;
        while (!level.empty())
        {
          auto node = level.front();
          level.pop();
          if(node) {
            levelRet.push_back(node->val);
            for (auto &child : node->children)
              nextLevel.push(child);
          }
        }
        ret.push_back(levelRet);
        level = nextLevel;
      }
      return ret;
    }
};

int main()
{
  return 0;
}