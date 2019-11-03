
#include <iostream>
#include <unordered_set>
using namespace std;

class RandomizedSet
{
  unordered_set<int> set;

public:
  /** Initialize your data structure here. */
  RandomizedSet()
  {
  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val)
  {
    if (set.find(val) != set.end())
      return false;
    set.insert(val);
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val)
  {
    if (set.find(val) == set.end())
      return false;
    set.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom()
  {
    auto p = set.begin();
    int res, len = 1;
    while (p != set.end())
    {
      if (rand() % len == 0)
      {
        res = *p;
      }
      ++len, ++p;
    }
    return res;
  }
};

int main()
{

  RandomizedSet *obj = new RandomizedSet();
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
