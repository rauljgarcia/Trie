#ifndef TRIE_H__
#define TRIE_H__

#include <string>
#include <memory>
#include <unordered_map>

using namespace std;

struct trie {
  char c;
  bool isLeaf;
  unordered_map<char, shared_ptr<trie>>links;
};

class Trie {
public:
  Trie();
  //using shared_pointers, so not keeping track of
  // freeing memory, leaving blank
  ~Trie();


  //creates new node with map and defaults isLeaf to false
  shared_ptr<trie>CreateNode();

  void insert(shared_ptr<trie>& root, string str);

private:
  shared_ptr<trie>root;

};

#endif  // TRIE_H__