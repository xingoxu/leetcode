// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Genetic Mutation.
// Memory Usage: 8.8 MB, less than 50.00% of C++ online submissions for Minimum Genetic Mutation.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
  bool isMutation(string &a, string &b)
  {
    int diff = 0;
    if (a.size() != b.size())
      return false;
    for (int i = a.size() - 1; i >= 0; --i)
    {
      if (a[i] != b[i])
        ++diff;
      if (diff >= 2)
        return false;
    }
    if (diff == 0)
      return false;
    return true;
  }

public:
  int minMutation(string start, string end, vector<string> &bank)
  {
    queue<string> bfs;
    bfs.push(start);
    int count = 0;
    while (!bfs.empty())
    {
      queue<string> nextLevel;
      while (!bfs.empty())
      {
        auto str = bfs.front();
        bfs.pop();
        for (int i = bank.size() - 1; i >= 0; --i)
        {
          if (isMutation(bank[i], str))
          {
            if (bank[i] == end)
              return count + 1;
            nextLevel.push(bank[i]);
            bank.erase(bank.begin() + i);
          }
        }
      }
      ++count;
      bfs = nextLevel;
    }
    return -1;
  }
};

int main()
{
  vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  cout << Solution().minMutation("AAAAACCC", "AACCCCCC", bank) << endl;
  return 0;
}