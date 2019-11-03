// Runtime: 20 ms, faster than 55.19% of C++ online submissions for Mini Parser.
// Memory Usage: 22.3 MB, less than 20.00% of C++ online submissions for Mini Parser.

#include <iostream>
using namespace std;

class NestedInteger
{
public:
  // Constructor initializes an empty nested list.
  NestedInteger();

  // Constructor initializes a single integer.
  NestedInteger(int value);

  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value);

  // Set this NestedInteger to hold a nested list and adds a nested integer to it.
  void add(const NestedInteger &ni);

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class Solution
{
public:
  NestedInteger deserialize(string s)
  {
    int start = 0;
    return deserialize(s, start);
  }
  NestedInteger deserialize(string s, int &start) {
    string number;
    bool isSingleNumber = true;
    int length = s.size();
    NestedInteger ret;
    while (start <= length - 1)
    {
      if(s[start] == '[') {
        isSingleNumber = false;
        int initStart = start++;
        auto child = deserialize(s, start);
        if(child.isInteger()){
          NestedInteger tmp;
          tmp.add(child);
          child = tmp;
        }
        if (initStart != 0)
          ret.add(child);
        else
          ret = child;
        number = "";
      } else if(s[start] == ']') {
        break;
      }
      else if (s[start] == ',')
      {
        if (number == "")
        {
        } else {
          isSingleNumber = false;
          ret.add(NestedInteger(stoi(number)));
          number = "";
        }
      }
      else
      {
        number += s[start];
      }
      ++start;
    }
    if (isSingleNumber && number != "")
      ret = NestedInteger(stoi(number));
    else if(number != "")
      ret.add(NestedInteger(stoi(number)));
    return ret;
  }
};
