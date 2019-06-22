// Runtime: 24 ms, faster than 97.24% of C++ online submissions for Convert Sorted List to Binary Search Tree.
// Memory Usage: 22.9 MB, less than 99.40% of C++ online submissions for Convert Sorted List to Binary Search Tree.

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

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

ListNode *stringToListNode(string input)
{
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list)
  {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
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
  TreeNode *sortedListToBST(ListNode *head)
  {
    int count = 0, left = 0;
    TreeNode *root = NULL, *rightCursor = NULL;
    while (head)
    {
      TreeNode *newNode = new TreeNode(head->val);
      if (rightCursor)
      {
        rightCursor->right = newNode;
      }
      else
      {
        root = newNode;
      }
      rightCursor = newNode;

      ++count;

      if (left < count / 2)
      {
        TreeNode *rootNext = root->right;
        rootNext->left = root;
        root->right = NULL;
        root = rootNext;
        ++left;
      }

      head = head->next;
    }
    if (root && root->left)
      root->left = sortLeftTree(root->left);
    if (root && root->right)
      root->right = sortRightTree(root->right);

    return root;
  }
  TreeNode *sortLeftTree(TreeNode *root)
  {
    int count = 0, right = 0;
    TreeNode *newRoot = root;
    while (root)
    {
      count++;
      if (right < count / 2)
      {
        TreeNode *rootNext = newRoot->left;
        rootNext->right = newRoot;
        newRoot->left = NULL;
        newRoot = rootNext;
        ++right;
      }
      root = root->left;
    }
    if (newRoot && newRoot->left)
      newRoot->left = sortLeftTree(newRoot->left);
    if (newRoot && newRoot->right)
      newRoot->right = sortRightTree(newRoot->right);

    return newRoot;
  }
  TreeNode *sortRightTree(TreeNode *root)
  {
    int count = 0, left = 0;
    TreeNode *newRoot = root;
    while (root)
    {
      count++;
      if (left < count / 2)
      {
        TreeNode *rootNext = newRoot->right;
        rootNext->left = newRoot;
        newRoot->right = NULL;
        newRoot = rootNext;
        ++left;
      }
      root = root->right;
    }
    if (newRoot && newRoot->left)
      newRoot->left = sortLeftTree(newRoot->left);
    if (newRoot && newRoot->right)
      newRoot->right = sortRightTree(newRoot->right);

    return newRoot;
  }
};

int main()
{
  TreeNode *ret = Solution().sortedListToBST(stringToListNode("[0,1,2,3,4,5]"));

  cout << treeNodeToString(ret) << endl;
  return 0;
}