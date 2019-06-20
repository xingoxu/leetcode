// Runtime: 28 ms, faster than 92.12% of C++ online submissions for Binary Tree Maximum Path Sum.
// Memory Usage: 25.1 MB, less than 57.70% of C++ online submissions for Binary Tree Maximum Path Sum.

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
    int _maxPathSum(TreeNode *root)
    {
        int left = -214748, right = -214748;
        if (root->left)
        {
            left = _maxPathSum(root->left);
        }
        if (root->right)
        {
            right = _maxPathSum(root->right);
        }
        int result = max(root->val, left + root->val);
        result = max(result, right + root->val);
        if (left > result)
            maxResult = max(maxResult, left);
        if (right > result)
            maxResult = max(maxResult, right);
        if(left + right + root->val > result) {
            maxResult = max(maxResult, left + right + root->val);
        }
        return result;
    }
    int maxResult = -214748;
    int maxPathSum(TreeNode *root)
    {
        int result = _maxPathSum(root);
        result = max(result, maxResult);
        return result;
    }
};

int main()
{
    const auto &result = Solution().maxPathSum(stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,null,1]"));

    cout << result << endl;

    return 0;
}
