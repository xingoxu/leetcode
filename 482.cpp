#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
  string licenseKeyFormatting(string S, int K)
  {
    int charCount = 0;
    for(auto &ch: S) 
      if(ch != '-')
        ++charCount;
    int start = charCount % K == 0 ? K : charCount % K, index = 0;
    stringstream ss;
    for (int i = 0; i < S.size(); ++i)
    {
      auto &ch = S[i];
      if (ch == '-')
        continue;
      if (start == 0)
      {
        ss << '-';
        start = K;
      }
      // cout << index << endl;
      ss << ((char)toupper(ch));
      --start, ++index;
    }
    return ss.str();
  }
};

int main()
{
  cout << Solution().licenseKeyFormatting("0123456789", 1) << endl;
  return 0;
}