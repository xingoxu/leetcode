// Runtime: 8 ms, faster than 82.05% of C++ online submissions for Magical String.
// Memory Usage: 9.9 MB, less than 100.00% of C++ online submissions for Magical String.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  int magicalString(int n)
  {
    if(n == 0) return 0;
    string s = "122";
    int index = 2, count = 1;
    bool isOne = true;
    while (s.size() < n)
    {
      if (s[index++] == '2')
      {
        if (isOne)
        {
          s += "11";
          if (s.size() > n)
            return count + 1;
          count += 2;
        }
        else
        {
          s += "22";
        }
      }
      else
      {
        if (isOne)
        {
          s += '1';
          count += 1;
        }
        else
          s += '2';
      }
      isOne = !isOne;
    }
    return count;
  }
};

int main()
{
  cout << Solution().magicalString(9999) << endl;
}