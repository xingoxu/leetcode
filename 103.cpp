#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                })
                    .base(),
                input.end());
}

TreeNode *stringToTreeNode(string input)
{
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size())
    {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true)
    {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ','))
        {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null")
        {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode *root)
{
    if (root == nullptr)
    {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        vector<TreeNode *> thisFloor;
        thisFloor.push_back(root);
        bool isLeftToRight = true;
        while (!thisFloor.empty())
        {
            int thisFloorSize = thisFloor.size();
            vector<int> floorResult(thisFloorSize);

            vector<TreeNode *> nextFloor;
            for (int i = 0; i < thisFloorSize; i++)
            {
                int getIndex = isLeftToRight ? i : (thisFloorSize - i - 1);
                floorResult[i] = thisFloor[getIndex]->val;
                if (thisFloor[i]->left)
                    nextFloor.push_back(thisFloor[i]->left);
                if (thisFloor[i]->right)
                    nextFloor.push_back(thisFloor[i]->right);
            }
            result.push_back(floorResult);
            thisFloor = nextFloor;
            isLeftToRight = !isLeftToRight;
        }
        return result;
    }
};

int main()
{
    TreeNode *root = stringToTreeNode("[3,9,20,null,null,15,7]");

    const auto &result = Solution().zigzagLevelOrder(root);
    for (int i = 0; i < result.size();i++) {
        for (int j = 0; j < result[i].size();j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
