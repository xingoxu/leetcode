#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), [](int &a, int &b) -> bool {
        auto num_a = to_string(a);
        auto num_b = to_string(b);
        int iterator = 0;
        while (iterator < num_a.size() && iterator < num_b.size() && num_a[iterator] == num_b[iterator])
        {
          iterator++;
        }
        if (iterator < num_a.size() && iterator < num_b.size())
        {
          return num_a[iterator] > num_b[iterator];
        } else
        {
          // num_b < num_a
          return stoi(num_a + num_b) > stoi(num_b + num_a);
        }
      });

      stringstream ss;
      bool isFirst = true;
      for (int i = 0; i < nums.size(); i++)
      {
        if(nums[i] != 0)
          isFirst = false;
        if (isFirst && nums[i] == 0 && i != nums.size() - 1)
          continue;
        ss << nums[i];
      }
      return ss.str();
    }
};

int main()
{
  vector<int> x{3,30,34,5,9};

  cout << Solution().largestNumber(x) << endl;

  return 0;
}
