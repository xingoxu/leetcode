// Runtime: 8 ms, faster than 85.27% of C++ online submissions for String Compression.
// Memory Usage: 9.2 MB, less than 83.33% of C++ online submissions for String Compression.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    if (chars.size() <= 0)
      return 0;
    int count = 0;
    int total = 0;
    char pre = chars[0];
    for (int i = 0; i < chars.size(); ++i)
    {
      auto x = chars[i];
      if (x != pre)
      {
        if (count > 1){
          auto c = to_string(count);
          chars[total++] = pre;
          for (auto &cc : c)
            chars[total++] = cc;
        }
        else
          chars[total++] = pre;
        
        count = 1;
        pre = x;
      }
      else
        ++count;
    }
    if (count > 1){
      auto c = to_string(count);
      chars[total++] = pre;
      for (auto &cc : c)
        chars[total++] = cc;
    }
    else
      chars[total++] = pre;
    return total;
  }
};

int main()
{
  vector<char> chars = {'a', 'b', 'b'};
  cout << Solution().compress(chars) << endl;
  return 0;
}