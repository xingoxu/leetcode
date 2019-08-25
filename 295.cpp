// Runtime: 180 ms, faster than 23.36% of C++ online submissions for Find Median from Data Stream.
// Memory Usage: 55.4 MB, less than 8.70% of C++ online submissions for Find Median from Data Stream.
// TODO: There's a lots of Solution in this problem, try to realize them.

#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct AVLTreeNode
{
  int val;
  int height = 0;
  int size = 1;
  AVLTreeNode *left;
  AVLTreeNode *right;
  AVLTreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class AVLTree
{
private:
  void insert(int x, AVLTreeNode *&root)
  {
    if (x > root->val)
    {
      if (root->right)
        insert(x, root->right);
      else
        root->right = new AVLTreeNode(x);
    }
    else
    {
      if (root->left)
        insert(x, root->left);
      else
        root->left = new AVLTreeNode(x);
    }
    int leftHeight = root->left ? root->left->height : -1;
    int rightHeight = root->right ? root->right->height : -1;

    if (abs(leftHeight - rightHeight) >= 2)
    {
      balance(root);
    }
    else
    {
      root->height = max(leftHeight + 1, rightHeight + 1);
      root->size = 1 + (root->left ? root->left->size : 0) + (root->right ? root->right->size : 0);
    }
  }

  void balance(AVLTreeNode *&root)
  {
    int leftHeight = root->left ? root->left->height : -1;
    int rightHeight = root->right ? root->right->height : -1;
    if (leftHeight > rightHeight)
    {
      auto leftChild = root->left;
      leftHeight = leftChild->left ? leftChild->left->height : -1;
      rightHeight = leftChild->right ? leftChild->right->height : -1;
      // LL
      if (leftHeight > rightHeight)
      {
        balanceLL(root, leftChild);
      }
      // LR
      else
      {
        balanceLR(root);
      }
    }
    else
    {
      auto rightChild = root->right;
      leftHeight = rightChild->left ? rightChild->left->height : -1;
      rightHeight = rightChild->right ? rightChild->right->height : -1;
      // RR
      if (leftHeight < rightHeight)
      {
        balanceRR(root, rightChild);
      }
      // RL
      else
      {
        balanceRL(root);
      }
    }
  }
  void balanceLL(AVLTreeNode *&root, AVLTreeNode *leftChild)
  {
    root->left = leftChild->right;
    leftChild->right = root;
    root = leftChild;
    leftChild = leftChild->right;
    // update height
    leftChild->height = max(leftChild->left ? leftChild->left->height + 1 : 0, leftChild->right ? leftChild->right->height + 1 : 0);
    root->height = max(root->left ? root->left->height + 1 : 0, root->right->height + 1);

    // update size
    leftChild->size = 1 + (leftChild->left ? leftChild->left->size : 0) + (leftChild->right ? leftChild->right->size : 0);
    root->size = 1 + (root->left ? root->left->size : 0) + root->right->size;
  }
  void balanceRR(AVLTreeNode *&root, AVLTreeNode *rightChild)
  {
    root->right = rightChild->left;
    rightChild->left = root;
    root = rightChild;
    rightChild = rightChild->left;
    // update height
    rightChild->height = max(rightChild->right ? rightChild->right->height + 1 : 0, rightChild->left ? rightChild->left->height + 1 : 0);
    root->height = max(root->right ? root->right->height + 1 : 0, root->left->height + 1);
    // update size
    rightChild->size = 1 + (rightChild->left ? rightChild->left->size : 0) + (rightChild->right ? rightChild->right->size : 0);
    root->size = 1 + (root->right ? root->right->size : 0) + root->left->size;
  }
  void balanceLR(AVLTreeNode *&root)
  {
    balanceRR(root->left, root->left->right);
    balanceLL(root, root->left);
  }
  void balanceRL(AVLTreeNode *&root)
  {
    balanceLL(root->right, root->right->left);
    balanceRR(root, root->right);
  }
  int findMedian(AVLTreeNode *root, int target)
  {
    int leftSize = root->left ? root->left->size : 0;
    int rightSize = root->right ? root->right->size : 0;
    if (target == leftSize + 1)
      return root->val;
    if (target > leftSize + 1)
      return findMedian(root->right, target - leftSize - 1);
    else
      return findMedian(root->left, target);
  }

public:
  AVLTreeNode *head = NULL;
  AVLTree()
  {
  }
  void insert(int x)
  {
    if (head == NULL)
    {
      head = new AVLTreeNode(x);
      return;
    }
    insert(x, head);
  }
  void traversal(AVLTreeNode *root)
  {
    if (root == NULL)
      return;
    traversal(root->left);
    cout << root->val << endl;
    traversal(root->right);
  }
  double findMedian()
  {
    if (head->size % 2 == 0)
      return (double)(findMedian(head, head->size / 2) + findMedian(head, (head->size / 2) + 1)) / (double)2;
    else
      return findMedian(head, (head->size / 2) + 1);
  }
};

class MedianFinder
{
  AVLTree tree;

public:
  /** initialize your data structure here. */
  MedianFinder()
  {
  }

  void addNum(int num)
  {
    tree.insert(num);
  }

  double findMedian()
  {
    return tree.findMedian();
  }
};

int main()
{

  return 0;
}