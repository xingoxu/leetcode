#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
  {
    unordered_map<int, int> ab;
    for (auto &a : A)
      for (auto &b : B)
      {
        ++ab[a + b];
      }

    int ret = 0;
    for (auto &c : C)
      for (auto &d : D)
        ret += ab[-c - d];
    return ret;
  }
};

int main()
{
  vector<int> A{-1, -1};
  vector<int> B{-1, 1};
  vector<int> C{-1, 1};
  vector<int> D{1, -1};
  cout << Solution().fourSumCount(A, B, C, D) << endl;
}