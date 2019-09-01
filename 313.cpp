// Runtime: 424 ms, faster than 9.98% of C++ online submissions for Super Ugly Number.
// Memory Usage: 86.3 MB, less than 22.22% of C++ online submissions for Super Ugly Number.
// TODO: faster solution

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      priority_queue<long, vector<long>, greater<long>> pq;
      pq.push(1l);
      long ret = 1;
      for (int i = 0; i < n; i++)
      {
        ret = pq.top();
        pq.pop();
        while(pq.size() > 0 && ret == pq.top())
          pq.pop();
        for (int j = primes.size() - 1; j >= 0; --j)
        {
          pq.push(ret * (long)primes[j]);
        }
      }
      return ret;
    }
};

int main()
{
  vector<int> primes = {7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251};
  cout << Solution().nthSuperUglyNumber(100000, primes) << endl;
  return 0;
}