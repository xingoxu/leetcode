// Runtime: 4 ms, faster than 58.28% of C++ online submissions for Evaluate Division.
// Memory Usage: 9.4 MB, less than 88.89% of C++ online submissions for Evaluate Division.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
  unordered_map<string, unordered_map<string, double>> table;
  double query(vector<string> &query)
  {
    unordered_set<string> prevent_duplicate;
    string &first = query[0], &second = query[1];
    if (table.find(first) == table.end())
      return -1;
    cout << first << ' ' << endl;
    queue<pair<string, double>> remain;
    remain.push({first, 1});
    prevent_duplicate.insert(first);
    while (!remain.empty())
    {
      auto p = remain.front();
      remain.pop();
      for(auto &downPair: table[p.first]) {
        if(downPair.first == second)
          return p.second * downPair.second;
        if (prevent_duplicate.find(downPair.first) == prevent_duplicate.end()){
          remain.push({downPair.first, p.second * downPair.second});
          prevent_duplicate.insert(downPair.first);
        }
      }
    }
    return -1;
  }

public:
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
  {
    for (int i = equations.size() - 1; i >= 0;--i) {
      auto &pair = equations[i];
      table[pair[0]][pair[1]] = values[i];
      table[pair[1]][pair[0]] = 1 / values[i];
    }
    vector<double> result(queries.size());
    int count = 0;
    for (auto &q : queries)
      result[count++] = query(q);
    return result;
  }
};

int main()
{
  vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
  vector<double> values = {2.0, 3.0};
  vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
  auto result = Solution().calcEquation(equations, values, queries);
  for(auto &r : result)
    cout << r << ' ';
  cout << endl;
  return 0;
}