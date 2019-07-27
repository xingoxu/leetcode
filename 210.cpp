
// Runtime: 48 ms, faster than 10.14% of C++ online submissions for Course Schedule II.
// Memory Usage: 152.4 MB, less than 5.10% of C++ online submissions for Course Schedule II.
// A Naive Solution, TODO: find a faster solution

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct twowayLink{
  unordered_set<twowayLink*> parents;
  vector<twowayLink *> children;
  int num;
  twowayLink(int x) { num = x; };
};

class Solution
{
  vector<twowayLink *> map;
  void addToTop(int course, int require, int maxSize)
  {
    auto courseNode = map[course];
    auto requireNode = map[require];
    if (!courseNode)
    {
      courseNode = new twowayLink(course);
      courseNode->parents = unordered_set<twowayLink *>(maxSize);
      map[course] = courseNode;
    }
    if (!requireNode)
    {
      requireNode = new twowayLink(require);
      requireNode->parents = unordered_set<twowayLink *>(maxSize);
      map[require] = requireNode;
    }


    courseNode->parents.insert(requireNode);
    requireNode->children.push_back(courseNode);
  }

public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
  {
    map = vector<twowayLink *>(numCourses);

    for (auto &prerequisite : prerequisites)
    {
      addToTop(prerequisite[0], prerequisite[1], numCourses);
    }
    queue<twowayLink*> q;
    for (int i = map.size() - 1; i >= 0;i--)
    {
      auto course = map[i];
      if (course == NULL)
      {
        course = new twowayLink(i);
        map[i] = course;
      }
      if(course->parents.empty()){
        q.push(course);
      }
    }

    int i = 0;
    vector<int> ret(numCourses);
    while (!q.empty())
    {
      auto current = q.front();
      q.pop();
      ret[i] = current->num;
      ++i;
      for (auto child : current->children)
      {
        child->parents.erase(current);
        if (child->parents.empty())
          q.push(child);
      }
    }
    if(i != numCourses)
      return {};

    return ret;
  }
  ~Solution()
  {
    for (auto x : map)
    {
      delete x;
    }
  }
};

int main()
{
  vector<vector<int>> pre{{1, 0}, {2, 0}, {3, 1}, {3, 2}};

  const auto &ret = Solution().findOrder(4, pre);
  for (int i = 0; i < ret.size();i++) {
    cout << ret[i] << ' ';
  }
  cout << endl;

  return 0;
}
