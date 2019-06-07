#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
      return a[0] < b[0];
    });
    if (intervals.size() <= 1)
      return intervals;
    for (int i = 0; i < intervals.size() - 1; i++)
    {
      vector<int> compareArray;
      if (i == 0)
      {
        compareArray = intervals[0];
      }
      else
      {
        compareArray = result[result.size() - 1];
      }
      vector<int> compareArrayAfter = intervals[i + 1];
      if (compareArray[1] < compareArrayAfter[0])
      {
        if (i == 0)
        {
          result.push_back(compareArray);
        }
        result.push_back(compareArrayAfter);
      }
      else
      {
        int largest = max(compareArray[1], compareArrayAfter[1]);
        if (i == 0)
        {
          result.push_back({compareArray[0], largest});
        }
        else
        {
          result[result.size() - 1][1] = largest;
        }
      }
    }
    return result;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<vector<int>> x{{1, 4}, {10, 19}}; // -4 -1 -1 0 1 2

  vector<vector<int>> result = s->merge(x);

  for (int i = 0; i < result.size(); i++)
  {
    vector<int> inner = result[i];
    for (int j = 0; j < inner.size(); j++)
    {
      cout << inner[j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
