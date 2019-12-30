#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int findLineNumber(char ch, string line, int lineNumber)
  {
    int lineNum = 0;
    for (auto &lch : line)
    {
      if (lch == tolower(ch))
      {
        lineNum = lineNumber;
        break;
      }
    }
    return lineNum;
  }

public:
  vector<string> findWords(vector<string> &words)
  {
    const string line1 = "qwertyuiop";
    const string line2 = "asdfghjkl";
    const string line3 = "zxcvbnm";
    vector<string> ret;
    for (auto &word : words)
    {
      int wordLine = 0;
      bool add = true;
      for (auto &ch : word)
      {
        int line = findLineNumber(ch, line1, 1);
        if (line == 0)
          line = findLineNumber(ch, line2, 2);
        if (line == 0)
          line = findLineNumber(ch, line3, 3);
        if (wordLine == 0)
          wordLine = line;
        else if (wordLine != line)
        {
          add = false;
          break;
        }
      }
      if (add)
      {
        ret.push_back(word);
      }
    }
    return ret;
  }
};

int main()
{
  vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
  auto result = Solution().findWords(words);
  for (auto &ret : result)
  {
    cout << ret << ' ';
  }
  cout << endl;
  return 0;
}
