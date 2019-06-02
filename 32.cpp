#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int longestValidParentheses(string s)
  {
    int length = s.size();
    stack<int> st;
    st.push(-1);
    int count = 0;
    int max = 0;
    for (int i = 0; i < length; i++)
    {
      if (s[i] == '(')
      {
        st.push(i);
      }
      else
      {
        st.pop();
        if (st.empty())
          st.push(i);
        int before = st.top();

        int distance = i - before;
        if (distance > max)
          max = distance;
      }
    }
    return max;
  }
};

int main()
{
  Solution *s = new Solution();

  vector<int> x{3, 2, 2, 3}; // -4 -1 -1 0 1 2
  cout << s->longestValidParentheses("()))))()()(())") << endl;
  return 0;
}
