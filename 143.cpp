#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        stack<ListNode *> st;
        auto cursor = head;
        int count = 0;
        while (cursor)
        {
            ++count;
            st.push(cursor);
            cursor = cursor->next;
        }

        cursor = head;
        int total = count;
        count = 1;
        while (count <= total / 2)
        {
            auto back = st.top();
            st.pop();
            auto now = cursor;
            cursor = cursor->next;
            now->next = back;
            back->next = cursor;
            ++count;
        }
        if(cursor)
            cursor->next = NULL;
    }
};

int main()
{
    ListNode *head = stringToListNode("[1,2,3,4,5]");

    Solution().reorderList(head);

    cout << listNodeToString(head) << endl;
    return 0;
}