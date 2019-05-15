#include <string>
#include <iostream>
using namespace std;

const int ASCIILength = 127;
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int stringLength = s.length();
    int repeat[ASCIILength];
    memset(repeat, -1, sizeof(repeat));

    int biggest = 0;
    int sum = 0;
    for (int i = 0; i < stringLength; i++)
    {
      int character = (int)s[i];
      if (repeat[character] > -1)
      {
        sum > biggest && (biggest = sum);
        i = repeat[character];
        memset(repeat, -1, sizeof(repeat));
        sum = 0;
      } else {
        repeat[character] = i;
        sum++;
      }
    }
    sum > biggest && (biggest = sum);

    return biggest;
  }
};

int main()
{
  Solution *s = new Solution();
  cout << s->lengthOfLongestSubstring(" ") << endl;
  return 0;
}