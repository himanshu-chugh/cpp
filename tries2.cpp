#include <iostream>
#include <string>
using namespace std;

#include <string>
#include <vector> 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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

	bool checkPalamdrom(string s){
		string k = s;
		s.reserve();
		return s == k;
	}

	bool findIfPalindromePair(vector<string> a) {
		// Complete this function
		// Return true or false.
		int size = a.size();
		for(int i = 0; i < size; i++){
			int len = a[i].length();
			string s;
			for(int j = len -1 ; j >= 0; j--){
				s = s + a[i][j];
			}
			if (s == a[i]){
				return true;
			}
			insertWord(root , s);
		}
		for(int i = 0; i < size; i++){
			int len = a[i].length();
			int pos = 1;
			TrieNode *child = root , *child1 = root->children[a[i][0] - 'a'];
			while(child1 && pos < len){
				child = child1;
				child1 = child1->children[a[i][pos] - 'a'];
				pos++;
			}
			if(pos == len){
				return true;
			}
			if(child->isTerminal){
				if(checkPalamdrom(a[i].substr(pos))){
					return true;
				}
			}
		}
		return false;
	}

};



#include <vector>


int main() {
    Trie t;
    vector <string> vect;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    
    bool ans = t.findIfPalindromePair(vect);
    if (ans){
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}