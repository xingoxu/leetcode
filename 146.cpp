#include <iostream>
#include <unordered_map>
using namespace std;

struct TwoWayListNode
{
  int key;
  int val;
  TwoWayListNode *before;
  TwoWayListNode *next;
  TwoWayListNode(int key, int value) : key(key), val(value), next(NULL), before(NULL) {}
};

class LRUCache
{
  int _capacity;
  int _nowLength = 0;
  unordered_map<int, TwoWayListNode *> cache;
  TwoWayListNode *head = NULL;
  TwoWayListNode *end = NULL;

public:
  LRUCache(int capacity)
  {
    _capacity = capacity;
  }

  int get(int key)
  {
    auto it = cache.find(key);
    if (it == cache.end())
      return -1;
    else
    {
      TwoWayListNode *moveNode = it->second;
      TwoWayListNode *nextNode = moveNode->next;
      TwoWayListNode *beforeNode = moveNode->before;
      if (head == moveNode)
        return moveNode->val;

      beforeNode->next = nextNode;
      if (nextNode)
        nextNode->before = beforeNode;
      else
        end = beforeNode;

      moveNode->before = NULL;
      moveNode->next = head;
      head->before = moveNode;
      head = moveNode;
      return moveNode->val;
    }
  }

  void put(int key, int value)
  {
    if (get(key) != -1)
    {
      cache[key]->val = value;
      return;
    }
    TwoWayListNode *newHead = new TwoWayListNode(key, value);
    newHead->next = head;
    newHead->before = NULL;
    if (head == NULL)
    {
      end = newHead;
    }
    else
    {
      head->before = newHead;
    }
    head = newHead;

    cache[key] = newHead;
    if (++_nowLength > _capacity)
    {

      TwoWayListNode *newEnd = end->before;
      TwoWayListNode *deleteNode = end;
      // cout << "===delete Node ===" << endl;
      // cout << deleteNode->val << endl;
      // cout << "=== end ===" << endl;
      end = newEnd;
      end->next = NULL;
      cache.erase(deleteNode->key);
      delete deleteNode;
      _nowLength = _capacity;
    }
  }
};

int main()
{
  LRUCache *cache = new LRUCache(2 /* capacity */);

  cache->put(2, 1);
  cache->put(3, 2);
  cout << cache->get(3) << endl; // returns 1
  cout << cache->get(2) << endl; // returns 1
  cache->put(4, 3);
  cout << cache->get(2) << endl; // returns -1 (not found)
  cout << cache->get(3) << endl; // returns 3
  cout << cache->get(4) << endl; // returns 1

  return 0;
}