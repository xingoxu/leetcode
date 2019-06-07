// Time exceeded when use generate Permutation
// try to use nextPermutation to generate permutation

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

static int lastN = 0;
static vector<string> cache = { "1,2,3,4,5,6,7,8,9" };

class Solution
{
public:
  string getPermutation(int n, int k)
  {
    vector<int> init(n);
    for (int i = 0; i < n; i++)
    {
      init[i] = i + 1;
    }

    for (int i = 0; i <= k - 2; i++)
    {
      nextPermutation(init);
    }
    std::stringstream ss;
    vector<int> v = init;
    for (int i = 0; i < v.size(); ++i)
    {
      ss << v[i];
    }
    string s = ss.str();

    return s;
  }
  // a cache version
  // but it seems be slower when adding cache
  string _getPermutation(int n, int k) {
    if (n == lastN && cache.size() >= k) {
      return cache[k - 1];
    }
    else if (n != lastN)
    {
      vector<string> newCache;
      cache = newCache;
    }
    vector<int> init(n);
    if (cache.size() == 0 ) {
      std::stringstream ss;
      for (int i = 0; i < n;i++) {
        init[i] = i + 1;
        ss << i + 1;
      }
      string s = ss.str();
      cache.push_back(s);
    } else {
      string s = cache[cache.size() - 1];
      for (int i = 0; i < n; i++)
      {
        init[i] = s[i] - '0';
      }
    }


    for (int i = cache.size(); i <= k - 1;i++) {
      nextPermutation(init);
      std::stringstream ss;
      vector<int> v = init;
      for (int i = 0; i < v.size(); ++i)
      {
        ss << v[i];
      }
      string s = ss.str();
      cache.push_back(s);
    }

    lastN = n;
    return cache[k - 1];
  }
  void nextPermutation(vector<int> &nums)
  {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i + 1] <= nums[i])
    {
      i--;
    }
    if (i >= 0)
    {
      int j = nums.size() - 1;
      while (j >= 0 && nums[j] <= nums[i])
      {
        j--;
      }
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }
    reverse(nums, i + 1);
  }
  void reverse(vector<int> &nums, int start) {
    int left = start, right = nums.size() - 1;
    while (left < right)
    {
      int temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
      left++;
      right--;
    }
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  cout << s->getPermutation(9, 206490) << endl;
  return 0;
}
