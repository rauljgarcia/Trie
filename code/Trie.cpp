#include "Trie.h"
#include <iostream>
using namespace std;

Trie::Trie(){
    root = shared_ptr<trie>(new trie);
    cout<<"root"<<endl;
}

Trie::~Trie(){
}

shared_ptr<trie> Trie::CreateNode(){
    shared_ptr<trie>ret(new trie);
    ret->isLeaf = false;
    return ret;
}

void Trie::insert(string word){
    shared_ptr<trie>curr = root;

    for(int i =0; i<word.size();i++){
        if(curr->children[word[i]] == nullptr){
            curr->children[(word[i])] = CreateNode();
            
            
        }
        curr = (curr->children[word[i]]);
    }
    curr->isLeaf = true;
}

bool Trie::search(string word){
    if(root == nullptr){
        return false;
        }

    shared_ptr<trie>curr = root;
    for(int i = 0; i<word.size(); i++){
        char ch = word.at(i);
        shared_ptr<trie> node = curr->children[(ch)];
        if(node == nullptr){
            cout<<"false"<<endl;
            return false;
        }
        curr = node;
    }
    cout<<"true"<<endl;
    return curr->isLeaf;
}

bool Trie::searchFull(string word){
    if(root == nullptr){
        return false;
    }
    shared_ptr<trie>curr = root;
    
    for(auto it : word){
        if(!curr->children[it]){
            cout<<"false"<<endl;
            return false;
        } else {
            curr = curr->children[it];
        }
    }
    cout<<"true"<<endl;
    return curr->isLeaf;
}

bool Trie::searchSub(shared_ptr<trie>& root, string word){
    // if(root == nullptr){
    //     return false;
    // }

    // shared_ptr<trie>curr = root;
    // for(int i=0; i<word.length(); i++){
    //     curr = curr->children[word[i]];
    //     if(curr == nullptr){
    //         cout<<"false"<<endl;
    //         return false;
    //     }
    // }
    // cout<<"true"<<endl;
    // return true;
}

bool Trie::nodeEmpty(shared_ptr<trie>& curr){
    for(auto it: curr->children){
    if(it.second == nullptr){
        cout<<"true"<<endl;
        return true;
        }
    }
    cout<<"false"<<endl;
    return false;
}

bool Trie::delWordHelper(string& word, shared_ptr<trie>& root){
    if(root == nullptr){
        return false;
        }
    
    if(word.size() == 0){
        if(root->isLeaf == true){
            root->isLeaf = false;
            return true;
        }
        return false;
    }

    string part = word.substr(1);
    if(delWordHelper(part, root->children[ (word[0]) ])){

        if(nodeEmpty(root->children[(word[0])])){
            root->children[(word[0])] = nullptr;
            return true;
            } else { 
                return true;
            }
    } else {   
        return false;
        }
    return false;
}
 
bool Trie::deleteWord(string& word){
    if(delWordHelper(word, root)){
        return true;
        } else {
    return false;
    }
}

