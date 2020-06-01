#include <iostream>
using namespace std;
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
    
};


#include <climits>
#include <queue>


// Following is the given Tree node structure
/**************

 template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};
***************/



#include<stack>
using namespace std;

class node{
    public:
    int f;
    int s;
    TreeNode<int> * ptr;
    node(TreeNode<int> * s , int ss){
        f = ss;
        ptr = s;
    }
};
node* helper(TreeNode<int>* root){
    if(root == NULL) {
        return 0;
    }
    if(root->children.size() == 0){
        return NULL;
    }
    node* body = new node(root , root->data);
    body->s = INT_MIN;
    for(int i = 0; i < root->children.size(); i++){
        node * t = helper(root->children[i]);
        if(t == NULL){
            if(body->f < root->children[i]->data){
                body->s = body->f;
                body->f = root->children[i]->data;
            }
            else if(body->s < root->children[i]->data && root->children[i]->data != body->f){
                body->s = root->children[i]->data;
            }
            else{}
        }
        else{
            if(body->f > t->f){
                if(body->s < t->f){
                    body->s = t->f;
                }
            }
            else if(body->f < t->f){
                int tt = body->f;
                body->f = t->f;
                if(tt > t->s){
                    body->s = tt;
                }
                else if(tt < t->s){
                    body->s = t->s;
                }
                else{};
            }
            else{}
        }
        delete t;
    }
    return body;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    cout<< helper(root)->s << "\n";
    return helper(root)->ptr;
}





TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = secondLargest(root);
    if(ans == NULL) {
        cout << INT_MIN << endl;
    }
    else {
        cout << ans -> data << endl;
    }
}
