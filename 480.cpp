// Runtime: 100 ms, faster than 25.96% of C++ online submissions for Sliding Window Median.
// Memory Usage: 26.7 MB, less than 14.29% of C++ online submissions for Sliding Window Median.
//TODO: find a faster solution

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

    _balance(root);
  }

  void _balance(AVLTreeNode *&root)
  {
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

  int removeRight(AVLTreeNode *&root)
  {
    if (root->right)
    {
      auto val = removeRight(root->right);
      _balance(root);
      return val;
    }
    else
    {
      int val = root->val;
      auto copy = root;
      if (root->left)
      {
        root = root->left;
      } else {
        root = NULL;
      }
      delete copy;
      return val;
    }
  }

  void remove(int x, AVLTreeNode *&root)
  {
    if (x == root->val)
    {
      if (root->left && root->right)
      {
        root->val = removeRight(root->left);
      }
      else
      {
        root = root->left ? root->left : root->right;
        return;
      }
    }
    else if (x > root->val)
    {
      remove(x, root->right);
    }
    else
    {
      remove(x, root->left);
    }
    _balance(root);
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
      return ((double)findMedian(head, head->size / 2) + findMedian(head, (head->size / 2) + 1)) / (double)2;
    else
      return findMedian(head, (head->size / 2) + 1);
  }
  void remove(int x)
  {
    remove(x, head);
  }
};

class Solution
{
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k)
  {
    AVLTree tree;
    int i = 0;
    for (; i < k; ++i)
      tree.insert(nums[i]);
    i -= 1;

    vector<double> result{tree.findMedian()};
    while (++i < nums.size())
    {
      tree.insert(nums[i]);
      // cout << tree.head->val << endl;
      tree.remove(nums[i - k]);

      // tree.traversal(tree.head);
      // cout << "end" << endl;

      result.push_back(tree.findMedian());
      // cout << i << ' ' << tree.findMedian() << endl;
    }
    return result;
  }
};

int main()
{
  vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
  auto result = Solution().medianSlidingWindow(nums, 3);
  for (auto &num : result)
  {
    cout << num << ' ';
  }
  cout << endl;
  return 0;
}