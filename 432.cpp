// Runtime: 48 ms, faster than 88.70% of C++ online submissions for All O`one Data Structure.
// Memory Usage: 22.7 MB, less than 100.00% of C++ online submissions for All O`one Data Structure.

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <sstream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void trimLeftTrailingSpaces(string &input)
{
  input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                return !isspace(ch);
              }));
}

void trimRightTrailingSpaces(string &input)
{
  input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                return !isspace(ch);
              })
                  .base(),
              input.end());
}

vector<int> stringToIntegerVector(string input)
{
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim))
  {
    output.push_back(stoi(item));
  }
  return output;
}

ListNode *stringToListNode(string input)
{
  // Generate list from the input
  vector<int> list = stringToIntegerVector(input);

  // Now convert that list into linked list
  ListNode *dummyRoot = new ListNode(0);
  ListNode *ptr = dummyRoot;
  for (int item : list)
  {
    ptr->next = new ListNode(item);
    ptr = ptr->next;
  }
  ptr = dummyRoot->next;
  delete dummyRoot;
  return ptr;
}

int stringToInteger(string input)
{
  return stoi(input);
}

string listNodeToString(ListNode *node)
{
  if (node == nullptr)
  {
    return "[]";
  }

  string result;
  while (node)
  {
    result += to_string(node->val) + ", ";
    node = node->next;
  }
  return "[" + result.substr(0, result.length() - 2) + "]";
}

class AllOne
{

  unordered_map<string, list<pair<string, int>>::iterator> map;
  // {value, times}
  list<pair<string, int>> times;

public:
  /** Initialize your data structure here. */
  AllOne()
  {
  }

  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
  void inc(string key)
  {
    if (map.count(key) <= 0)
    {
      times.push_front({key, 1});
      map[key] = times.begin();
      // cout << key << " hit: " << (*map[key]).first << endl;
    }
    else
    {
      auto it = map[key];
      auto nextIt = (++it);
      it = map[key];
      ++(*it).second;
      while (nextIt != times.end() && (*it).second > (*nextIt).second)
        ++nextIt;
      times.splice(nextIt, times, it);
    }
  }

  /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
  void dec(string key)
  {
    if (map.count(key) <= 0)
      return;
    auto it = map[key];
    if ((*it).second - 1 <= 0)
    {
      times.erase(it);
      map.erase(key);
      return;
    }
    auto beforeIt = (--it);
    it = map[key];
    --(*it).second;
    while (beforeIt != times.end() && (*it).second < (*beforeIt).second)
      --beforeIt;
    if(beforeIt == --it)
      return;
    else if (beforeIt == times.end())
      times.splice(times.begin(), times, map[key]);
    else
      times.splice(beforeIt, times, map[key]);
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey()
  {
    if (times.size() <= 0)
      return "";
    return times.back().first;
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey()
  {
    if (times.size() <= 0)
      return "";
    return times.front().first;
  }
};

int main()
{
  AllOne *obj = new AllOne();
  obj->inc("a");
  obj->inc("b");
  obj->inc("b");
  obj->inc("b");
  obj->inc("b");
  obj->dec("b");
  obj->dec("b");
  cout << obj->getMaxKey() << endl;
  cout << obj->getMinKey() << endl;
  return 0;
}