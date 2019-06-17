#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  string string1;
  string string2;
  unordered_map<string, int> cache;
  bool isScramble(int left1, int right1, int left2, int right2)
  {
    int length1 = right1 - left1 + 1;
    int length2 = right2 - left2 + 1;
    if (length1 != length2)
    {
      return false;
    }
    string key = to_string(left1) + "#" + to_string(left2) + "#" + to_string(length1);
    if (cache[key] > 0)
      return cache[key] == 1;
    if (length1 == 2)
      return setCache(key, (string1[left1] == string2[left2] && string1[right1] == string2[right2]) || (string1[left1] == string2[right2] && string1[right1] == string2[left2]));
    if (length1 == 1)
      return setCache(key, string1[left1] == string2[left2]);

    for (int i = 0; i < length1 - 1; i++)
    {
      if (isScramble(left1, left1 + i, left2, left2 + i) && isScramble(left1 + i + 1, right1, left2 + i + 1, right2))
      {
        return setCache(key, true);
      }
      if (isScramble(left1, left1 + i, right2 - i, right2) && isScramble(left1 + i + 1, right1, left2, right2 - i - 1))
      {
        return setCache(key, true);
      }
    }
    return setCache(key, false);
  }
  bool setCache(string key, bool result)
  {
    cache[key] = result == true ? 1 : 2;
    return result;
  }

public:
  bool isScramble(string s1, string s2)
  {
    string1 = s1;
    string2 = s2;
    return isScramble(0, s1.size() - 1, 0, s2.size() - 1);
  }
};

int main()
{
  vector<vector<char>> x = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << Solution().isScramble("ccabcbabcbabbbbcbb",
                                "bbbbabccccbbbabcba")
       << endl;

  return 0;
}