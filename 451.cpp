#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <sstream>
using namespace std;

class Solution
{
public:
  string frequencySort(string s)
  {
    unordered_map<char, int> map;
    for(auto &ch:s) 
      ++map[ch];
    auto comp = [](pair<char, int> a, pair<char, int> b) {
      return a.second < b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(comp);
    for (auto &p : map)
      pq.push({p.first, p.second});

    stringstream ss;
    while (!pq.empty())
    {
      for (int i = pq.top().second-1; i >=0 ;--i)
        ss << pq.top().first;

      pq.pop();
    }
    return ss.str();
  }
};

int main()
{
  cout << Solution().frequencySort("his s he a ha he  ha ae") << endl;
  return 0;
}
