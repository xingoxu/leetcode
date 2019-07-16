// Runtime: 44 ms, faster than 78.79% of C++ online submissions for Repeated DNA Sequences.
// Memory Usage: 24.4 MB, less than 32.04% of C++ online submissions for Repeated DNA Sequences.
//  ??? Maybe need to TODO

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
      unordered_map<string, int> map;
      vector<string> ret;
      for (int i = 0; i < 10; i++)
      {
        int iterator = i;
        while (iterator + 9 < s.size())
        {
          const auto &current = s.substr(iterator, 10);
          if (++map[current] == 2)
            ret.push_back(current);
          iterator += 10;
        }
      }
      return ret;
    }
};

int main()
{
  const auto &result = Solution().findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
  for (int i = 0; i < result.size();i++) {
    cout << result[i] << endl;
  }
  return 0;
}
