// Runtime: 12 ms, faster than 95.14% of C++ online submissions for UTF-8 Validation.
// Memory Usage: 9.6 MB, less than 75.00% of C++ online submissions for UTF-8 Validation.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
  int getLength(vector<int> &data, int index)
  {
    int count = 0;
    for (int i = 7; i >= 0; --i)
    {
      if ((data[index] & (1 << i)) == 0)
        break;
      ++count;
    }
    if (count == 1 || count >= 5)
      return 0;
    if (count == 0)
      return 1;
    return count;
  }
  bool validateUTF8(vector<int> &data, int start, int length)
  {
    if (length == 1)
      return true;
    for (int i = 1; i < length; ++i)
    {
      if (((data[i + start] & (1 << 7))) == 0)
        return false;
      if (((data[i + start] & (1 << 6))) != 0)
        return false;
    }
    return true;
  }

public:
  bool validUtf8(vector<int> &data)
  {
    int index = 0;
    while (index < data.size())
    {
      int length = getLength(data, index);
      if (length == 0)
        return false;
      if (index + length > data.size() || !validateUTF8(data, index, length))
        return false;
      index = index + length;
    }

    return true;
  }
};

int main()
{
  vector<int> input = {250,145,145,145,145};
  cout << Solution().validUtf8(input) << endl;
  return 0;
}