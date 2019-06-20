#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> hashTable;
        int result = 0;
        for (auto &n : nums)
        {
            if (hashTable.find(n) != hashTable.end())
                continue;
            if (hashTable.find(n - 1) == hashTable.end() && hashTable.find(n + 1) == hashTable.end())
            {
                result = max(result, hashTable[n] = 1);
                continue;
            }

            if (hashTable.find(n - 1) == hashTable.end())
            {

                result = max(result, hashTable[n] = hashTable[n + 1] = ++hashTable[n + hashTable[n + 1]]);
                continue;
            }

            if (hashTable.find(n + 1) == hashTable.end())
            {
                result = max(result, hashTable[n] = hashTable[n - 1] = ++hashTable[n - hashTable[n - 1]]);
                continue;
            }

            int left = hashTable[n - 1];
            int right = hashTable[n + 1];
            int length = left + right + 1;
            hashTable[n - left] = length;
            hashTable[n + right] = length;
            hashTable[n] = length;
            result = max(result, length);
        }
        return result;
    }
};

int main()
{
    vector<int> x = {-2, -3, -3, 7, -3, 0, 5, 0, -8, -4, -1, 2};

    cout << Solution().longestConsecutive(x) << endl;
    return 0;
}