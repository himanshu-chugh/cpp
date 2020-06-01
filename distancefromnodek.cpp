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
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
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
void help(BinaryTreeNode<int>* root , int distance , BinaryTreeNode<int>* toIgnore = NULL){
    if(root){
        if(distance == 0 ){
            cout << root->data << "\n" ;
        }
        else if(distance > 0){
            if(!(toIgnore == root->left))
            help(root->left , distance - 1);
            if(!(toIgnore == root->right))
            help(root->right , distance - 1);
        }
        else{
            return;
        }
    }
    return;
}
#include<stack>
using namespace std;
void helper(BinaryTreeNode<int>* root , int distance , int node , stack<BinaryTreeNode<int>*> &s){
    if(root){
        BinaryTreeNode<int>* last = NULL;
        s.push(root);
        if(root->data == node){
            while(!s.empty()) {
                help(s.top() , distance , last);
                distance--;
                last = s.top();
                s.pop();
                if(distance<0){
                break;
                }
            } 
        }
        else{
            helper(root->left , distance , node , s);
            helper(root->right , distance , node , s);
        }
        if(!s.empty())
        s.pop();
    }
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code here
    stack <BinaryTreeNode<int>*> s ;
    helper(root , k , node ,s);
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
    int targetNode, k;
    cin >> targetNode >> k;
    nodesAtDistanceK(root, targetNode, k);
    delete root;
}
