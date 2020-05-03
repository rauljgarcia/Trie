#ifndef TRIE_H__
#define TRIE_H__

#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

struct trie {
  char letter = 0;
  bool isLeaf = false;
  unordered_map<char, shared_ptr<trie>>children;
};

class Trie {
private:
  shared_ptr<trie>root;

public:
  Trie();
  //using shared_pointers, so not keeping track of
  // freeing memory, leaving blank
  ~Trie();


  //creates new node with empty map, isLeaf defaults to false
  shared_ptr<trie>CreateNode();

  //iteratively creates new trie from an array of strings
  void insert(string word);

  //iterative search for a full string in the trie
  bool searchFull(string word);

  //iterative search for a substring in the trie
  bool searchSub(shared_ptr<trie>& root, string word);

  bool search(string word);

  //checks if a node has no children, return true
  bool nodeEmpty(shared_ptr<trie>& curr);

  //recursive deletion of a given string in the trie
  bool deleteWord(string& word);

  bool delWordHelper(string& word, shared_ptr<trie>& root);

  shared_ptr<trie>GetRoot();

};

#endif  // TRIE_H__