#include <iostream>
#include <vector>
using namespace std;

struct Trie
{
  vector<Trie *> next = vector<Trie *>(2, NULL);
};

class Solution
{
  void setTrie(int num, Trie *root)
  {
    for (int i = 31; i >= 0; --i)
    {
      int bit = (num & (1 << i)) == 0 ? 0 : 1;
      if (!root->next[bit])
        root->next[bit] = new Trie();
      root = root->next[bit];
    }
  }

public:
  int findMaximumXOR(vector<int> &nums)
  {
    auto root = new Trie();

    for (auto &x : nums)
      setTrie(x, root);

    auto cur = root;
    int maxN = 0;
    for (auto &num : nums)
    {
      int ret = 0;
      for (int j = 31; j >= 0; --j)
      {
        int bit = (num & (1 << j)) == 0 ? 0 : 1;
        if (cur->next[1 - bit])
        {
          ret += (1 << j);
          cur = cur->next[1 - bit];
        }
        else
          cur = cur->next[bit];
      }
      cur = root;
      maxN = max(maxN, ret);
    }

    return maxN;
  }
};

int main()
{
  vector<int> input = {8, 10, 2};
  cout << Solution().findMaximumXOR(input) << endl;
  return 0;
}