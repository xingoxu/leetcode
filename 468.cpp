// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Validate IP Address.
// Memory Usage: 8.5 MB, less than 50.00% of C++ online submissions for Validate IP Address.

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
  bool validateIPv4Number(string number)
  {
    if (number == "")
      return false;
    if (number.size() == 1)
      return true;
    if (number.size() > 1 && number[0] == '0')
      return false;
    if(number.size() >=4)
      return false;
    return stoi(number) <= 255;
  }
  bool isIPv4(string IP)
  {
    string numberPart = "";
    int dot = 0;
    for (auto &ch : IP)
    {
      if (ch >= '0' && ch <= '9')
      {
        numberPart += ch;
      }
      else if (ch == '.')
      {
        if (!validateIPv4Number(numberPart))
          return false;
        numberPart = "";
        ++dot;
      }
      else
      {
        return false;
      }
      if (dot > 3)
        return false;
    }
    return dot == 3 && validateIPv4Number(numberPart);
  }
  bool validateIPv6Number(string number)
  {
    if (number == "")
      return false;
    if(number.size() <= 4)
      return true;
    return false;
  }
  bool isIPv6(string IP)
  {
    string numberPart;
    int mark = 0;
    for (auto &ch : IP)
    {
      if ((ch >= '0' && ch <= '9') ||
          (ch >= 'A' && ch <= 'F') ||
          (ch >= 'a' && ch <= 'f'))
      {
        numberPart += ch;
      }
      else if (ch == ':')
      {
        if (!validateIPv6Number(numberPart))
          return false;
        numberPart = "";
        ++mark;
      }
      else
      {
        return false;
      }
      if (mark > 7)
        return false;
    }
    return mark == 7 && validateIPv6Number(numberPart);
  }

public:
  string validIPAddress(string IP)
  {
    if (isIPv4(IP))
      return "IPv4";
    if (isIPv6(IP))
      return "IPv6";
    return "Neither";
  }
};

int main()
{
  cout << Solution().validIPAddress("2001:0db8:85a3::8A2E:0370:7334") << endl;
  return 0;
}