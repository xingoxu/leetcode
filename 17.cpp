#include <iostream>
#include <vector>
using namespace std;

// test cases may occurs some problem
class Solution {
public:
  vector<string> letterCombinations(string digits)
  {
    string numberpad[] = {
      "",
      "",
      "abc",
      "def",
      "ghi",
      "jkl",
      "mno",
      "pqrs",
      "tuv",
      "wxyz"
    };
    if (digits == "")
      return {};

    if (digits.size() == 1)
    {

      string ch = numberpad[atoi(&digits[0])];
      vector<string> result;
      for (int i = 0; i < ch.size(); i++)
      {
        string tmp(1, ch[i]);
        result.push_back(tmp);
      }

      return result;
    }
    int digitLength = digits.size();
    string left = digits.substr(0, digitLength / 2);
    string right = digits.substr(digitLength / 2);
    vector<string> leftArray = letterCombinations(left);
    vector<string> rightArray = letterCombinations(right);
    int leftLength = leftArray.size();
    int rightLength = rightArray.size();
    vector<string> result;
    for (int i = 0; i < leftLength; i++)
    {
      for (int j = 0; j < rightLength; j++)
      {
        result.push_back(leftArray[i] + rightArray[j]);
      }
    }
    return result;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<string> result = s->letterCombinations("23");

  int length = result.size();

  for (int i = 0; i < length;i++) {
    cout << result[i] << endl;
  }

  // cout << s->letterCombinations("23") << endl;
  return 0;
}