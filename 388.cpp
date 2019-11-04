// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Absolute File Path.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Longest Absolute File Path.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int lengthLongestPath(string input)
  {
    vector<int> indents;

    int indent = 0, now = 0, maxLength = 0;
    bool isFile = false;
    for (auto &ch : input)
    {
      if(ch == '\n') {
        indents.resize(max((int)indents.size(), indent + 1));
        if (indent != 0)
        {
          indents[indent] = now + indents[indent - 1] + 1;
        } else {
          indents[indent] = now;
        }
        if(isFile)
          maxLength = max(indents[indent], maxLength);
        now = 0;
        indent = 0;
        isFile = false;
      }
      else if (ch == '\t')
      {
        ++indent;
      }
      else if (ch == '.')
      {
        isFile = true;
        ++now;
      }
      else
      {
        ++now;
      }
    }
    indents.resize(max((int)indents.size(), indent + 1));
    if (indent != 0)
    {
      indents[indent] = now + indents[indent - 1] + 1;
    } else {
      indents[indent] = now;
    }
    if(isFile)
      maxLength = max(indents[indent], maxLength);
    return maxLength;
  }
};

int main()
{
  cout << Solution().lengthLongestPath("a") << endl;
}