// TODO: find a more efficient method
// Runtime: 108 ms, faster than 6.74% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
// Memory Usage: 76 MB, less than 9.09% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  vector<int> mergeSort(vector<vector<int>> &matrix, int lineNum)
  {
    int total = (matrix.size() - lineNum) * 2 - 1;
    vector<int> ret(total);
    int x = lineNum + 1, y = lineNum;
    for (int i = 0; i < total; ++i)
    {
      int next;
      if (x < matrix.size() && y < matrix.size())
      {
        if (matrix[x][lineNum] <= matrix[lineNum][y])
          next = matrix[x++][lineNum];
        else
          next = matrix[lineNum][y++];
      }
      else if (x < matrix.size())
        next = matrix[x++][lineNum];
      else
        next = matrix[lineNum][y++];
      ret[i] = next;
    }
    return ret;
  }
  vector<int> mergeSort(vector<int> const &a, vector<int> const &b)
  {
    int total = a.size() + b.size();
    vector<int> ret(total);
    int x = 0, y = 0;
    for (int i = 0; i < total; ++i)
    {
      int next;
      if (x < a.size() && y < b.size())
      {
        if (a[x] <= b[y])
          next = a[x++];
        else
          next = b[y++];
      }
      else if (x < a.size())
        next = a[x++];
      else
        next = b[y++];
      ret[i] = next;
    }
    return ret;
  }

public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    int count = 1, numRemoved = 0;
    vector<int> sortedOrder{matrix[0][0]};
    while (k - 1 >= count * count - 1)
    {
      auto index = count - 1;
      const auto &childSort = mergeSort(matrix, index);
      auto previousResult = count * count - index * index;
      numRemoved += previousResult;
      sortedOrder = vector<int>(sortedOrder.begin() + (previousResult), sortedOrder.end());
      sortedOrder = mergeSort(sortedOrder, childSort);
      ++count;
    }
    return sortedOrder[k - numRemoved];
  }
};

int main()
{
  vector<vector<int>> matrix{
      {1, 5, 9},
      {10, 11, 13},
      {12, 13, 15}};
  cout << Solution().kthSmallest(matrix, 7) << endl;
  return 0;
}
