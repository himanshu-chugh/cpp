#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;



class Avlnode{
    public:
    int data; 
    int height;
    Avlnode *left , *right;
    Avlnode(int d , int h){
        data = d;
        height = h;
        left = NULL;
        right = NULL;
    }
    ~Avlnode(){
        delete left , right;
    }
};

class AVL{
    Avlnode * root;
    int height(Avlnode* node){
        if(node){
            return node->height;
        }
        return 0;
    }
    Avlnode* rightRotate(Avlnode* root){
        Avlnode *x = root->left;
        root->left = x->right;
        x->right = root;
        root->height = max(height(root->left) , height(root->right)) + 1;
        x->height = max(height(x->left) , height(x->right)) + 1;
        return x;
    }
    Avlnode* leftRotate(Avlnode* root){
        Avlnode *x = root->right;
        root->right = x->left;
        x->left = root;
        root->height = max(height(root->left) , height(root->right)) + 1;
        x->height = max(height(x->left) , height(x->right)) + 1;
        return x;
    }
    int getbalance(Avlnode* root){
        return (height(root->left) - height(root->right));
    }
    
    Avlnode* inserthelper(Avlnode* root , int d){
        if(root == NULL){
            // cout << "Came here " << endl;
            Avlnode*a = new Avlnode(d , 1);
            // cout << " returning " << endl;
            return a;
        }
        else if(root->data > d){
            root->left = inserthelper(root->left , d);
        }
        else if(root->data < d){
            root->right = inserthelper(root->right , d);
        }
        else{
            return root;
        }
        root->height = max(height(root->left) , height(root->right)) + 1;
        
        int bf = getbalance(root);
        
        if(bf > 1 && root->left->data > d){
            return rightRotate(root);
        }
        if(bf < -1 && root->right->data < d){
            return leftRotate(root);
        }
        if(bf > 1 && root->left->data < d){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(bf < -1 && root->right->data > d){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void levelWisePrint( queue<Avlnode*> &s1 , queue<Avlnode*> &s2){
        // cout << s1.front()->data << " " ;
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                cout << s1.front()->data << " " ;
                if(s1.front()->left){
                    s2.push(s1.front()->left);
                }
                if(s1.front()->right){
                    s2.push(s1.front()->right);
                }
                s1.pop();
            }
            cout << endl;
            while(!s2.empty()){
                cout << s2.front()->data << " " ;
                if(s2.front()->left){
                    s1.push(s2.front()->left);
                }
                if(s2.front()->right){
                    s1.push(s2.front()->right);
                }
                s2.pop();
            }
            cout << endl;
        }
    }
    void inorderTraversal(Avlnode* root){
        if(root){
            inorderTraversal(root->left);
            cout << root->data << " " ;
            inorderTraversal(root->right);
        }
    }
    
    
Avlnode* deleteNode(Avlnode* root, int d)  {  
      
    if (root == NULL)  
        return root;  
  
    if ( d < root->data )  
        root->left = deleteNode(root->left, d);  
  
    else if( d > root->data )  
        root->right = deleteNode(root->right, d);  
  
    else
    {  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Avlnode *temp = root->left ?  
                         root->left :  
                         root->right;  
    
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else 
            *root = *temp;
            free(temp);  
        }  
        else
        {  
            Avlnode* temp = minValueNode(root->right);  
            root->data = temp->data;  
            root->right = deleteNode(root->right,  
                                     temp->data);  
        }  
    }  
  
    if (root == NULL)  
    return root;  
  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    int balance = getBalance(root);  
    if (balance > 1 &&  
        getBalance(root->left) >= 0)  
        return rightRotate(root);  
  
    if (balance > 1 &&  
        getBalance(root->left) < 0)  
    {  
        root->left = leftRotate(root->left);  
        return rightRotate(root);  
    }  
  
    if (balance < -1 &&  
        getBalance(root->right) <= 0)  
        return leftRotate(root);  
  
    if (balance < -1 &&  
        getBalance(root->right) > 0)  
    {  
        root->right = rightRotate(root->right);  
        return leftRotate(root);  
    }  
  
    return root;  
}




    public:
    AVL(){
        root = NULL;
    }
    void inorderTraversal(){
        inorderTraversal(root);
        cout << endl;
    }
    void insert(int d){
        root = inserthelper(root , d);
    }
    void levelWisePrint(){
        queue<Avlnode*> s1 , s2;
        if(root){
            s1.push(root);
        }
        // cout << root->data << " ";
        levelWisePrint(s1 , s2);
    }
    void deleteNode(int d){
        root = deleteNode(root , d);
    }
};


int main(){
    AVL a;
    cout << "Start to insert in avl tree" << endl;
    for(int i = 0; i < 15; i++){
        a.insert(i);
        cout << "\tEntering " << i << endl << endl;
        cout << "Level wise tree " << endl;
        a.levelWisePrint();
        cout << endl;
        cout << "inorder traversal" << endl;
        a.inorderTraversal();
        cout << endl;
    }
    return 0;
}