// Runtime: 24 ms, faster than 98.87% of C++ online submissions for Range Sum Query - Mutable.
// Memory Usage: 19.1 MB, less than 75.00% of C++ online submissions for Range Sum Query - Mutable.
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

class NumArray
{
  vector<int> *origin;
  vector<int> BIT;
  int lastBit(int x)
  {
    return x & (-x);
  }
  void add(int pos, int val)
  {
    for (int i = ++pos; i < BIT.size(); i += lastBit(i))
    {
      BIT[i] += val;
    }
  }
  int sum(int pos)
  {
    int ret = 0;
    for (int i = ++pos; i > 0; i -= lastBit(i))
    {
      ret += BIT[i];
    }
    return ret;
  }

public:
  NumArray(vector<int> &nums)
  {
    origin = &nums;
    BIT = vector<int>(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i)
    {
      add(i, nums[i]);
    }
  }

  void update(int i, int val)
  {
    int diff = val - (*origin)[i];
    add(i, diff);
    (*origin)[i] = val;
  }

  int sumRange(int i, int j)
  {
    return sum(j) - sum(i - 1);
  }
};

int main()
{
  vector<int> nums = {1, 3, 5};

  NumArray *obj = new NumArray(nums);
  cout << obj->sumRange(0, 2) << endl; //9
  obj->update(1, 2);
  cout << obj->sumRange(0, 2) << endl; //8
  return 0;
}