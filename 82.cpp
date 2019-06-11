#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head)
      return head;
    ListNode *pointer = head;
    while(pointer->next != NULL && pointer->next->val == pointer->val) {
      pointer = pointer->next;
    }
    if (pointer == head) {
      ListNode *next = deleteDuplicates(pointer->next);
      head->next = next;
      return head;
    } else
    {
      return deleteDuplicates(pointer->next);
    }
  };
  // try to use iterate but failed
  ListNode* _______deleteDuplicates(ListNode* head) {
    if (!head)
      return head;
    if (!head->next)
      return head;
    if (head->next->next == NULL && head->next->val == head->val)
      return NULL;
    ListNode *pointer = head->next;
    ListNode *oneBefore = head;
    int beforeValue = head->val;

    while (pointer != NULL)
    {
      if(beforeValue != pointer->val) {
        cout << "oneBefore: " << oneBefore->val << " pointer: " << pointer->val << endl;
        cout << "head: " << head->val << endl;

        if (oneBefore->next != pointer && oneBefore != head)
        {
          oneBefore->next = pointer;
          cout << "set" << endl;
        }
        else if (oneBefore->next != pointer && oneBefore == head)
        {
          head = pointer;
          oneBefore = head;
          beforeValue = pointer->val;
          pointer = pointer->next;
          continue;
        }
        beforeValue = pointer->val;
        if (pointer->next != NULL && pointer->next->val != pointer->val)
          oneBefore = oneBefore->next;

      }
      else
      {
      }

      pointer = pointer->next;
    }
    cout << "oneBefore: " << oneBefore->val << endl;
    cout << (pointer == NULL) << endl;
    return head;
  }
};
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}
string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
  ListNode *head = stringToListNode("[1,1,3]");

  ListNode *ret = Solution().deleteDuplicates(head);

  string out = listNodeToString(ret);
  cout << out << endl;

  return 0;
}
