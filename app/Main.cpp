#include <string>
#include <vector>
#include <iostream>
#include "../code/Trie.h"


using namespace std;

int main(){
    Trie myTrie;
    
    //user-input string insertion in collpased code below (inprogress)
    // string strings;
    // vector<string> words;
    // cout<<"Enter words into the Trie (separated by commas): "<<endl;
    // cin>>strings;
    // words.insert(words.end(), {strings});
    // words.insert(words.end(), {"hello", "goodbye", "apple", "banana"});

    //Insert function, builds trie with strings
    vector<string> words;
    words.insert(words.end(), {"duck"});
    for(int i = 0; i<words.size(); i++){
        myTrie.insert(words[i]);
    }
    
    //Adding word to existing trie
    // string word = "cat";
    // myTrie.insert(word);

    //Adding similar word to existing trie
    // string word2 = "cathy";
    // myTrie.insert(word2);

    //Adding same word capitalized to existing trie
    // string word3 = "Cathy";
    // myTrie.insert(word3);

    //Full string search function, returns if word was found in the trie or not
    // string wordSearch = "turtle";
    // if(myTrie.searchFull(wordSearch)== true){
    //     cout<<"The string '"<<wordSearch<<"' was found in the Trie"<<endl;
    //     } else {
    //         cout<<"The string '"<<wordSearch<<"' was not found in the Trie"<<endl;
    //     };
    
    // Prefix search function, returns if prefix is in the trie or not
    // string pre = "boy";
    // if(myTrie.searchPrefix(pre)== true){
    //     cout<<"The prefix '"<<pre<<"' was found in Trie"<<endl;
    //     } else {
    //         cout<<"The prefix '"<<pre<<"' was not found in Trie"<<endl;
    //     };

    
    // Delete string function, returns if the string was deleted from trie or does not exist
    // string deletionWord = "Cathy";
    // if(myTrie.deleteWord(deletionWord)){
    //     cout<<"The string '"<<deletionWord<<"' has been sucessfully deleted from Trie"<<endl;
    // } else {
    //     cout<<"The string '"<<deletionWord<<"' was not found in Trie"<<endl;
    // }
    return 0;
}