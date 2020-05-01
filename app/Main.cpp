#include <iostream>
#include "../code/Trie.h"

using namespace std;

int main(){
    Trie myTrie;
    
    string keys[] = {"abc", "abgl", "cdf"};

    shared_ptr<trie>root = nullptr;
    for(int i = 0; i<3; i++){
        myTrie.insert(root,keys[i]);
    }
    
    // myTrie.insert(root,"abc");
    // myTrie.insert(root,"abgl");
    // myTrie.insert(root,"cdf");
    // myTrie.insert(root,"abcd");
    // myTrie.insert(root,"lmn");

   
    return 0;
}

