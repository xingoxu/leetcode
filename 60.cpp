#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

static int lastN = 0;
static vector<string> cache;

class Solution
{
public:
  string getPermutation(int n, int k) {
    if (n == lastN && cache.size() >= k) {
      return cache[k - 1];
    } else {
      vector<string> newCache;
      cache = newCache;
    }
    vector<int> init(n);
    for (int i = 0; i < n;i++) {
      init[i] = i + 1;
    }
    vector<vector<int>> result = generatePermutation(init, k);
    for (int i = 0; i < result.size();i++) {
      std::stringstream ss;
      vector<int> v = result[i];
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
  vector<vector<int>> generatePermutation(vector<int> &nums, int max) {
    if(nums.size() <= 1)
      return {nums};
    vector<vector<int>> result;
    for (int i = 0; i < nums.size(); i++)
    {
      int temp = nums[i];
      nums.erase(nums.begin() + i);
      vector<int> sliceArray(nums.begin(), nums.end());
      vector<vector<int>> childResults = generatePermutation(sliceArray, INT_MAX);
      for (int j = 0; j < childResults.size(); j++)
      {
        vector<int> childResult = childResults[j];
        childResult.insert(childResult.begin(), temp);
        result.push_back(childResult);
        if (result.size() >= max){
          return result;
        }
      }
      nums.insert(nums.begin() + i, temp);
    }
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  cout << s->getPermutation(9, 54494) << endl;
  return 0;
}
