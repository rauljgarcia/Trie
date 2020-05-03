#include <string>
#include <vector>
#include <iostream>
#include "../code/Trie.h"


using namespace std;

int main(){
    Trie myTrie;
    
    // string strings;
    // vector<string> words;
    // cout<<"Enter words into the Trie (separated by commas): "<<endl;
    // cin>>strings;
    // words.insert(words.end(), {strings});
    // words.insert(words.end(), {"hello", "goodbye", "apple", "banana"});
    vector<string> words;
    words.insert(words.end(), {"rabbit", "day", "radio"});
    for(int i = 0; i<words.size(); i++){
        myTrie.insert(words[i]);
    }
    
    myTrie.search("rab");

    // myTrie.searchFull("abbit");

    // myTrie.searchSub(root, "da");
    string word = "ra";
    if(myTrie.deleteWord(word)){
        cout<<word<<" has sucessfully been deleted from Trie"<<endl;
    } else {
        cout<<word<<" is not present in Trie"<<endl;
    }

    return 0;
}