#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
  string convertToTitle(int n)
  {
    const char diff = 'A' - 1;

    string ret;

    while (n != 0)
    {
      int remain = n % 26;
      n = n / 26;
      if (remain > 0)
      {
        ret = (char)(diff + remain) + ret;
      }
      else
      {
        ret = 'Z' + ret;
        n--;
      }
    }
    return ret;
  }
};

int main()
{
  cout << Solution().convertToTitle(28) << endl;

  return 0;
}
