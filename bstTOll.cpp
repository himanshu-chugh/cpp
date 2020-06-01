#include <iostream>
#include <queue>

template <typename T>
class Node{
public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
};

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
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
 
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

pair<Node<int>* , Node<int>*> constructBst2(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<Node<int>* , Node<int>*> p;
        p.first = NULL; 
        p.second = NULL;
        return p;
    }
    //Node<int>* head1=tail1=head2=tail2=NULL;
    pair<Node<int>* , Node<int>*> p1,p2,toReturn;
    Node<int>* node = new Node<int>(root->data);
    p1 = constructBst2(root->left);
    p2 = constructBst2(root->right);
    if(p1.first == NULL){
        toReturn.first = node;
        if(p2.first == NULL){
            toReturn.second = node;
            return toReturn;
        }
        else{
            node->next = p2.first;
            toReturn.second = p2.second;
            return toReturn;
        }
    }
    else{
        toReturn.first = p1.first;

        p1.second->next = node;
        if(p2.first == NULL){
            toReturn.second = node;
            return toReturn;
        }
        else{
            node->next = p2.first;
            toReturn.second = p2.second;
            return toReturn;
        }
    }
}


Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return constructBst2(root).first;
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
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    
}
