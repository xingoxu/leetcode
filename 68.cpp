#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    int i = 0;
    int wordsSize = words.size();
    vector<string> result;
    vector<string> stack;
    int stackSize = 0;
    int stackWordSize = 0;
    while (i < wordsSize)
    {
      string &now = words[i];
      if (stackWordSize + (stackSize - 1) + now.size() + 1 <= maxWidth)
      {
      }
      else
      {
        stringstream ss;
        if (stack.size() == 1)
        {
          int blanks = maxWidth - stack[0].size();
          ss << stack[0];
          for (int j = 0; j < blanks; j++)
            ss << " ";
        }
        else
        {
          int blanks = (maxWidth - stackWordSize) / (stackSize - 1);
          int diff = maxWidth - stackWordSize - (stackSize - 1) * blanks;
          int totalBlanks = maxWidth - stackWordSize;

          for (int j = 0; j < stack.size(); j++)
          {
            ss << stack[j];
            if (j == stack.size() - 1)
              break;
            int remainBlanks = stack.size() - 2 - j;
            int blankCount;
            if (diff == 0)
              blankCount = blanks;
            else {
              if (remainBlanks <= 0)
                blankCount = totalBlanks;
              else
                blankCount = ((totalBlanks - blanks - 1) / remainBlanks >= blanks) ? blanks + 1 : blanks;
            }

            for (int bi = 0; bi < blankCount; bi++)
              ss << " ";
            totalBlanks -= blankCount;
          }
        }
        result.push_back(ss.str());
        stackSize = 0;
        stackWordSize = 0;
        stack.clear();
      }
      stack.push_back(now);
      stackSize++;
      stackWordSize += now.size();
      i++;
    }

    stringstream ss;
    if (stack.size() == 1)
    {
      int blanks = maxWidth - stack[0].size();
      ss << stack[0];
      for (int j = 0; j < blanks; j++)
        ss << " ";
    }
    else
    {
      for (int j = 0; j < stack.size(); j++)
      {
        ss << stack[j];
        if (j == stack.size() - 1)
          break;
        ss << " ";
      }
      int blanks = maxWidth - stackWordSize - stackSize + 1;
      for (int j = 0; j < blanks;j++)
        ss << " ";
    }
    result.push_back(ss.str());

    return result;
  }
};

int main()
{
  Solution s;

  vector<string> x{"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"};

  const vector<string> &result = s.fullJustify(x, 16);

  for (int i = 0; i < result.size(); i++)
  {
    cout << '"' << result[i] << '"' << endl;
  }

  return 0;
}
