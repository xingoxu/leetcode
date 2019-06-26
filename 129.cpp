// Runtime: 8 ms, faster than 55.93% of C++ online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 16.2 MB, less than 5.05% of C++ online submissions for Sum Root to Leaf Numbers.
// TODO: find a efficient solution

#include <iostream>
#include <vector>
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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        const auto &resultArray = _sumNumbers(root);
        for (int i = 0; i < resultArray.size();i++) {
            sum += stoi(resultArray[i]);
        }
        return sum;
    }
    vector<string> _sumNumbers(TreeNode *root) {
        vector<string> left, right;
        if (root->left)
        {
            left = _sumNumbers(root->left);
        }
        if (root->right)
        {
            right = _sumNumbers(root->right);
        }
        for (int i = 0; i < left.size();i++) {
            left[i] = to_string(root->val) + left[i];
        }
        for (int i = 0; i < right.size();i++) {
            left.push_back(to_string(root->val) + right[i]);
        }
        if(left.size() == 0)
            return {to_string(root->val)};
        return left;
    }
};

int main()
{
    cout << Solution().sumNumbers(stringToTreeNode("[1,2,3]")) << endl;
    return 0;
}
