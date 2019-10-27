#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      vector<int> dict(26,0);
      for (auto &letter : magazine)
        ++dict[letter - 'a'];
      for(auto &letter:ransomNote)
        if (--dict[letter - 'a'] < 0)
          return false;
      return true;
    }
};

int main() {
  cout << Solution().canConstruct("aa", "ab") << endl;
  return 0;
}