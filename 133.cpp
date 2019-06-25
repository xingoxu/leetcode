#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;

  Node() {}

  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (!node)
      return NULL;
    queue<Node *> queue;
    queue.push(node);
    unordered_map<int, Node *> oldToNew;
    unordered_map<int, bool> visited;

    while (!queue.empty())
    {
      Node *current = queue.front();
      queue.pop();
      if (visited[current->val] == false)
      {
        visited[current->val] = true;

        Node *newNode = new Node(current->val, current->neighbors);
        oldToNew[current->val] = newNode;
        for (auto x : current->neighbors)
        {
          if (visited[x->val] == false)
          {
            queue.push(x);
          }
        }
      }
    }

    Node *newHead = oldToNew[node->val];
    visited.clear();
    queue.push(newHead);
    while (!queue.empty())
    {
      Node *current = queue.front();
      queue.pop();
      if (visited[current->val] == false)
      {
        visited[current->val] = true;
        auto &currentNeighbors = current->neighbors;
        vector<Node *> newNeighbors(currentNeighbors.size());

        for (int i = 0; i < newNeighbors.size(); i++)
        {
          Node *originNeighbor = currentNeighbors[i];
          newNeighbors[i] = oldToNew[originNeighbor->val];

          if (visited[originNeighbor->val] == false)
            queue.push(newNeighbors[i]);
        }
        current->neighbors = newNeighbors;
      }
    }

    return newHead;
  }
};

int main()
{
  Node *one = new Node(1, {});
  Node *two = new Node(2, {});
  Node *three = new Node(3, {});
  Node *four = new Node(4, {});
  one->neighbors = {two, four};
  two->neighbors = {one, three};
  three->neighbors = {two, four};
  four->neighbors =  {one, three};
  Solution().cloneGraph(one);
  return 0;
}
