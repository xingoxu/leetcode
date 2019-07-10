#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {
    int left = 0, maxRight = numbers.size() - 1;
    while (true)
    {
      if (numbers[left] + numbers[maxRight] == target)
      {
        return {left + 1, maxRight + 1};
      }
      else if (numbers[left] + numbers[maxRight] > target)
      {
        maxRight--;
        continue;
      }
      else
      {
        ++left;
        if (maxRight < numbers.size() - 1)
          maxRight++;
        continue;
      }
    }
    return {0, 0};
  }
};

int main()
{
  vector<int> numbers{
      5, 25, 75};
  const auto &result = Solution().twoSum(numbers, 100);
  
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ' ';
  }
  cout << endl;

  return 0;
}
