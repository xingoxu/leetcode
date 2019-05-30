#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int size = nums.size();
      int count = 0;
      for (int i = 0; i < size; i++)
      {
        int now = nums[i];
        if (now == val)
        {

        } else {
          if (i > count) {
            int temp = now;
            now = nums[count];
            nums[count] = temp;
          }
          count++;
        }
      }
      return count;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3,2,2,3}; // -4 -1 -1 0 1 2

  // vector<vector<int>> result = s->removeNthFromEnd(x, -1);

  // for (int i = 0; i < result.size(); i++)
  // {
  //   cout << '[' << result[i][0];
  //   cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  // }

  cout << s->removeElement(x, 3) << endl;
  cout << x[0] << endl;
  return 0;
}
