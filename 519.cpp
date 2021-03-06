#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  Solution(int n_rows, int n_cols) : n_rows(n_rows), n_cols(n_cols), size(n_rows * n_cols)
  {
    srand(time(nullptr));
  }

  vector<int> flip()
  {
    int id = rand() % size;
    int rid = id;

    --size;

    if (holes.count(id))
    {
      id = holes[id];
    }

    holes[rid] = holes.count(size) ? holes[size] : size;

    return {id / n_cols, id % n_cols};
  }

  void reset()
  {
    holes.clear();
    size = n_rows * n_cols;
  }

private:
  int n_rows;
  int n_cols;
  int size;
  unordered_map<int, int> holes;
};

int main()
{

  return 0;
}