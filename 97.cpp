#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
      map<string, bool> cache;
      return isInterleave(s1, 0, s2, 0, s3, 0, cache);
    }
    bool isInterleave(string &s1,int s1Start,string &s2,int s2Start, string &s3,int s3Start, map<string,bool> &cache){
      {
        stringstream keyStream;
        keyStream << s1Start << '-' << s2Start << '-' << s3Start;
        if(cache[keyStream.str()]) {
          return false;
        }
      }
      while (s3Start < s3.size())
      {
        if(s1Start < s1.size() && s2Start < s2.size() && s1[s1Start] == s2[s2Start] && s1[s1Start] == s3[s3Start]) {
          int childResult = isInterleave(s1, s1Start + 1, s2, s2Start, s3, s3Start + 1, cache) ||
                            isInterleave(s1, s1Start, s2, s2Start + 1, s3, s3Start + 1, cache);
          if (!childResult)
          {
            stringstream keyStream;
            keyStream << s1Start << '-' << s2Start << '-' << s3Start;
            cache[keyStream.str()] = true;
          }
          return childResult;
        }
        else if (s1Start < s1.size() && s1[s1Start] == s3[s3Start])
        {
          s1Start++;
        }
        else if (s2Start < s2.size() && s2[s2Start] == s3[s3Start])
        {
          s2Start++;
        }
        else
        {
          return false;
        }
        s3Start++;
      }
      return s1Start >= s1.size() && s2Start >= s2.size();
    }
};

int main()
{
  cout << Solution().isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
"babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;

  return 0;
}
