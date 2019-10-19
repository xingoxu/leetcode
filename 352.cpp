#include <iostream>
#include <vector>
using namespace std;

class SummaryRanges
{
private:
  vector<vector<int>> intervals;

  int binarySearch(vector<vector<int>> &intervals, int val)
  {
    return binarySearchHelper(intervals, 0, intervals.size(), val);
  }

  int binarySearchHelper(vector<vector<int>> &intervals, int start, int end, int val)
  {
    if (start == end)
      return -1;
    if (start + 1 == end && intervals[start][0] < val)
      return start;

    int mid = (start + end) / 2;
    if (intervals[mid][0] == val)
    {
      return mid;
    }
    else if (intervals[mid][0] < val)
    {
      return binarySearchHelper(intervals, mid, end, val);
    }
    else
    { //intervals[mid] > val
      return binarySearchHelper(intervals, start, mid, val);
    }
  }

public:
  /** Initialize your data structure here. */
  SummaryRanges()
  {
    intervals = vector<vector<int>>();
  }

  /** For a new number n, find the last(biggest) interval
     *  [s,t], such that s < n. If no such interval exists, 
     *  return -1.
     */
  void addNum(int val)
  {
    int index = binarySearch(intervals, val);

    // intervals[index] contains val
    if (index != -1 && intervals[index][1] >= val)
    {
      return;
    }
    if (index != intervals.size() - 1 && val + 1 == intervals[index + 1][0])
    {
      intervals[index + 1][0] = val;
    }
    else if (index != -1 && val - 1 == intervals[index][1])
    {
      intervals[index][1] = val;
    }
    else
    {
      intervals.insert(intervals.begin() + (index + 1), {val, val});
    }

    //merge intervals[index] with intervals[index+1]
    if (index != -1 && index + 1 < intervals.size() && intervals[index][1] + 1 == intervals[index + 1][0])
    {
      intervals[index][1] = intervals[index + 1][1];
      intervals.erase(intervals.begin() + index + 1);
    }

    return;
  }

  vector<vector<int>> getIntervals()
  {
    return intervals;
  }
};

void print(vector<vector<int>> &param_2)
{
  for (auto pair : param_2)
  {
    for (auto x : pair)
    {
      cout << x << ',';
    }
  }
  cout << endl;
}

int main()
{
  SummaryRanges *obj = new SummaryRanges();
  obj->addNum(1);
  vector<vector<int>> param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(3);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(7);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(2);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(6);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(9);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(4);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(10);
  param_2 = obj->getIntervals();
  print(param_2);
  obj->addNum(5);
  param_2 = obj->getIntervals();
  print(param_2);
}