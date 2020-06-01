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


#include <queue>
#include <climits>


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
/*
class help{
    public:
    int f,s;
    TreeNode<int> * ptr;
    help(TreeNode<int>* ss){
        ptr = ss;
    }
};

help* helper(TreeNode<int>* root){
    if(root == NULL){
        return NULL;
    }
}
*/

void helper(TreeNode<int>* root , queue<TreeNode<int>*> &q){
    if(root == NULL){
        return;
    }
    q.push(root);
    for(int i = 0; i < root->children.size(); i++){
        helper(root->children[i] , q);
    }
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL){
        return NULL;
    }
    queue<TreeNode<int>*> q;
    helper(root , q);
    TreeNode<int> *temp = q.front() , *returnPointer = q.front() , *freminder = q.front();
    int f = temp->data , s = INT_MIN;
    while (!q.empty())
    {
        temp = q.front();
        if(f < temp->data){
            returnPointer = freminder;
            freminder = temp;
            s = f; 
            f = temp->data;
        }
        else if( s < temp->data && temp->data < f){
            s = temp->data;
            returnPointer = temp;
        }
        else{}
        q.pop();
    }
    cout<< f <<" " << s<<endl;
    if(f == s || s == INT_MIN){
        return  NULL;
    }
    return returnPointer;
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
