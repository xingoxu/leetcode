
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
      list<int> ll;
      vector<int> times(26, 0);
      for (auto &alphabet : s)
      {
        int a = alphabet - 'a';
        ++times[a];
        ll.push_back(a);
      }
      int count = 0;
      for (auto &x : ll)
      {
        if (times[x] == 1)
          return count;
        ++count;
      }
      return -1;
    }
};

int main()
{
  cout << Solution().firstUniqChar("loveleetcode") << endl;
  return 0;
}
