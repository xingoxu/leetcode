#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        map<char, int> symbol;
        symbol['I'] = 1;
        symbol['V'] = 5;
        symbol['X'] = 10;
        symbol['L'] = 50;
        symbol['C'] = 100;
        symbol['D'] = 500;
        symbol['M'] = 1000;

        int length = s.size();
        int sum = 0;
        for (int i = 0; i < length; i++)
        {
            if (i == (length - 1))
            {
                sum += symbol[s[i]];
                continue;
            }
            int first = symbol[s[i]];
            int second = symbol[s[i + 1]];
            if (second > first) {
                sum = sum + second - first;
                i++;
            } else {
                sum += first;
            }
        }
        return sum;
    }
};

int main()
{
    Solution *s = new Solution();

    cout << s->romanToInt("LVIII") << endl;
    return 0;
}