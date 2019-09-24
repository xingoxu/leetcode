

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void reverseString(vector<char> &s)
  {
    int left = 0, right = s.size() - 1;
    while (left < right)
      swap(s[left++], s[right--]);
  }
};

int main()
{
  vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
  Solution().reverseString(s);
  for (auto x : s)
  {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}