#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  string decodeString(string s)
  {
    int start = 0;
    return decodeString(s, start, 1);
  }
  string decodeString(string s, int &start, int times)
  {
    string number, tResult;
    while (start < s.size())
    {
      if(s[start] <= '9' && s[start] >= '0') {
        number += s[start];
      } else if(s[start] == '[') {
        int initStart = start + 1;
        tResult += decodeString(s, initStart, stoi(number));
        start = initStart;
        number = "";
      }
      else if (s[start] == ']')
      {
        break;
      }
      else
      {
        tResult += s[start];
      }
      ++start;
    }
    // cout << tResult << ' ' << times << endl;
    string result;
    for (int i = 1; i <= times; ++i)
    {
      result += tResult;
    }
    return result;
  }
};

int main()
{
  cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
  return 0;
}