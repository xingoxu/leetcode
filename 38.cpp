#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
  string countAndSay(int n)
  {
    map<int, string> cache;
    return _countAndSay(n, cache);
  }
  string _countAndSay(int n, map<int, string> cache)
  {
    if (n == 1)
      return "1";
    if(n==2)
      return "11";
    if (cache[n] != "")
      return cache[n];

    string lastString = _countAndSay(n - 1, cache);
    int size = lastString.size();

    char lastChar = lastString[0];
    int count = 1;
    string result;
    for (int i = 1; i < size; i++)
    {
      if (lastString[i] == lastChar)
      {
        count++;
      }
      else
      {
        result.append(to_string(count));
        result += lastChar;
        count = 1;
        lastChar = lastString[i];
      }
    }
    result.append(to_string(count));
    result += lastChar;
    cache[n] = result;
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}; // -4 -1 -1 0 1 2

  // vector<vector<int>> result = s->removeNthFromEnd(x, -1);

  // for (int i = 0; i < result.size(); i++)
  // {
  //   cout << '[' << result[i][0];
  //   cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  // }

  cout << s->countAndSay(10) << endl;
  return 0;
}
