#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

class Solution
{
  unordered_map<int, list<int>> dict;

public:
  Solution(vector<int> &nums)
  {
    for (int i = nums.size() - 1; i >= 0; --i)
      dict[nums[i]].push_back(i);
  }

  int pick(int target)
  {
    // srand((int)time(0));
    int result, len = 1;
    auto &li = dict[target];
    auto p = li.begin();
    while (p != li.end())
    {
      if (rand() % len == 0)
      {
        result = *p;
      }
      len++;
      ++p;
    }
    return result;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main()
{
  vector<int> nums{1, 2, 3, 3, 3};
  Solution *obj = new Solution(nums);
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(3) << endl;
  cout << obj->pick(1) << endl;
  return 0;
}