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

TEST_F(test_Trie, TestEmptyFunc1){
    Trie myobj;
    
    // ASSERT_EQ(2, myobj.EmptyFunc());
}

TEST_F(test_Trie, TestEmptyFunc2){
    Trie myobj;
    
    // ASSERT_EQ(3, myobj.EmptyFunc());
}