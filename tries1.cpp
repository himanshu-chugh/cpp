#include <iostream>
#include <string>
using namespace std;

// #include "TrieNode.h"
#include <string>
#include <vector>
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

	bool see(TrieNode *root , string pattern){
		if(!root && pattern.size() != 0){
			return false;
		}
		else if(!root && pattern.size() == 0){
			return true;
		}
		else if(root && pattern.size() == 0){
			return true;
		}
		else{
			int index = pattern[0] - 'a';
			return see(root->children[index] , pattern.substr(1));
		}
	}
	bool patternMatching(vector<string> vect, string pattern) {
		// Complete this function
		// Return true or false
        int size = vect.size();
        int len ;
        for(int i = 0 ; i < size; i++){
			len = vect[i].length();
			for(int j = 0; j < len; j++){
				insertWord(root ,vect[i].substr(j));
			}
		}
		
        return see(root ,pattern);
    }
        
};


#include <vector>

int main() {
	Trie t;
    int N;
    cin >> N;
    string pattern;
    vector<string> vect;
    for (int i=0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;
    if (t.patternMatching(vect, pattern)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}