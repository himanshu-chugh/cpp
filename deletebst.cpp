#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *lptr ;
    node *rptr ;
    node(){
        lptr = NULL;
        rptr = NULL;
    }
};

node* createBst(node *root , int d){
    if(root == NULL){
        node *n = new node;
        n->data = d;
        return n;
    }
    else if(root->data > d){
        root->lptr = createBst(root->lptr , d);
        return root;
    }
    else{
        root->rptr = createBst(root->rptr , d);
        return root;
    }
}



void printBst(node*root){
    if(root==NULL){
        return ;
    }
    printBst(root->lptr);
    cout<<root->data<<" ";
    printBst(root->rptr);
}

node* deleteFromBst(node*root , int d){
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == d && root->lptr == NULL && root->rptr == NULL){
        delete root;
        return NULL;
    }
    else if(root->data == d && root->rptr == NULL && root->lptr != NULL){
        node* temp = root->lptr;
        delete root;
        return temp;
    }
    else if(root->data == d && root->lptr == NULL && root->rptr != NULL){
        node* temp = root->rptr;
        delete root;
        return temp;
    }
    else if(root->data == d && root->lptr != NULL && root->rptr != NULL){
        node *parentPtr = NULL , *smallBigPtr = root->lptr ;
        while(smallBigPtr->rptr){
            parentPtr = smallBigPtr;
            smallBigPtr = smallBigPtr->rptr;
        }
        
        if(parentPtr == NULL){
            smallBigPtr->rptr = root->rptr;
            delete root;
        }
        else{
            parentPtr->rptr = smallBigPtr->lptr;
            smallBigPtr->lptr = root->lptr;
            smallBigPtr->rptr = root->rptr;
            delete root;
        }
        return smallBigPtr;
    }
    else if(root->data > d){
        root->lptr = deleteFromBst(root->lptr , d);
        return root;
    }
    else{
        root->rptr = deleteFromBst(root->rptr , d);
        return root;
    }
}
    

int main(){
    node *root=NULL;
    int a[] = {15,3,6,8,2,7,17,5,432,118 ,252,19};
    for(int i=0;i<12;i++){
        root = createBst(root , a[i]);
    }
    
    printBst(root);
    //cout<<endl;
    //root = deleteFromBst(root , 118);
    //printBst(root);

    /*    
    for(int i=0;i<12;i++){
        cout<<endl;
        root = deleteFromBst(root , a[i]);
        printBst(root);
    }
    
    cout<<endl;
    */ 
    
   delete root;
}