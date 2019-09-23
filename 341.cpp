// Runtime: 20 ms, faster than 63.39% of C++ online submissions for Flatten Nested List Iterator.
// Memory Usage: 16.1 MB, less than 84.85% of C++ online submissions for Flatten Nested List Iterator.
// TODO: change it to online

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedInteger
{
public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator
{
  queue<int> offline;

public:
  NestedIterator(vector<NestedInteger> &nestedList)
  {
    iterateNestList(nestedList);
  }
  void iterateNestList(const vector<NestedInteger> &nestedList)
  {
    for (int i = 0; i < nestedList.size(); ++i)
    {
      auto now = &nestedList[i];
      if (now->isInteger())
        offline.push(now->getInteger());
      else
        iterateNestList(now->getList());
    }
  }

  int next()
  {
    auto ret = offline.front();
    offline.pop();
    return ret;
  }

  bool hasNext()
  {
    return !offline.empty();
  }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */


int main()
{
  return 0;
}