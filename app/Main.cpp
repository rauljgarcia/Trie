#include <string>
#include <vector>
#include <iostream>
#include "../code/Trie.h"


using namespace std;

int main(){
    Trie myTrie;
    
    vector<string> words;
    cout<<"Enter words into the Trie: "<<endl;
    words.insert(words.end(), {"rabbit", "day", "radio"});
    
    for(int i = 0; i<words.size(); i++){
        myTrie.insert(words[i]);
    }
    
    myTrie.search("ay");

    myTrie.searchFull("abbit");

    // myTrie.searchSub(root, "da");
    string word = "ra";
    if(myTrie.deleteWord(word)){
        cout<<word<<" has sucessfully been deleted from Trie"<<endl;
    } else {
        cout<<word<<" is not present in Trie"<<endl;
    }

    return 0;
}