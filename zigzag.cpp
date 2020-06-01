#include <iostream>
#include <queue>
#include <stack>

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

#include<stack>
using namespace std;

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int>*> lr,rl;
    rl.push(root);
    while(!lr.empty() || !rl.empty()){
        while(!lr.empty()){
            cout<<lr.top()->data<<" ";
            if(lr.top()->right){
                rl.push(lr.top()->right);
            }
            if(lr.top()->left){
                rl.push(lr.top()->left);
            }
            lr.pop();
            if(lr.empty()){
                cout<<endl;
            }
        }
        while(!rl.empty()){
            cout<<rl.top()->data<<" ";
            if(rl.top()->left){
                lr.push(rl.top()->left);
            }
            if(rl.top()->right){
                lr.push(rl.top()->right);
            }
            rl.pop();
            if(rl.empty()){
                cout<<endl;
            }
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
    zigZagOrder(root);
}
