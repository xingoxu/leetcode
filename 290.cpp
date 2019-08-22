#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool wordPattern(string pattern, string str)
  {
    unordered_map<char, string> map;
    unordered_map<string, char> reverse_map;
    stringstream ss;

    int patternIt = 0;
    for (int i = 0; i <= str.size(); ++i)
    {
      if (i != str.size() && str[i] != ' ')
      {
        ss << str[i];
      }
      else
      {
        auto it = map.find(pattern[patternIt]);
        auto reverseIt = reverse_map.find(ss.str());
        if (it != map.end())
        {
          if (it->second != ss.str() || reverseIt->second != pattern[patternIt])
            return false;
        } else if(reverseIt != reverse_map.end()) {
          return false;
        }
        else
        {
          map[pattern[patternIt]] = ss.str();
          reverse_map[ss.str()] = pattern[patternIt];
        }
        ++patternIt;
        ss = stringstream();
      }
    }
    if(patternIt != pattern.size())
      return false;
    return true;
  }
};

int main()
{
  cout << Solution().wordPattern("ab", "dog cat");
  return 0;
}