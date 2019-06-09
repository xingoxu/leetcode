#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      int iterator = 0;
      int sizeA = a.size();
      int sizeB = b.size();
      string result;

      bool carry = false;
      while (iterator < sizeA && iterator < sizeB)
      {
        int pointerA = sizeA - 1 - iterator;
        int pointerB = sizeB - 1 - iterator;
        if(a[pointerA] != b[pointerB]) {
          result += (carry ? "0" : "1");
        } else {
          result += (carry ? "1" : "0");
          carry = false;
          if (a[pointerA] == '1')
            carry = true;
        }
        iterator++;
      }
      string &iteratingObject = iterator < sizeA ? a : b;
      sizeA = iteratingObject.size();
      while (iterator < sizeA)
      {
        int pointer = sizeA - 1 - iterator;
        if (iteratingObject[pointer] == '0')
        {
          result += (carry ? "1" : "0");
          carry = false;
        } else {
          result += (carry ? "0" : "1");
        }

        iterator++;
      }
      if (carry)
        result += "1";
      reverse(result.begin(), result.end());
      return result;
    }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{4,3,2,1};

  cout << s->addBinary("100", "110010") << endl;

  return 0;
}
