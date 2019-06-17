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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(vector<int>& inorder, vector<int>& postorder,int inorderLeft, int inorderRight,int postorderLeft, int postorderRight)
    {
        if (postorderRight < postorderLeft || inorderRight < inorderLeft)
        {
            return NULL;
        }
        if (postorderLeft == postorderRight)
        {
            return new TreeNode(postorder[postorderLeft]);
        }

        int root = postorder[postorderRight];
        int leftChildInorderRight = inorderLeft;
        for (int i = inorderLeft; i <= inorderRight; i++)
        {
            if (inorder[i] == root)
            {
                leftChildInorderRight = i - 1;
                break;
            }
        }

        int leftChildPostorderRight = leftChildInorderRight - inorderLeft + postorderLeft;
        int rightChildPostorderLeft = leftChildPostorderRight + 1;

        TreeNode *leftChild = buildTree(inorder, postorder, inorderLeft, leftChildInorderRight, postorderLeft, leftChildPostorderRight);
        TreeNode *rightChild = buildTree(inorder, postorder, leftChildInorderRight + 2, inorderRight, rightChildPostorderLeft, postorderRight - 1);

        TreeNode *result = new TreeNode(root);
        result->left = leftChild;
        result->right = rightChild;
        return result;
    }
};

int main()
{
    vector<int> inorder = {2, 1};
    vector<int> postorder = {1, 2};

    const auto &result = Solution().buildTree(inorder, postorder);

    cout << treeNodeToString(result) << endl;

    return 0;
}
