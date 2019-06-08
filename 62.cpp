#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> cache = {{1}};

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    if (cache.size() >= n && cache[n - 1].size() >= m)
    {
      return cache[n - 1][m - 1];
    }
    int lastNumber = 0;
    cache.resize(n);
    for (int i = 0; i < n; i++)
    {
      vector<int> *rowPointer = &cache[i];
      for (int j = rowPointer->size(); j < m; j++)
      {
        int up = 0;
        int left = 0;
        if (i - 1 >= 0)
        {
          up = cache[i - 1][j];
        }
        if (j - 1 >= 0)
        {
          left = (*rowPointer)[j - 1];
        }
        lastNumber = up + left;
        rowPointer->push_back(lastNumber);
      }
    }

    return lastNumber;
  }
};

int main()
{
  Solution *s = new Solution();

  // vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  cout << s->uniquePaths(3, 2) << endl;
  for (int i = 0; i < cache.size();i++) {
    for (int j = 0; j < cache[i].size();j++) {
      cout << cache[i][j] << ' ';
    }
    cout << endl;
  }
  cout << s->uniquePaths(7, 3) << endl;
  cout << s->uniquePaths(3, 3) << endl;
  cout << s->uniquePaths(7, 36) << endl;
  cout << s->uniquePaths(36, 7) << endl;


  return 0;
}
