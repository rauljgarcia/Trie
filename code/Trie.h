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
  //full string ends in a leaf
  bool searchFull(string word);

  //interative search for a prefix in the trie
  //prefix starts at root but doesn't nec end in a leaf
  bool searchPrefix(string pre);

  //interative search for a prefix in the trie
  //prefix starts at root returns true if string is exists and ends with leaf
  bool searchSuffix(string sufx);

  //helper function to delWordHelper 
  //checks if a node has no children, returns true
  bool nodeEmpty(shared_ptr<trie>& curr);

  //helper function to deleteWord
  //recurses through the trie from the root by each char in the string
  //if string doesn't end in leaf returns false, as it's not a full string
  bool delWordHelper(string& word, shared_ptr<trie>& root);

  //deletes a given full string in the trie
  bool deleteWord(string& word);
};

#endif  // TRIE_H__