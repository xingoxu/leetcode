#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

class Solution {
  public:
    vector<int> grayCode(int n)
    {
      if (n == 0)
        return {0};
      if (n == 1)
        return {0, 1};

      const vector<int> &previousResult = grayCode(n - 1);
      vector<int> result;
      int count = 2, previousResultSize = previousResult.size();
      const int andNumber = pow(2, n - 1);
      bool statusZeroFirst = true;
      for (int i = 0; i < previousResultSize; i++)
      {
        const int &x = previousResult[i];
        int a, b;
        if (statusZeroFirst)
        {
          a = 0 | x;
          b = andNumber | x;
        } else {
          a = andNumber | x;
          b = 0 | x;
        }
        result.push_back(a);
        result.push_back(b);
        statusZeroFirst = !statusZeroFirst;
      }
      return result;
    }
    void printbinary(const unsigned int val, int n)
    {
      for (int i = n - 1; i >= 0; i--)
      {
        if (val & (1 << i))
          cout << "1";
        else
          cout << "0";
      }
    }
};

int main() {
  int n = 4;
  const vector<int> &result = Solution().grayCode(n);
  for (int i = 0; i < result.size();i++) {
    Solution().printbinary(result[i], n);
    cout << endl;
  }
}