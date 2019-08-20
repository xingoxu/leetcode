// Runtime: 4 ms, faster than 69.79% of C++ online submissions for H-Index.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for H-Index.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int hIndex(vector<int> &citations)
  {
    if (citations.size() == 0)
      return 0;
    sort(citations.begin(), citations.end());
    return citations.size() - find(citations, 0, citations.size() - 1);
  }
  int find(vector<int> &citations, int start, int end)
  {

    while (start < end - 1)
    {
      auto middle = (end - start) / 2 + start;
      if (citations[middle] >= (citations.size() - middle))
        end = middle;
      else
        start = middle;
    }
    if (citations[start] >= (citations.size() - start))
      return start;
    if (citations[end] >= (citations.size() - end))
      return end;
    return end + 1;
  }
};

int main()
{
  vector<int> citations{0};
  cout << Solution().hIndex(citations) << endl;

  return 0;
}
