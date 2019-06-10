#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int pointer0 = -1;
    int pointer1 = -1;
    int pointer2 = -1;
    for (int i = 0; i < nums.size(); i++)
    {
      switch (nums[i])
      {
      case 0:
        nums[++pointer0] = 0;
      case 1:
        if (++pointer1 != pointer0)
          nums[pointer1] = 1;
      case 2:
        if (++pointer2 != pointer1)
          nums[pointer2] = 2;
      }
    }
  }
};

int main()
{
  Solution s;

  vector<int> input = {2, 0, 2, 1, 1, 0};

  s.sortColors(input);
  for (int i = 0; i < input.size();i++) {
    cout << input[i] << ' ';
  }
  cout << endl;

  return 0;
}
