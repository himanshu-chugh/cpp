#include<iostream>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> *left,*right;
    BinaryTreeNode(T d){
        data = d;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

template <typename T>
class BinarySearchTree{
    BinaryTreeNode<T> *root;
    
    bool hasData(T data , BinaryTreeNode<T> * r){
        if(r == NULL){
            return false;
        }
        if(r->data == data){
            return true;
        }
        if(r->data > data){
            return hasData(data , r->left);
        }
        else{
            return hasData(data , r->right);
        }
    }

    BinaryTreeNode<T>* insert(T data , BinaryTreeNode<T>*r){
        if(r == NULL ){
            BinaryTreeNode<T> * temp = new BinaryTreeNode<T>(data);
            return temp;
        }
        if (r->data > data)
        {
            r->left = insert(data , r->left);
            return r;
        }
        else{
            r->right = insert(data , r->right);
            return r;
        }
    }

    BinaryTreeNode<T>* deleteData(T d , BinaryTreeNode<T> *r){
        if(r == NULL){
            return NULL;
        }
        if(r->data == d && r->left == NULL && r->right == NULL){
            delete r;
            return NULL;
        }
        else if(r->data == d  && r->left != NULL && r->right == NULL){
            BinaryTreeNode<T> *temp = r->left;
            r->left = NULL;
            delete r;
            return temp;
        }
        else if(r->data == d && r->left == NULL  && r->right !=NULL ){
            BinaryTreeNode<T> *temp = r->right;
            r->right = NULL;
            delete r;
            return temp;
        }
        else if(r->data == d && r->left != NULL && r->right != NULL){
            BinaryTreeNode<T> *temp1 = r->right ,*temp2=NULL;
            while(temp1->left){
                temp2 = temp1;
                temp1 = temp1->left;
            }
            if(temp2 == NULL){
                temp1->left = r->left;
                r->right = NULL;
                r->left = NULL;
                delete r;
                return temp1;
            }
            else{
                temp2->left = temp1->right;
                temp1->left = r->left;
                temp1->right = r->right;
                delete r;
                return temp1;
            }   
        }
        else if(r->data > d){
            r->left = deleteData(d,r->left );
            return r; 
        }
        else if(r->data < d){
            r->right = deleteData(d,r->right );
            return r;
        }
        else{
            return NULL;
        }
    }   

    void printThisTree(BinaryTreeNode<T>* r){
        if(r){
            printThisTree(r->left);
            cout<<r->data<<" ";
            printThisTree(r->right);
        }
    }

    public:
    BinarySearchTree(){
        root = NULL;
    }
    ~BinarySearchTree(){
        delete root;
    }
    
    void deleteData(T data){
        root = deleteData(data , root);
    }
    void print(){
        printThisTree(root);
    }
    void insert(T data){
        root = insert(data , root);
        
    }

    bool hasData(T data){
        return hasData(data , root);
    }

};