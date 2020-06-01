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
#include<vector>
using namespace std;
vector<int>* help(BinaryTreeNode <int>* root , int d){
    vector<int>*v=NULL;
    if(root == NULL){
        return NULL;
    }
    else if(root->data  == d){
        vector<int>*V = new vector<int>();
        V->push_back(d);
        return V;
    }
    else if(v = help(root->left , d)){
        v->push_back(root->data);
        return v;
    }
    else if(v = help(root->right , d)){
        v->push_back(root->data);
        return v;
    }
    else{
        return NULL;
    }
}
int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
    // Write your code here
    vector<int>*v1=NULL,*v2=NULL;
    v1 = help(root,val1);
    v2 = help(root,val2);
    int ans = root->data;
    while(v1->back() == v2->back()){
        ans = v1->back();
        v1->pop_back();
        v2->pop_back();
    }
    return ans;
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
    int a, b;
    cin >> a >> b;
    cout << lcaBinaryTree(root, a, b);
    delete root;
}
