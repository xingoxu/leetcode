
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{

public:
  string removeDuplicateLetters(string s)
  {
    vector<unsigned int> cnt(26, 0); //only consider lowercase letters
    vector<bool> inRes(26, false);   //true if the letter has been added to res
    for (char ch : s)
      cnt[ch - 'a']++;
    string res = ""; //use res as a stack
    for (char ch : s)
    {
      cnt[ch - 'a']--;
      if (res.empty())
      {
        res.push_back(ch);
        inRes[ch - 'a'] = true;
        continue;
      }
      if (inRes[ch - 'a'])
        continue;
      while (ch < res.back() && !res.empty() && cnt[res.back() - 'a'] > 0)
      {
        inRes[res.back() - 'a'] = false;
        res.pop_back();
      }
      res.push_back(ch);
      inRes[ch - 'a'] = true;
    }
    return res;
  }
};

int main()
{
  cout << Solution().removeDuplicateLetters("mitnlruhznjfyzmtmfnstsxwktxlboxutbic") << endl;
  return 0;
}