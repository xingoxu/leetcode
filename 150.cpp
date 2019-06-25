#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    if (tokens.size() == 0)
      return 0;

    int left = 0, end = tokens.size() - 1;
    stack<int> st;
    while (left <= end) {
      string now = tokens[left];
      char firstChar = now[0];
      if (now.size() == 1 && (firstChar < '0' || firstChar > '9'))
      {
        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();
        st.push(evaluate(a, b, now));
      } else {
        st.push(stoi(now));
      }
      left++;
    }
    return st.top();
  }
  int evaluate(int a, int b, string _operator)
  {
    switch (_operator[0])
    {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '*':
      return a * b;
    case '/':
      return a / b;
    }
    // won't be here
    return 0;
  }
};

int main()
{
  vector<string> tokens{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
  cout << Solution().evalRPN(tokens) << endl;
  return 0;
}
