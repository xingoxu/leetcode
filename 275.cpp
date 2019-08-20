// Runtime: 24 ms, faster than 52.10% of C++ online submissions for H-Index II.
// Memory Usage: 12.4 MB, less than 86.67% of C++ online submissions for H-Index II.

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
