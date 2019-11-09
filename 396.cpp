#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxRotateFunction(vector<int> &A)
  {
    long sum = 0, current = 0, count = 0;
    for (auto &x : A)
    {
      sum += x;
      current += (count++) * x;
    }
    int ret = current;
    for (int i = 1; i < A.size(); ++i)
    {
      current = current - sum + ((long)A.size()) * A[i - 1];
      ret = max(ret, (int)current);
    }
    return ret;
  }
};

int main()
{
  vector<int> A = {2147483647,2147483647};
  cout << Solution().maxRotateFunction(A) << endl;
  return 0;
}