// Runtime: 60 ms, faster than 11.82% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 10.6 MB, less than 34.94% of C++ online submissions for Minimum Window Substring.
// Can be optimized


#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  string minWindow(string s, string t)
  {
    map<char, int> charMap;
    for (int i = t.size() - 1; i >= 0; i--)
    {
      if (charMap[t[i]])
        charMap[t[i]]++;
      else
        charMap[t[i]] = 1;
    }

    int leftPointer = 0;
    int smallestLength = INT_MAX;
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
      char now = s[i];
      map<char, int>::iterator it;
      bool allHit = true;

      for (it = charMap.begin(); it != charMap.end(); it++)
      {
        if (it->first == now)
        {
          it->second--;
        }
        if (it->second > 0)
          allHit = false;
      }

      while (allHit)
      {
        char left = s[leftPointer];
        for (it = charMap.begin(); it != charMap.end(); it++)
        {
          if (it->first == left)
          {
            it->second++;
          }
          if (it->second > 0)
          {
            int length = i - leftPointer + 1;
            if (length < smallestLength)
            {
              result = s.substr(leftPointer, length);
              smallestLength = length;
            }
            allHit = false;
          }
        }

        leftPointer++;
      }
    }
    return result;
  }
};

int main()
{
  Solution s;

  vector<int> input = {2, 0, 2, 1, 1, 0};

  cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;

  return 0;
}
