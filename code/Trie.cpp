#include "Trie.h"
#include <iostream>
using namespace std;

Trie::Trie(){
    // shared_ptr<node>root = shared_ptr<node>(new node);
}

Trie::~Trie(){
}

shared_ptr<trie> Trie::CreateNode(){
    shared_ptr<trie>ret(new trie);
    ret->isLeaf = false;
    return ret;
}

void Trie::insert(shared_ptr<trie>& root, string word){
    if(root == nullptr){
        root = CreateNode();
        cout<<"root"<<endl;
    }

    shared_ptr<trie>curr = root;
    for(auto it: word){
        if(curr->children.find(it) == curr->children.end()){
            shared_ptr<trie> node = CreateNode();
            node->letter = it;
            cout<<"new node char = "<<node->letter<<" ->"<<endl;
            curr->children[it] = node;
        }
        curr = curr->children[it];
    }
    curr->isLeaf = true;
    cout<<"leaf"<<endl;
    return;
}

bool Trie::searchFull(shared_ptr<trie>& root, string word){
    if(root == nullptr){
        return false;
    }

    shared_ptr<trie>curr = root;
    for(int i=0; i<word.length(); i++){
        curr = curr->children[word[i]];
        if(curr == nullptr){
            cout<<"false"<<endl;
            return false;
        }
    }
    if (curr->isLeaf){
        cout<<"true"<<endl;
        return true;
    }
}

bool Trie::searchSub(shared_ptr<trie>& root, string word){
    if(root == nullptr){
        return false;
    }

    shared_ptr<trie>curr = root;
    for(int i=0; i<word.length(); i++){
        curr = curr->children[word[i]];
        if(curr == nullptr){
            cout<<"false"<<endl;
            return false;
        }
    }
    cout<<"true"<<endl;
    return true;
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

bool Trie::delWordHelper(shared_ptr<trie>& root, string& word){
    if(root == nullptr)
        return false;
    
    if(word.size() == 0){
        if(root->isLeaf == true){
            root->isLeaf = false;
            return true;
        }
        return false;
    }

    string part = word.substr(1);
    if(delWordHelper(root->children[ (word[0]) ], part)){

        if(nodeEmpty(root->children[ (word[0]) ])){
            root->children[(word[0])] = nullptr;
            return true;
                } else {
            return true;
        }
    }   
    return false;
}
 
bool Trie::deleteWord(shared_ptr<trie>&root, string word){
    if(delWordHelper(root, word))
        return true;
    return false;
}


