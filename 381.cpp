// Runtime: 60 ms, faster than 65.54% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// Memory Usage: 23.3 MB, less than 75.00% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedCollection
{
  vector<pair<int, int>> nums;
  unordered_map<int, vector<int>> map;

public:
  /** Initialize your data structure here. */
  RandomizedCollection()
  {
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val)
  {
    bool result = map.find(val) == map.end();
    map[val].push_back(nums.size());
    nums.push_back({val, map[val].size() - 1});
    return result;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val)
  {
    if (map.find(val) == map.end())
      return false;
    auto last = nums.back();
    map[last.first][last.second] = map[val].back();
    nums[map[val].back()] = last;
    map[val].pop_back();
    if (map[val].size() <= 0)
      map.erase(val);
    nums.pop_back();
    return true;
  }

  /** Get a random element from the collection. */
  int getRandom()
  {
    return nums[rand() % nums.size()].first;
  }
};

int main()
{

  RandomizedCollection *obj = new RandomizedCollection();
  cout << obj->insert(1) << endl;
  cout << obj->remove(2) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;
  cout << obj->getRandom() << endl;
  cout << obj->getRandom() << endl;
  cout << obj->remove(1) << endl;
  cout << obj->insert(2) << endl;
  cout << obj->getRandom() << endl;
  cout << obj->getRandom() << endl;
  cout << obj->getRandom() << endl;
  return 0;
}
