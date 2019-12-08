// Runtime: 4 ms, faster than 99.74% of C++ online submissions for Longest Repeating Character Replacement.
// Memory Usage: 9.2 MB, less than 93.10% of C++ online submissions for Longest Repeating Character Replacement.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int characterReplacement(string s, int k)
  {
    vector<int> count(26, 0);
    int start = 0, end = 0, maxCount = 0, maxLength = 0;
    while(end < s.size()) {
      maxCount = max(maxCount, ++count[s[end] - 'A']);
      while (end - start + 1 - maxCount > k)
        --count[s[start++] - 'A'];
      maxLength = max(maxLength, end - start + 1);
      ++end;
    }
    return maxLength;
  }
};

int main()
{
  cout << Solution().characterReplacement("AABABBA", 1) << endl;
  return 0;
}