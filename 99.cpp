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
    void recoverTree(TreeNode *root)
    {
        morrisTravelRecoverTree(root);
    }
    void morrisTravelRecoverTree(TreeNode *root)
    {
        TreeNode *cur = root, *pre = NULL, *threadingNode = NULL;
        TreeNode *first = NULL, *second = NULL;
        while (cur)
        {
            if (cur->left)
            {
                threadingNode = cur->left;
                while (threadingNode->right && threadingNode->right != cur)
                {
                    threadingNode = threadingNode->right;
                }
                if (threadingNode->right)
                {
                    // do swap here;
                    if (pre != NULL && pre->val > cur->val)
                    {
                        if (first)
                            second = cur;
                        else
                        {
                            first = pre;
                            second = cur;
                        }
                    }
                    pre = cur;
                    cur = cur->right;
                    threadingNode->right = NULL;
                }
                else
                {
                    threadingNode->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                // the most left node
                // do swap here;
                if (pre != NULL && pre->val > cur->val)
                {
                    if (first)
                        second = cur;
                    else
                    {
                        first = pre;
                        second = cur;
                    }
                }
                pre = cur;
                cur = cur->right;
            }
        }
        if (first && second)
            swap(&first->val, &second->val);
    }
    TreeNode *TreeRoot;
    // still use log(n) space
    void _recoverTree(TreeNode *root)
    {
        if (root->left)
        {
            _recoverTree(root->left);
        }
        TreeNode *smallest = findSmallestNodeRighterThan_StackVer(root);
        if (smallest != root)
        {
            swap(&root->val, &smallest->val);
        }
        if (root->right)
        {
            _recoverTree(root->right);
        }
    }
    TreeNode *findSmallestNodeRighterThan_StackVer(TreeNode *node)
    {
        stack<TreeNode *> findStack;
        TreeNode *pointer = TreeRoot;
        TreeNode *smallest = NULL;
        while (pointer || !findStack.empty())
        {
            if (pointer)
            {
                findStack.push(pointer);
                pointer = pointer->right;
            }
            else
            {
                TreeNode *nodeNow = findStack.top();
                if (smallest)
                {
                    if (smallest->val > nodeNow->val)
                        smallest = nodeNow;
                }
                else
                {
                    smallest = nodeNow;
                }
                if (nodeNow == node)
                    return smallest;
                pointer = findStack.top()->left;
                findStack.pop();
            }
        }
        return smallest;
    }
    void uncorrect_recoverTree(TreeNode *root)
    {
        if (root->left)
        {
            root->val = recoverLeft(root->left, root->val);
        }
        if (root->right)
        {
            root->val = recoverRight(root->right, root->val);
        }
    }
    int recoverLeft(TreeNode *root, int parentVal)
    {
        int minVal, maxVal;
        if (root->val < parentVal)
        {
            minVal = root->val;
            maxVal = parentVal;
        }
        else
        {
            minVal = parentVal;
            maxVal = root->val;
        }
        if (root->left)
        {
            minVal = recoverLeft(root->left, minVal);
            if (minVal > maxVal)
            {
                swap(&minVal, &maxVal);
            }
        }
        cout << minVal << ' ' << maxVal << endl;
        if (root->right)
        {
            minVal = recoverRight(root->right, minVal);
            if (minVal > maxVal)
            {
                swap(&minVal, &maxVal);
            }
        }
        cout << minVal << ' ' << maxVal << endl;
        root->val = minVal;
        return maxVal;
    }
    int recoverRight(TreeNode *root, int parentVal)
    {
        int minVal, maxVal;
        if (root->val < parentVal)
        {
            minVal = root->val;
            maxVal = parentVal;
        }
        else
        {
            minVal = parentVal;
            maxVal = root->val;
        }
        if (root->left)
        {
            maxVal = recoverLeft(root->left, maxVal);
            if (minVal > maxVal)
            {
                swap(&minVal, &maxVal);
            }
        }
        if (root->right)
        {
            maxVal = recoverRight(root->right, maxVal);
            if (minVal > maxVal)
            {
                swap(&minVal, &maxVal);
            }
        }
        root->val = maxVal;
        return minVal;
    }

    void swap(int *x, int *y)
    {
        int temp;
        if (*x != *y)
        {
            temp = *x;
            *x = *y;
            *y = temp;
        }
    }
};

int main()
{
    TreeNode *root = stringToTreeNode("[1,3,null,null,2]");
    Solution().recoverTree(root);

    cout << treeNodeToString(root) << endl;
    return 0;
}
