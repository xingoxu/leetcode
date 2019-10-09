
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
  bool binarySearch(int &num, int start, int end)
  {
    if (start > end)
      return false;
    if (start * start > num || end * end < num)
      return false;
    if (start == end)
      return start * start == num;
    int middle = (end - start) / 2 + start;
    int value = middle * middle;
    if(value == num)
      return true;
    else if(value > num)
      return binarySearch(num, start, middle - 1);
    else
      return binarySearch(num, middle + 1, end);
  }

public:
  bool isPerfectSquare(int num)
  {
    return binarySearch(num, 0, 46340);
  }
};

int main()
{
  cout << Solution().isPerfectSquare(14) << endl;
  return 0;
}
