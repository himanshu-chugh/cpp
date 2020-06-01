#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode** children;
    bool isTerminal;
    TrieNode(char c){
        data = c;
        children = new TrieNode*[26];
        for( int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }
    private:
    void inserthelper(TrieNode* root , string s){
        if( s.size() == 0){
            root->isTerminal = true;
            return;
        }
        else if( root->children[s[0] - 'a'] == NULL){
            root->children[s[0] - 'a'] = new TrieNode(s[0]);
            inserthelper(root->children[s[0] - 'a'] , s.substr(1)); 
        }
        else{
            inserthelper(root->children[s[0] - 'a'] , s.substr(1) );
        }
    }

    bool searchhelper(TrieNode*root , string s){
        if(s.length() == 0){
            return root->isTerminal;
        }
        int childrenindex = s[0] - 'a';
        if(root->children[childrenindex] != NULL){
            if(root->children[childrenindex]->data == s[0])
            return searchhelper(root->children[childrenindex] , s.substr(1));
        }
        
        return false;
        
    }

    void removehelper(TrieNode* root , string s){
        if(s.length() == 0){
            root->isTerminal = false;
            return;
        }
        int childrenindex = s[0] - 'a';
        if(root->children[childrenindex] != NULL){
            removehelper(root->children[childrenindex] , s.substr(1));
            bool flag = 0;
            for ( int i = 0; i < 26; i++){
                if(root->children[childrenindex]->children[i] != NULL){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                delete root->children[childrenindex];
                root->children[childrenindex] = NULL;
            }
        }
        return;
    }

    public:
    void insertWord(string s){
        inserthelper(root , s);
    }

    bool searchWord(string s){
        return searchhelper(root , s);
    }
    void removeWord(string s){
        removehelper(root, s);
    }
};

int main(){
    Trie t;
    t.insertWord("ans");
    cout << t.searchWord("an") << endl;
    cout << t.searchWord("ans") << endl;
    t.removeWord("ans");
    cout << t.searchWord("ans") << endl;
    return 0;
}