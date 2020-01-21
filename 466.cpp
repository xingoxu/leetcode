// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count The Repetitions.
// Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Count The Repetitions.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int getMaxRepetitions(string s1, int n1, string s2, int n2)
  {
    int i1 = 0, i2 = 0, result = 0, copy_n1 = n1;
    unordered_map<int, int> group_cache;
    unordered_map<int, int> result_cache;
    group_cache[0] = 0, result_cache[0] = 0;
    while (n1 > 0)
    {
      if (s1[i1] == s2[i2])
      {
        if (++i2 >= s2.size())
        {
          i2 = 0;
          ++result;
        }
      }

      if (++i1 >= s1.size())
      {
        int group = copy_n1 - n1;
        group_cache[group] = i2;
        result_cache[group] = result;

        for (int k = 0; k < group; ++k)
        {
          if (group_cache[k] == i2)
          {
            int prev_count = result_cache[k];
            int pattern_count = (copy_n1 - 1 - k) / (group - k) * (result - result_cache[k]);
            int after_count = result_cache[k + (copy_n1 - 1 - k) % (group - k)] - result_cache[k];
            return (prev_count + pattern_count + after_count) / n2;
          }
        }

        i1 = 0;
        --n1;
      }
    }
    return result / n2;
  }
};

int main()
{
  cout << Solution().getMaxRepetitions("lovelive",
                                       1,
                                       "lovelive",
                                       10);
  return 0;
}