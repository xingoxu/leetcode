#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
      string str = to_string(x);
      int rightCount = str.size()-1;
      int leftCount = 0;
      while(leftCount < rightCount) {
        if (str[rightCount] != str[leftCount]) {
          return false;
        }
        leftCount++;
        rightCount--;
      }
      return true;
    }
};

int main()
{
  Solution *s = new Solution();

  cout << s->isPalindrome(-121) << endl;
  return 0;
}