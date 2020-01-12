#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LFUCache
{
  int _capacity;
  unordered_map<int, int> key_index;
  vector<vector<int>> key_value_times;
  void move_before(int index)
  {
    while (index > 0 && key_value_times[index][2] >= key_value_times[index - 1][2])
    {
      swap(key_value_times[index], key_value_times[index - 1]);
      auto &key = key_value_times[index][0];
      key_index[key] = index;
      --index;
    }
    auto &key = key_value_times[index][0];
    key_index[key] = index;
  }

public:
  LFUCache(int capacity)
  {
    _capacity = capacity;
  }

  int get(int key)
  {
    if (key_index.count(key) <= 0)
      return -1;
    auto &pair = key_value_times[key_index[key]];
    ++pair[2];
    move_before(key_index[key]);
    return key_value_times[key_index[key]][1];
  }

  void put(int key, int value)
  {
    if (_capacity <= 0)
      return;
    vector<int> insertEl = {key, value, 1};
    if (key_index.count(key) > 0)
    {
      auto &pair = key_value_times[key_index[key]];
      pair[1] = value;
      ++pair[2];
      move_before(key_index[key]);
      return;
    }
    else if (key_value_times.size() >= _capacity)
    {
      // delete final element
      key_index.erase(key_value_times[_capacity - 1][0]);
      key_value_times[_capacity - 1] = insertEl;
    }
    else
    {
      key_value_times.push_back(insertEl);
    }
    move_before(key_value_times.size() - 1);
  }
};

int main()
{
  LFUCache *obj = new LFUCache(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  cout << obj->get(3) << endl;
  obj->put(4, 4);              // evicts key 1.
  cout << obj->get(1) << endl; // returns -1 (not found)
  cout << obj->get(3) << endl; // returns 3
  cout << obj->get(4) << endl; // returns 4
  return 0;
}
