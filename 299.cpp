#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  string getHint(const string secret, const string guess)
  {
    vector<int> countMap(10, 0);
    for (int i = 0; i < secret.size(); ++i)
    {
      ++countMap[secret[i] - '0'];
    }
    int hitBoth = 0, hitSingle = 0;
    for (int i = 0; i < guess.size(); ++i)
    {
      if (i < secret.size() && secret[i] == guess[i])
      {
        ++hitBoth;
        if (countMap[guess[i] - '0'] > 0)
        {
          countMap[guess[i] - '0']--;
        }
        else
        {
          hitSingle--;
        }
      }
      else if (countMap[guess[i] - '0'] > 0)
      {
        countMap[guess[i] - '0']--;
        hitSingle++;
      }
    }
    return to_string(hitBoth) + "A" + to_string(hitSingle) + "B";
  }
};

int main()
{
  cout << Solution().getHint("1807", "7810") << endl;
  return 0;
}