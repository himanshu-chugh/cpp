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
#include<queue>
using namespace std;
void printLevelWise(BinaryTreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int>* temp = q.front();
        q.pop();
        cout << temp->data << ":" ;
        if(temp->left){
            cout << "L:" << temp->left->data;
            q.push(temp->left);
        }
        else{
            cout << "L:" << -1;
        }
        if(temp->right){
            cout << ",R:" << temp->right->data;
            q.push(temp->right);
        }
        else{
            cout << ",R:" << -1;
        }
        cout << endl;
    }
}

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left) , height(root->right));
}

int diameterOfBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int option1 = diameterOfBinaryTree(root->left);
    int option2 = diameterOfBinaryTree(root->right);
    int option3 = height(root->left) + height(root->right) + 1;
    return(max(option1 , max(option2,option3) ) );
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
    if(!p1.first || !p2.first){
        toReturn.first = false;
        return toReturn;
    }
    else if(abs(p1.second - p2.second) > 1){
        toReturn.first = false;
        return toReturn;
    }
    else{
        toReturn.second = 1 + max(p1.second , p2.second);
        toReturn.first = true ;
        return toReturn;
    }
}

bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
    //cout<<"---> "<<helper(root).first<<endl;
    return helper(root).first;
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    cout<<"\n\tchaeck balaced:";
    cout<<isBalanced(root);
}
