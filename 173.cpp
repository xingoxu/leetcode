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

class BSTIterator
{
public:
    TreeNode *now;
    stack<TreeNode *> parents;
    BSTIterator(TreeNode *root)
    {
        now = root;
        gotoLeft();
    }
    void gotoLeft()
    {
        while (now)
        {
            parents.push(now);
            now = now->left;
        }
    }

    /** @return the next smallest number */
    int next()
    {
        int ret = parents.top()->val;
        now = parents.top()->right;
        parents.pop();
        gotoLeft();
        return ret;
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !parents.empty();
    }
};

int main()
{
    auto root = stringToTreeNode("[7,3,15,null,null,9,20]");
    BSTIterator *iterator = new BSTIterator(root);
    cout << iterator->next() << endl;    // return 3
    cout << iterator->next() << endl;    // return 7
    cout << iterator->hasNext() << endl; // return true
    cout << iterator->next() << endl;    // return 9
    cout << iterator->hasNext() << endl; // return true
    cout << iterator->next() << endl;    // return 15
    cout << iterator->hasNext() << endl; // return true
    cout << iterator->next() << endl;    // return 20
    cout << iterator->hasNext() << endl; // return false
    return 0;
}
