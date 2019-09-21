// Runtime: 32 ms, faster than 34.68% of C++ online submissions for Reconstruct Itinerary.
// Memory Usage: 17.6 MB, less than 25.00% of C++ online submissions for Reconstruct Itinerary.
// O(nlogn)

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>>& tickets)
  {
    for (auto ticket : tickets)
      targets[ticket[0]].insert(ticket[1]);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
  }

  map<string, multiset<string>> targets;
  vector<string> route;

  void visit(string airport)
  {
    while (targets[airport].size())
    {
      string next = *targets[airport].begin();
      targets[airport].erase(targets[airport].begin());
      visit(next);
    }
    route.push_back(airport);
  }
};


int main()
{
  vector<vector<string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
  auto result = Solution().findItinerary(tickets);
  for(auto route: result)
    cout << route << ' ';
  cout << endl;
  return 0;
}