#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
      int iterator = 0;
      stack<string> st;
      int leftPointer = 0;
      while (iterator < path.size())
      {
        if(path[iterator] == '/') {
          if(leftPointer == iterator || leftPointer == iterator -1) {
            leftPointer = iterator;
            iterator++;
            continue;
          }
          string folderName = path.substr(leftPointer + 1, iterator - 1 - leftPointer);
          if (folderName == "..")
          {
            if(!st.empty())
              st.pop();
          }
          else if (folderName == ".")
          {
          } else {
            st.push(folderName);
          }
          leftPointer = iterator;
        }
        iterator++;
      }
      if (leftPointer != iterator - 1)
      {
        string folderName = path.substr(leftPointer + 1, iterator - 1 - leftPointer);
        if (folderName == "..")
        {
          if(!st.empty())
            st.pop();
        }
        else if (folderName == ".")
        {
        } else {
          st.push(folderName);
        }
      }
      if(st.empty())
        return "/";
      string result;
      while (!st.empty())
      {
        result = "/" + st.top() + result;
        st.pop();
      }

      return result;
    }
};

int main()
{
  Solution s;

  cout << s.simplifyPath("/home/") << endl;
  cout << s.simplifyPath("/../") << endl;
  cout << s.simplifyPath("/home//foo/") << endl;
  cout << s.simplifyPath("/a/./b/../../c/") << endl;
  cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
  cout << s.simplifyPath("/a//b////c/d//././/..") << endl;

  return 0;
}
