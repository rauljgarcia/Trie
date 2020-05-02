#include <string>
#include <vector>
#include <iostream>
#include "../code/Trie.h"


using namespace std;

int main(){
    Trie myTrie;
    
    vector<string> words;
    words.insert(words.end(), {"abc", "cde"});
    shared_ptr<trie>root = nullptr;
    
    for(int i = 0; i<words.size(); i++){
        myTrie.insert(root,words[i]);
    }
    
    myTrie.searchFull(root, "abd");

    myTrie.searchSub(root, "ce");

    if(myTrie.deleteWord(root, "abc")){
        cout<<"abc sucessfully deleted"<<endl;
    } else {
        cout<<"not present"<<endl;
    }
    return 0;
}