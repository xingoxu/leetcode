// Runtime: 12 ms, faster than 28.30% of C++ online submissions for Zuma Game.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Zuma Game.
// TODO: optimization

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  int findMinStep(string board, unordered_map<char, int> &hand)
  {
    if (board.size() == 0)
      return 0;
    int ret = INT_MAX;
    for (int i = board.size() - 1; i >= 0;)
    {
      int j = i--;
      auto &originCh = board[j];
      while (i >= 0 && board[i] == originCh)
        --i;
      // cout << j << endl;
      int sameLength = j - i;
      int useHand = sameLength >= 3 ? 0 : 3 - sameLength;
      if (hand[originCh] < useHand)
        continue;
      hand[originCh] -= useHand;
      string clearBoard = board.substr(0, i + 1) + board.substr(j + 1);
      // cout << originCh << ' ' << clearBoard << endl;
      auto child = findMinStep(clearBoard, hand);
      if(child != -1)
        ret = min(child + useHand, ret);
      hand[originCh] += useHand;
    }
    return ret == INT_MAX ? -1 : ret;
  }

public:
  int findMinStep(string board, string hand)
  {
    unordered_map<char, int> dict;
    for (auto &ch : hand) 
      ++dict[ch];
    return findMinStep(board, dict);
  }
};

int main()
{
  cout << Solution().findMinStep("RBYYBBRRB", "YRBGB") << endl;
  return 0;
}