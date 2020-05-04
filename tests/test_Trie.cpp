#include <gtest/gtest.h>
#include "../code/Trie.h"

#include <iostream>
#include <string>

using namespace std;

class test_Trie : public ::testing::Test {
protected:
	// This function runs only once before any TEST_F function
	static void SetUpTestCase(){
	}

	// This function runs after all TEST_F functions have been executed
	static void TearDownTestCase(){
	}
    
	// this function runs before every TEST_F function
	void SetUp() override {
    }

	// this function runs after every TEST_F function
	void TearDown() override {
	}
};

TEST_F(test_Trie, TestInitialization){
    Trie myTri;
	shared_ptr<trie> root= myTri.CreateNode();
	ASSERT_TRUE(root); // expect root to have pointer
	ASSERT_FALSE(root->isLeaf);//expect set to false
	ASSERT_EQ(0, root->letter);
}

TEST_F(test_Trie, TestBuildTrieDifferentStartingLetters){
    Trie myTri;
	shared_ptr<trie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"apple", "blueberry", "cinnamon"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.insert(wordSet[i]);
	}
	myTri.nodeEmpty(root);
	ASSERT_FALSE(myTri.nodeEmpty(root));//indicates root has children	

	ASSERT_TRUE(myTri.searchFull(wordSet[0]));
	ASSERT_TRUE(myTri.searchFull(wordSet[1]));
	ASSERT_TRUE(myTri.searchFull(wordSet[2]));

	string word1 = "donut";
	ASSERT_FALSE(myTri.searchFull(word1));//expected not in trie
	string word2 = "donut";
	myTri.insert(word2);
	ASSERT_TRUE(myTri.searchFull(word2));//expected to in trie, after insert
}

TEST_F(test_Trie, TestBuildTrieSameStartingLetters){
	Trie myTri;
	shared_ptr<trie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"Skyler", "Shane", "Stephanie"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.insert(wordSet[i]);
	}
	myTri.nodeEmpty(root);
	ASSERT_FALSE(myTri.nodeEmpty(root));//indicates root has children	

	ASSERT_TRUE(myTri.searchFull(wordSet[0]));
	ASSERT_TRUE(myTri.searchFull(wordSet[1]));
	ASSERT_TRUE(myTri.searchFull(wordSet[2]));

	string word1 = "steve";//lowercase
	myTri.insert(word1);
	ASSERT_TRUE(myTri.searchFull(word1));
}

TEST_F(test_Trie, TestFullWordSearch){
    Trie myTri;
    shared_ptr<trie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"dell", "apple", "compaq", "hp"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.insert(wordSet[i]);
	}
    ASSERT_TRUE(myTri.searchFull(wordSet[0]));
	ASSERT_TRUE(myTri.searchFull(wordSet[1]));
	ASSERT_TRUE(myTri.searchFull(wordSet[3]));
	
	string word1 = "toshiba";
	ASSERT_FALSE(myTri.searchFull(word1));
	string word2 = "sony";
	ASSERT_FALSE(myTri.searchFull(word2));
	string word3 = "compaq";
	ASSERT_TRUE(myTri.searchFull(word3));
}

TEST_F(test_Trie, TestPrefixSearch){
    Trie myTri;
    shared_ptr<trie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"dell", "apple", "compaq", "hp"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.insert(wordSet[i]);
	}
	
	string word1 = "app";
	ASSERT_FALSE(myTri.searchFull(word1));//full-word search returns false
	ASSERT_TRUE(myTri.searchPrefix(word1));//prefix search returns true - same string
	string word2 = "compa";
	ASSERT_TRUE(myTri.searchPrefix(word2));
	string word3 = "h";
	ASSERT_TRUE(myTri.searchPrefix(word3));
}

TEST_F(test_Trie, TestDeleteWord){
    Trie myTri;
    shared_ptr<trie> root= myTri.CreateNode();
    vector<string> wordSet;
	
	wordSet.insert(wordSet.end(),{"Ford", "BMW", "Tesla", "Subaru"});
    for(int i = 0; i<wordSet.size(); i++){
		myTri.insert(wordSet[i]);
	}
	
	string word1 = "BMW";
	ASSERT_TRUE(myTri.searchFull(word1));//locates string in Trie, before deletion
	myTri.deleteWord(word1);
	ASSERT_FALSE(myTri.searchFull(word1));//returns as removed from Trie, after deletion

	string word2 = "Mercedes";
	ASSERT_FALSE(myTri.deleteWord(word2));//expect false, word doesn't exist in Trie	

	string word3 = "Tesla";
	ASSERT_TRUE(myTri.deleteWord(word3));
}