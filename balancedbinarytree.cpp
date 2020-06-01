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

pair<bool , int> helper(BinaryTreeNode<int> *root){
    if(root == NULL){
        pair<bool,int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<bool,int> p1,p2,toReturn;
    p1 = helper(root->left);
    p2 = helper(root->right);
    if(p1.first && p2.first){
        toReturn.first = false;
        return toReturn;
    }
    if(abs(p1.second - p2.second) > 1){
        toReturn.first = false;
        return toReturn;
    }
    else{
        toReturn.second = 1 + max(p1.second , p2.second);
        toReturn.first = true;
        return toReturn;
    }
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    //cout<<"---> "<<helper(root).first<<endl;
    return helper(root).first;
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
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	cout << "false" << endl;
}
