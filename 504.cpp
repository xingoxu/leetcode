#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
  string reverseString(string str) {
    reverse(str.begin(), str.end());
    return str;
  }

public:
  string convertToBase7(int num)
  {
    if(num == 0)
      return 0;
    bool isMinus = num < 0;
    num = abs(num);
    stringstream ss;

    while (num != 0) {
      int remain = num % 7;
      num /= 7;
      ss << remain;
    }
    if(isMinus)
        ss << '-';
    return reverseString(ss.str());
  }
};

int main()
{
  cout << Solution().convertToBase7(-7) << endl;
  return 0;
}