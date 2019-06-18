#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int maxPoints(vector<vector<int>> &points)
  {
    int maxResult = 0;
    for (int i = 0; i < points.size(); i++)
    {
      unordered_map<int, unordered_map<int, int>> map;
      int samePoint = 0, biggest = 1;
      for (int j = i + 1; j < points.size(); j++)
      {
        const vector<int> &pointI = points[i];
        const vector<int> &pointJ = points[j];
        if (pointI[0] == pointJ[0] && pointI[1] == pointJ[1])
        {
          samePoint++;
        }
        else
        {
          int minusY = pointI[1] - pointJ[1];
          int minusX = pointI[0] - pointJ[0];
          int divider = gcd(minusY, minusX);
          minusY /= divider;
          minusX /= divider;
          if (map[minusY][minusX])
            ++map[minusY][minusX];
          else
            map[minusY][minusX] = 2;
          biggest = max(biggest, map[minusY][minusX]);
        }
      }
      maxResult = max(maxResult, biggest + samePoint);
    }
    return maxResult;
  }
  int gcd(int a, int b)
  {
    if (a == 0 || b == 0)
    {
      return a == 0 ? b : a;
    }
    return gcd(b, a % b);
  }
};

int main()
{
  vector<vector<int>> x = {{1, 1}};

  cout << Solution().maxPoints(x) << endl;
  return 0;
}