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
    
    void print(TrieNode* root , string pattern){
        if(root){
            for(int i = 0 ; i < 26; i++){
                print(root->children[i] , pattern + root->data);
            }
            if( root->isTerminal){
                cout << pattern + root->data << endl;
            }
        }
    }
    void autoComplete(vector<string> input, string pattern) {
        // Complete this function
        // Print the output as specified in question
        int size = input.size();
        for(int i = 0; i < size; i++){
            insertWord(root , input[i]);
        }
        int searchindex = pattern[0] - 'a';
        TrieNode *child = root->children[searchindex];
        int position = 1;
        int patternlen = pattern.size();
        while(child){
            if(position >= patternlen){
                for(int k = 0; k < 26; k++){
                    print(child->children[k] , pattern);
                }
                if(child->isTerminal){
                    cout << pattern << endl;
                }
                break;
            }
            searchindex = pattern[position] - 'a';
            position++;
            child = child->children[searchindex];
            
        }
        
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
    t.autoComplete(vect, pattern);
}
