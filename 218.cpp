// Runtime: 32 ms, faster than 88.09% of C++ online submissions for The Skyline Problem.
// Memory Usage: 14.8 MB, less than 53.94% of C++ online submissions for The Skyline Problem.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

struct SkylineNode
{
  int from;
  int to;
  int height;
  SkylineNode *next;
  SkylineNode(int _from, int _to, int _height) : from(_from), to(_to), height(_height), next(NULL) {}
};

class Solution
{
  // return cursor
  SkylineNode *processRight(int from, int to, int height, SkylineNode *&node)
  {
    if (node == NULL)
    {
      node = new SkylineNode(from, to, height);
      return node;
    }
    if(from >= node->to) {
      return processRight(from, to, height, node->next);
    }

    if(from < node->from) {
      SkylineNode *duplicate = node;
      SkylineNode *newSkylineNode = new SkylineNode(from, to, height);
      newSkylineNode->next = duplicate;
      if(to <= node->from) {
        node = newSkylineNode;
        return node;
      }
      else
      {
        newSkylineNode->to = node->from;
        node = newSkylineNode;
        processRight(newSkylineNode->to, to, height, node->next);
        return node;
      }
    }
    if (to <= node->to)
    {
      if (height <= node->height)
      {
        return node;
      }
      else
      {
        SkylineNode *nextNextSkylineNode = new SkylineNode(to, node->to, node->height);
        nextNextSkylineNode->next = node->next;
        node->to = from;
        SkylineNode *newSkylineNode = new SkylineNode(from, to, height);
        newSkylineNode->next = nextNextSkylineNode;
        node->next = newSkylineNode;
        return newSkylineNode;
      }
    }

    if (height <= node->height)
    {
      processRight(node->to, to, height, node->next);
      return node;
    }
    else
    {
      node->to = from;
      return processRight(from, to, height, node->next);
    }
  } 
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
  {
    SkylineNode *head = NULL;
    SkylineNode *cursor = NULL;
    for (int i = 0; i < buildings.size(); ++i)
    {
      auto &build = buildings[i];
      auto &from = build[0];
      auto &to = build[1];
      auto &height = build[2];

      if(!head) {
        cursor = processRight(from, to, height, head);
      } else {
        cursor = processRight(from, to, height, cursor);
      }
    }

    vector<vector<int>> result;
    int before = 0, beforeHeight = 0;
    while (head)
    {
      if (head->from < head->to)
      {
        if (head->from > before && before != 0)
        {
          result.push_back({before, 0});
        } else if (head->from == before && head->height == beforeHeight) {
          before = head->to;
          head = head->next;
          continue;
        }
        result.push_back({head->from, head->height});
        before = head->to;
        beforeHeight = head->height;
      }
      head = head->next;
    }
    if (before != 0)
      result.push_back({before, 0});
    return result;
  }
};

int main(){
  vector<vector<int>> buildings{
      {6765, 184288, 53874},
      {13769, 607194, 451649},
      {43325, 568099, 982005},
      {47356, 933141, 123943},
      {59810, 561434, 119381},
      {75382, 594625, 738524},
      {111895, 617442, 587304},
      {143767, 869128, 471633},
      {195676, 285251, 107127},
      {218793, 772827, 229219},
      {316837, 802148, 899966},
      {329669, 790525, 416754},
      {364886, 882642, 535852},
      {368825, 651379, 6209},
      {382318, 992082, 300642},
      {397203, 478094, 436894},
      {436174, 442141, 612149},
      {502967, 704582, 918199},
      {503084, 561197, 625737},
      {533311, 958802, 705998},
      {565945, 674881, 149834},
      {615397, 704261, 746064},
      {624917, 909316, 831007},
      {788731, 924868, 633726},
      {791965, 912123, 438310}};

  const auto &result = Solution().getSkyline(buildings);
  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}
