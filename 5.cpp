#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
  map<string, int*> mMap;
  string longestPalindrome(string s)
  {
    mMap.clear();
    int *x = _longestPalindrome(s, 0, s.size() - 1);
    // cout << '[' << x[0] << ", " << x[1] << ']' << endl;
    // cout << mMap. << endl;
    if (x[1] < x[0])
    {
      return "";
    }
    else
    {
      return s.substr(x[0], x[1] - x[0] + 1);
    }
  }
  int *_init2ElementArray(int a, int b) {
    int* returnArr = new int[2];
    returnArr[0] = a;
    returnArr[1] = b;
    return returnArr;
  }
  int *_longestPalindrome(string s, int start, int end)
  {
    // cout << '[' << start << ", " << end << ']' << endl;
    if (start > end)
    {
      return _init2ElementArray(0, 0);
    }
    int stringLength = end - start + 1;
    if (stringLength <= 1)
    {
      return _init2ElementArray(start, end);
    }
    ostringstream oss;
    oss << start << '-' << end;
    string mapKey = oss.str();
    if (mMap[mapKey])
    {
      return mMap[mapKey];
    }

    int *answer1 = getSingleLongestPalindrome(s, start, end - 1);
    int *answer2 = getSingleLongestPalindrome(s, start + 1, end);
    int *answer3 = getSingleLongestPalindrome(s, start, end);

    int *max = findMax(answer1, answer2, answer3);
    int maxSize = max[1] - max[0];
    if (maxSize >= stringLength - 1) {
      mMap[mapKey] = max;
      return max;
    }

    int *left = _longestPalindrome(s, start, stringLength % 2 == 0 ? end - 2 : (end - 2 + 1));
    int *right = _longestPalindrome(s, start + 2, end);
    max = findMax(max, left, right);
    // cout << "max: " << max[0] << ' ' << max[1] << endl;
    mMap[mapKey] = max;
    return max;
  }

  int *getSingleLongestPalindrome(string s, int originLeft, int originRight)
  {
    int stringLength = originRight - originLeft + 1;
    int left = stringLength % 2 == 0 ? stringLength / 2 - 1 : stringLength / 2;
    left = originLeft + left;
    int right = stringLength % 2 == 0 ? stringLength / 2 : ((stringLength / 2) + 1);
    right = originRight + 1 - right;

    while (left >= originLeft && right <= originRight)
    {
      if (s[left] != s[right])
      {
        return _init2ElementArray(left + 1, right - 1);
      }
      left--;
      right++;
    }
    return _init2ElementArray(originLeft, originRight);
  }
  int *findMax(int a[2], int b[2], int c[2])
  {
    int sizeA = a[1] - a[0];
    int sizeB = b[1] - b[0];
    int sizeC = c[1] - c[0];
    return ((sizeA > sizeB ? sizeA : sizeB) > sizeC) ? (sizeA > sizeB ? a : b) : c;
  }
};

int main()
{
  Solution *s = new Solution();
  cout << s->longestPalindrome("lcnvoknqgejxbfhijmxglisfzjwbtvhodwummdqeggzfczmetrdnoetmcydwddmtubcqmdjwnpzdqcdhplxtezctvgnpobnnscrmeqkwgiedhzsvskrxwfyklynkplbgefjbyhlgmkkfpwngdkvwmbdskvagkcfsidrdgwgmnqjtdbtltzwxaokrvbxqqqhljszmefsyewwggylpugmdmemvcnlugipqdjnriythsanfdxpvbatsnatmlusspqizgknabhnqayeuzflkuysqyhfxojhfponsndytvjpbzlbfzjhmwoxcbwvhnvnzwmkhjxvuszgtqhctbqsxnasnhrusodeqmzrlcsrafghbqjpyklaaqximcjmpsxpzbyxqvpexytrhwhmrkuybtvqhwxdqhsnbecpfiudaqpzsvfaywvkhargputojdxonvlprzwvrjlmvqmrlftzbytqdusgeupuofhgonqoyffhmartpcbgybshllnjaapaixdbbljvjomdrrgfeqhwffcknmcqbhvulwiwmsxntropqzefwboozphjectnudtvzzlcmeruszqxvjgikcpfclnrayokxsqxpicfkvaerljmxchwcmxhtbwitsexfqowsflgzzeynuzhtzdaixhjtnielbablmckqzcccalpuyahwowqpcskjencokprybrpmpdnswslpunohafvminfolekdleusuaeiatdqsoatputmymqvxjqpikumgmxaxidlrlfmrhpkzmnxjtvdnopcgsiedvtfkltvplfcfflmwyqffktsmpezbxlnjegdlrcubwqvhxdammpkwkycrqtegepyxtohspeasrdtinjhbesilsvffnzznltsspjwuogdyzvanalohmzrywdwqqcukjceothydlgtocukc") << endl;
  return 0;
}