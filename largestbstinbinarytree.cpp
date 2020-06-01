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
class Pair{
    public:
    BinaryTreeNode<int>* ptr;
    int height;
    int maxi;
    int mini;
    Pair(BinaryTreeNode<int>* d){
        ptr = d;
        height = 0;
    }
};

Pair helper(BinaryTreeNode<int>* root){
    if(!root){
        Pair p(NULL);
        return p;
    }
    else{
        Pair p1(NULL),p2(NULL) , toReturn(root);
        toReturn.height = 1;
        p1 = helper(root->left);
        p2 = helper(root->right);
        if(p1.ptr && p2.ptr){
            if( p1.ptr == root->left && p2.ptr == root->right ) {
               if( root->data > p1.maxi && root->data < p2.mini ){
                    toReturn.height = max(p1.height , p2.height) + 1;
                    toReturn.maxi = max(root->data , max(p1.maxi , p2.maxi));
                    toReturn.mini = min(root->data , min(p1.mini , p2.mini));
                    toReturn.ptr = root;
                    return toReturn;
                }
                else
                {
                    if(max(p1.height , p2.height)  == p1.height){
                        return p1;
                    }
                    else{
                        return p2;
                    }
                }
            }
            else{
                if(max(p1.height , p2.height)  == p1.height){
                        return p1;
                }
                else{
                    return p2;
                }
            }
            
        }
        else if(!p1.ptr && !p2.ptr){
            toReturn.maxi = root->data;
            toReturn.mini = root->data;
            toReturn.ptr = root;
            toReturn.height = 1;
            return toReturn;
        }
        else if(!p1.ptr && p2.ptr){
            if(p2.mini > root->data){
                toReturn.mini = root->data;
                toReturn.maxi = p2.maxi;
                toReturn.height = p2.height + 1;
                return toReturn;
            }
            else {
                return p2;
            }
        }
        else if(p1.ptr && !p2.ptr){
            if(p1.maxi < root->data){
                toReturn.maxi = root->data;
                toReturn.mini = p1.mini;
                toReturn.height = p1.height + 1;
                return toReturn;
            }
            else {
                return p1;
            }
        }
        else{
            cout<<"antdcfd\tcdwsvg\n";
            toReturn.maxi = root->data;
            toReturn.mini = root->data;
            toReturn.height = 1;
            return toReturn;
        }
        
    }
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    Pair p = helper(root);
    return p.height;

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
    cout << largestBSTSubtree(root);
    delete root;
}
