// Runtime: 216 ms, faster than 5.09% of C++ online submissions for Add and Search Word - Data structure design.
// Memory Usage: 173 MB, less than 5.04% of C++ online submissions for Add and Search Word - Data structure design.
// TODO: optimize preformance
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class WordDictionary
{
  vector<WordDictionary *> x;
  bool hasWord = false;

public:
  /** Initialize your data structure here. */
  WordDictionary()
  {
    x = vector<WordDictionary *>(26);
  }

  /** Adds a word into the data structure. */
  void addWord(string word)
  {
    addWord(word, 0);
  }
  void addWord(string word, int iterator)
  {
    if (iterator == word.size())
    {
      this->hasWord = true;
      return;
    }
    int chara = word[iterator] - 'a';
    auto next = x[chara] ? x[chara] : new WordDictionary();
    next->addWord(word, iterator + 1);
    x[chara] = next;
  }

  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word)
  {
    return search(word, 0);
  }
  bool search(string word, int iterator)
  {
    if (iterator == word.size())
      return hasWord;
    if (word[iterator] == '.')
    {
      for (auto wd : x)
      {
        if (wd && wd->search(word, iterator + 1))
          return true;
      }
      return false;
    }
    int chara = word[iterator] - 'a';
    auto next = x[chara];
    if (next)
      return next->search(word, iterator + 1);
    else
      return false;
  }

  ~WordDictionary()
  {
    for (auto wd : x)
    {
      if (wd != NULL)
        delete wd;
    }
  }
};

int main()
{
  WordDictionary *obj = new WordDictionary();
  obj->addWord("bad");
  obj->addWord("dad");
  obj->addWord("mad");
  cout << obj->search("pad") << endl; // -> false
  cout << obj->search("bad") << endl; // -> true
  cout << obj->search(".ad") << endl; // -> true
  cout << obj->search("b..") << endl; // -> true
  return 0;
}
