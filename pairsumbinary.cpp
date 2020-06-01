#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
    	if(left) {
     		delete left;
    	}
	if(right) {
     		delete right;
    	}
    }
};

using namespace std;

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<bits/stdc++.h>
using namespace std;
 
void helper(BinaryTreeNode<int> * root , vector<int>* v){
    if(root){
        //cout << root->data << " " ;
        v->push_back(root->data);
        helper(root->left , v);
        helper(root->right , v);
    }
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int>* v = new vector<int>();
    helper(root , v);
    cout << endl;
    //cout << v->size();
    int no = v->size();
    sort(v->begin() , v->end());
    int i = 0;
    int j = v->size() - 1;
    
    
    while(i<j){
        if(v->at(i) + v->at(j) == sum){
            cout << v->at(i) << " " << v->at(j) << endl;
            i++;
            j--;
        }
        else if(v->at(i) + v->at(j) > sum){
            j--;
        }
        else{
            i++;
        }
    }
    
    
}



BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int sum;
    cin >> sum;
    nodesSumToS(root, sum);
    delete root;
}
