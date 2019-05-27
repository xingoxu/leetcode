#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s)
  {
    stack<char> st;
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
      char ch = s[i];
      if (ch == '(' || ch == '{' || ch == '[')
      {
        st.push(ch);
      }
      else
      {
        if (st.empty()) {
          return false;
        }
        switch (ch)
        {
        case ')':
        {
          if (st.top() == '(')
            st.pop();
          else
            return false;
          break;
        }
        case ']':
        {
          if (st.top() == '[')
            st.pop();
          else
            return false;
          break;
        }
        case '}':
        {
          if (st.top() == '{')
            st.pop();
          else
            return false;
          break;
        }
        }
      }
    }
    return st.empty();
  }
};

int main()
{
  Solution *s = new Solution();

  // vector<int> x{-1,0,1,2,-1,-4}; // -4 -1 -1 0 1 2

  // vector<vector<int>> result = s->removeNthFromEnd(x, -1);

  // for (int i = 0; i < result.size(); i++)
  // {
  //   cout << '[' << result[i][0];
  //   cout << ',' << result[i][1] << ',' << result[i][2] << ',' << result[i][3] << ']' << endl;
  // }

  cout << s->isValid("({[]})") << endl;
  return 0;
}
