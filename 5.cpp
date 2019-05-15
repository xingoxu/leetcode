#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int stringLength = s.size();
      if (stringLength == 0 || stringLength == 1) {
        return s;
      }
      if (stringLength == 2) {
        if (s[0] == s[1])
          return s;
        else
          return s[0] + "";
      }
      string answer1 = getSingleLongestPalindrome(s.substr(0, stringLength - 1));
      string answer2 = getSingleLongestPalindrome(s.substr(1));
      string answer3 = getSingleLongestPalindrome(s);

      string max = findMax(answer1, answer2, answer3);
      if (max.size() > (stringLength % 2 == 0 ? stringLength / 2 : stringLength / 2 + 1))
      {
        return max;
      } else {
        string left = longestPalindrome(s.substr(0, stringLength % 2 == 0 ? stringLength - 2 : (stringLength - 2 + 1)));
        string right = longestPalindrome(s.substr(2));
        return findMax(max, left, right);
      }
    }
    string getSingleLongestPalindrome(string s) {
      int stringLength = s.size();
      int left = stringLength / 2 - 1;
      int right = stringLength % 2 == 0 ? stringLength / 2 : stringLength / 2 + 1;

      while (left >= 0 && right < stringLength) {
        if (s[left] != s[right]) {
          return s.substr(left + 1, right - left - 1);
        }
        left--;
        right++;
      }
      return s;
    }
    string findMax(string a, string b, string c)
    {
      int sizeA = a.size();
      int sizeB = b.size();
      int sizeC = c.size();
      return ((sizeA > sizeB ? sizeA : sizeB) > sizeC) ? (sizeA > sizeB ? a : b) : c;
    }
};

int main()
{
  Solution *s = new Solution();
  cout << s->longestPalindrome("civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth") << endl;
  return 0;
}