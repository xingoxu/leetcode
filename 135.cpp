// Runtime: 28 ms, faster than 86.38% of C++ online submissions for Candy.
// Memory Usage: 10.7 MB, less than 52.10% of C++ online submissions for Candy.
// TODO: I saw there is a constant space resolution

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> result(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1])
                result[i] = result[i - 1] + 1;
        }
        int ret = 0;
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && result[i] < result[i + 1] + 1)
                result[i] = result[i + 1] + 1;
            ret += result[i + 1];
        }
        ret += result[0];
        return ret;
    }
};

int main()
{
    vector<int> x = {1, 2, 2};

    cout << Solution().candy(x) << endl;
    return 0;
}