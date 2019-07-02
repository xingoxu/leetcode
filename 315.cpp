#include <iostream>
#include <vector>
using namespace std;

struct segment {
  int min, max, sum;
  segment *left, *right;
  segment(int _min, int _max)
  {
    min = _min;
    max = _max;
    sum = 0;
    left = NULL;
    right = NULL;
  }
};

class segmentTree
{
  segment *root;
  void deleteTree(segment *root) {
    if(root->left) {
      deleteTree(root->left);
    }
    if(root->right) {
      deleteTree(root->right);
    }
    delete root;
  }
  void add(int x, segment *_root)
  {
    ++_root->sum;
    if (_root->min == _root->max)
    {
      return;
    }
    int middle = (_root->max - _root->min) / 2 + _root->min;
    if(x > middle) {
      if(!_root->right)
        _root->right = new segment(middle + 1, _root->max);
      add(x, _root->right);
    } else {
      if(!_root->left)
        _root->left = new segment(_root->min, middle);
      add(x, _root->left);
    }
  }
  int sum(int x, segment *_root) {
    if(_root == NULL)
      return 0;
    if (_root->min == _root->max)
    {
      return _root->sum;
    }
    int middle = (_root->max - _root->min) / 2 + _root->min;
    int leftResult = _root->left ? _root->left->sum : 0;
    if (x == middle)
      return leftResult;
    if (x < middle)
    {
      return sum(x, _root->left);
    }else {
      return leftResult + sum(x, _root->right);
    }
  }

public:
  segmentTree(int min,int max) {
    root = new segment(min, max);
  }
  ~segmentTree() {
    deleteTree(root);
  }
  void add(int x) {
    add(x, root);
  }
  // find how many numbers smaller than x
  int sum(int x) {
    if(x < root->min || x > root->max)
      return 0;
    return sum(x, root);
  }
};

class Solution
{
public:
  vector<int> countSmaller(vector<int> &nums)
  {
    if (nums.size() == 0)
      return {};
    vector<int> result(nums.size());
    int minNumber = INT_MAX, maxNumber = INT_MIN;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      if (nums[i] < minNumber)
        minNumber = nums[i];
      if (nums[i] > maxNumber)
        maxNumber = nums[i];
    }
    auto st = segmentTree(minNumber, maxNumber);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      result[i] = st.sum(nums[i] - 1);
      st.add(nums[i]);
    }
    return result;
  }
};

int main()
{
  vector<int> x{-1, -1};

  const auto &result = Solution().countSmaller(x);

  for (int i = 0; i < result.size();i++){
    cout << result[i] << ' ';
  }
  cout << endl;

  return 0;
}
