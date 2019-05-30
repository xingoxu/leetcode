#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int length = nums.size();
      if (length <= 0)
        return length;
      int first = nums[0];
      int count = 1;
      vector<int>::iterator start = nums.begin();
      for (int i = 1; i < length; i++)
      {
        if(first == nums[i]) {
          nums.erase(start + i);
          i--;
          length--;
        }
        else
        {
          first = nums[i];
          count++;
        }
      }
      return count;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{0,0,1,1,1,2,2,3,3,4}; // -4 -1 -1 0 1 2

  // vector<vector<int>> result = s->removeNthFromEnd(x, -1);

  // for (int i = 0; i < result.size(); i++)
  // {
  //   cout << '[' << result[i][0];
  //   cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  // }

  cout << s->removeDuplicates(x) << endl;
  return 0;
}
