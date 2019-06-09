#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      for (int i = digits.size() - 1; i >= 0;i--) {
        int digit = digits[i];
        if (i == digits.size() - 1)
        {
          digit = ++digits[i];
        }
        if(digit >= 10 && i >0) {
          digits[i - 1]++;
          digits[i] -= 10;
        }
      }
      if (digits[0] >= 10) {
        digits[0] -= 10;
        digits.insert(digits.begin(), 1);
      }
      return digits;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{4,3,2,1};

  const vector<int> &result = s->plusOne(x);

  for (int i = 0; i < result.size(); i++)
  {
      cout << result[i] << ' ';
  }
  cout << endl;

  return 0;
}
