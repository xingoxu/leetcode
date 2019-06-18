// Runtime: 4 ms, faster than 84.46% of C++ online submissions for Binary Tree Postorder Traversal.
// Memory Usage: 9.4 MB, less than 19.47% of C++ online submissions for Binary Tree Postorder Traversal.

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

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *treeRoot)
    {
        vector<int> result;
        TreeNode *root = treeRoot;
        while (root)
        {
            if (root->left)
            {
                TreeNode *cursor = root->left;
                while (cursor->right && cursor->right != root)
                {
                    cursor = cursor->right;
                }
                if (cursor->right)
                {
                    // has cursor
                    cursor->right = NULL;
                    cursor = root->left;
                    vector<int> rightLine;
                    while (cursor)
                    {
                        rightLine.push_back(cursor->val);
                        cursor = cursor->right;
                    }
                    reverse(rightLine.begin(), rightLine.end());
                    result.insert(result.end(), rightLine.begin(), rightLine.end());

                    root = root->right;
                    continue;
                }
                else
                {
                    cursor->right = root;
                }
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }

        TreeNode *cursor = treeRoot;
        vector<int> rightLine;
        while (cursor)
        {
            rightLine.push_back(cursor->val);
            cursor = cursor->right;
        }
        reverse(rightLine.begin(), rightLine.end());
        result.insert(result.end(), rightLine.begin(), rightLine.end());


        return result;
    }
};

int main()
{
    const vector<int> &result = Solution().postorderTraversal(stringToTreeNode("[1,2,3,4,5,null,8,null,null,6,7,9,null]"));
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}
