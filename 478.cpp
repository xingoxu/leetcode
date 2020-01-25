// Runtime: 140 ms, faster than 83.45% of C++ online submissions for Generate Random Point in a Circle.
// Memory Usage: 27.4 MB, less than 100.00% of C++ online submissions for Generate Random Point in a Circle.

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
  double _radius;
  double _x_center;
  double _y_center;
  bool inCircle(double x, double y)
  {
    auto _x = x - _x_center;
    auto _y = y - _y_center;
    return sqrt(_x * _x + _y * _y) <= _radius;
  }

public:
  Solution(double radius, double x_center, double y_center)
  {
    _radius = radius;
    _x_center = x_center;
    _y_center = y_center;
  }

  vector<double> randPoint()
  {
    double x, y;
    do
    {
      auto x_distance = (double)rand() / RAND_MAX * (_radius * 2) - _radius;
      auto y_distance = (double)rand() / RAND_MAX * (_radius * 2) - _radius;
      x = _x_center + x_distance;
      y = _y_center + y_distance;
    } while (!inCircle(x, y));
    return vector<double>{x, y};
  }
};

int main()
{
  Solution *obj = new Solution(1, 0, 0);
  vector<double> param_1 = obj->randPoint();
  cout << param_1[0] << ' ' << param_1[1] << endl;
  return 0;
}