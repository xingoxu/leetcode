// Runtime: 140 ms, faster than 9.20% of C++ online submissions for Implement Trie (Prefix Tree).
// Memory Usage: 224.2 MB, less than 5.10% of C++ online submissions for Implement Trie (Prefix Tree).
// TODO: optimize preformance 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Trie
{
  vector<Trie *> x;
  bool hasWord = false;

public:
  /** Initialize your data structure here. */
  Trie()
  {
    x = vector<Trie *>(26);
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    this->insert(word, 0);
  }
  void insert(string word, int iterator)
  {
    if (iterator == word.size())
    {
      this->hasWord = true;
      return;
    }
    int chara = word[iterator] - 'a';
    auto next = x[chara] ? x[chara] : new Trie();
    next->insert(word, iterator + 1);
    x[chara] = next;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    return search(word, 0);
  }
  bool search(string word, int iterator)
  {
    if (iterator == word.size())
      return hasWord;
    int chara = word[iterator] - 'a';
    auto next = x[chara];
    if (next)
      return next->search(word, iterator + 1);
    else
      return false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    return startsWith(prefix, 0);
  }
  bool startsWith(string prefix, int iterator)
  {
    if (iterator == prefix.size())
      return true;
    int chara = prefix[iterator] - 'a';
    auto next = x[chara];
    if (next)
      return next->startsWith(prefix, iterator + 1);
    else
      return false;
  }
};

int main()
{
  Trie *obj = new Trie();
  obj->insert("apple");
  cout << obj->search("apple") << endl;   // returns true
  cout << obj->search("app") << endl;     // returns false
  cout << obj->startsWith("app") << endl; // returns true
  obj->insert("app");
  cout << obj->search("app") << endl; // returns true
  return 0;
}
