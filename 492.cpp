#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
  vector<int> constructRectangle(int area)
  {
    int middle = sqrt(area);
    if (middle * middle == area)
      return {middle, middle};
    while (true)
    {
      if(area % middle == 0) {
        return {area / middle, middle};
      }
      --middle;
    }
    return {0, 0};
  }
};

int main()
{
  auto result = Solution().constructRectangle(4);
  cout << result[0] << ' ' << result[1] << endl;
  return 0;
}
