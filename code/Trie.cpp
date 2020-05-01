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
        if(curr->links.find(it) == curr->links.end()){
            shared_ptr<trie> node = CreateNode();
            node->c = it;
            cout<<node->c<<endl;
            curr->links[it] = node;
        }
        curr = curr->links[it];
    }
    curr->isLeaf = true;
    cout<<"leaf"<<endl;
    return;
}