// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Watch.
// Memory Usage: 10.3 MB, less than 14.29% of C++ online submissions for Binary Watch.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<string> readBinaryWatch(int num)
  {
    if(num > 10 || num < 0)
      return {};
    // if(num == 0)
    //   return {"0:00"};

    int hourX = num > 6 ? num - 6 : 0;
    vector<string> ret;
    while (hourX <= 3 && num - hourX >= 0)
    {
      auto hRet = hour(hourX);
      auto mRet = minutes(num - hourX);

      if (hRet.size() == 0 && hourX == 0)
        hRet = {"0"};
      else if (hRet.size() == 0)
      {
        ++hourX;
        continue;
      }
      if (mRet.size() == 0 && num - hourX == 0)
        mRet = {"00"};
      else if(mRet.size() == 0)
      {
        ++hourX;
        continue;
      }

      for(auto &x: hRet) 
        for(auto &y: mRet)
          ret.push_back(x + ":" + y);

      ++hourX;
    }
    return ret;
  }
  vector<string> hour(int num)
  {
    const vector<int> display = {1, 2, 4, 8};
    unordered_map<string, vector<int>> cache;

    auto result = dfs(num, display, 0, cache);
    vector<string> ret;
    for (int i = result.size() - 1; i >= 0; --i)
      if(result[i] <= 11)
        ret.push_back(to_string(result[i]));

    return ret;
  }
  vector<int> dfs(int remain, const vector<int> &display, int i, unordered_map<string, vector<int>> &cache)
  {

    if (remain > display.size() - i || remain <= 0 || i >= display.size())
      return {};
    string key = to_string(remain) + "-" + to_string(i);
    if (cache.find(key) != cache.end())
      return cache[key];
    vector<int> res;

    if (remain == 1)
      res = {display[i]};
    else
    {
      auto cRes = dfs(remain - 1, display, i + 1, cache);
      for (auto &x : cRes)
        res.push_back(x + display[i]);
    }

    auto dRes = dfs(remain, display, i + 1, cache);
    for (auto &x : dRes)
    {
      res.push_back(x);
    }
    return cache[key] = res;
  }
  vector<string> minutes(int num)
  {
    const vector<int> display = {1, 2, 4, 8, 16, 32};
    unordered_map<string, vector<int>> cache;

    auto result = dfs(num, display, 0, cache);
    vector<string> ret;
    for (int i = result.size() - 1; i >= 0; --i){
      if(result[i] <= 59){
        string tmp;
        if (result[i] < 10)
          tmp =  "0" + to_string(result[i]);
        else
          tmp =  to_string(result[i]);
        ret.push_back(tmp);
      }
    }
    return ret;
  }
};

int main()
{
  auto result = Solution().readBinaryWatch(10);
  for (auto &x : result)
  {
    cout << x << endl;
  }
  return 0;
}