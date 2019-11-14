#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
  {
    sort(people.begin(), people.end(), [](vector<int> &peopleA, vector<int> &peopleB) {
      return peopleA[0] == peopleB[0] ? (peopleA[1] < peopleB[1]) : (peopleA[0] < peopleB[0]);
    });
    if (people.size() <= 0)
      return people;

    int preIndex = people.size() - 1, pre = people[preIndex][0], left = preIndex;
    while (true)
    {
      while(left >= 0 && pre == people[left][0])
        --left;
      int count = 0;
      for (int i = left + 1; i <= preIndex; ++i)
      {
        if(people[i][1] > count) {
          people.insert(people.begin() + (preIndex + 1 + (people[i][1] - count)), people[i]);
          people.erase(people.begin() + i);
          --preIndex;
          --i;
        }
        else
          ++count;
      }
      if(left < 0)
        break;
      pre = people[left][0];
      preIndex = left;
    }
    return people;
  }
};

int main()
{
  vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  auto result = Solution().reconstructQueue(people);
  for (auto &pair : result)
  {
    cout << pair[0] << ',' << pair[1] << ' ';
  }
  cout << endl;
  return 0;
}