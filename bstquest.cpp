#include<iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


/**************
 
 * Following is BinaryTreeNode class -
 
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
 * Foloowing is main function which we are using internally

int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
*******************/


class BST {
	// Complete this class
    BinaryTreeNode<int> *root;

    BinaryTreeNode<int>* insert(int data , BinaryTreeNode<int>*r){
        if(r == NULL ){
            BinaryTreeNode<int> * temp = new BinaryTreeNode<int>(data);
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
    
    bool hasData(int data , BinaryTreeNode<int> * r){
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

        BinaryTreeNode<int>* deleteData(int d , BinaryTreeNode<int> *r){
        if(r == NULL){
            return NULL;
        }
        if(r->data == d && r->left == NULL && r->right == NULL){
            delete r;
            return NULL;
        }
        else if(r->data == d  && r->left != NULL && r->right == NULL){
            BinaryTreeNode<int> *temp = r->left;
            r->left = NULL;
            delete r;
            return temp;
        }
        else if(r->data == d && r->left == NULL  && r->right !=NULL ){
            BinaryTreeNode<int> *temp = r->right;
            r->right = NULL;
            delete r;
            return temp;
        }
        else if(r->data == d && r->left != NULL && r->right != NULL){
            BinaryTreeNode<int> *temp1 = r->right ,*temp2=NULL;
            while(temp1->left){
                temp2 = temp1;
                temp1 = temp1->left;
            }
            if(temp2 == NULL){
                temp1->left = r->left;
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

    void printThisTree(BinaryTreeNode<int>* r){
        if(r){
            cout<<r->data<<":";
            
            if(r->left){
                cout<<"L:"<<r->left->data;
            }
            if(r->left && r->right){
                cout<<",";
            }
            if(r->right){
                cout<<"R:"<<r->right->data;
            }
            cout<<endl;
            printThisTree(r->left);
            printThisTree(r->right);
        }
    }

    public:
    void insert(int d){
        root = insert(d , root);
    }
    bool hasData(int data){
        return hasData(data , root);
    }
    void deleteData(int data){
        root = deleteData(data , root);
    }
    void printTree(){
        printThisTree(root);
    }
};



int main(){
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }
}
