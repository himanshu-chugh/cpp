#include<iostream>
#include"tree.h"
#include<queue>
using namespace std;

TreeNode<int>* inputTreeLevelWise(){
    int rootdata;
    cout << "Enter root data :" << endl;
    cin >> rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        cout << "Enter num of child of node :" << node->data << endl;
        int numChild;
        cin >> numChild;
        for( int i = 0; i < numChild; i++) {
            int data;
            cout << "Enter data of " << i << " th child of node : " << node->data << endl;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            q.push(child);
            node->children.push_back(child);
        } 
    }
    return root;
}


TreeNode<int>* inputTree(){
    int rootdata;
    cout<<"Enter data : \n";
    cin>>rootdata;
    TreeNode<int>* root = new TreeNode<int>(rootdata);
    int noOfChildren=0;
    cout<<"Enter no of children of "<<rootdata<<" node : \n";
    cin>>noOfChildren;
    
    for(int i=0; i<noOfChildren; i++) {
        root->children.push_back(inputTree());
    }
    return root;
    
}

void print(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<< root->data<<" : ";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data<<" ,";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        print(root->children[i]);
    }
}

void printLevelWise(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* node = q.front();
        q.pop();
        cout<< node->data<<":";
        for(int i=0;i<node->children.size();i++){
            cout<<node->children[i]->data;
            if(i < node->children.size()-1) {
                cout << ',';
            }
            q.push(node->children.at(i));
        }
        cout << endl;
    }
}

int numOfNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int numOfChild = 1;
    for (int i = 0; i < root->children.size(); i++) {
        numOfChild += numOfNodes(root->children.at(i));
    }
    return numOfChild;
}



TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root->children.size() == 0 ) {
        return root;
    }
    TreeNode<int>* max = root;
    for(int i = 0; i < root->children.size(); i++) {
        if(maxDataNode(root->children.at(i))->data > max->data){
            max = maxDataNode(root->children.at(i));
        }
    }
    return max;
}


int height(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root->children.size() == 0) {
        return 1;
    }
    int max = 0;
    for( int i = 0; i < root->children.size(); i++) {
        if( height(root->children.at(i)) > max){
            max = height( root->children.at(i));
        }
    }
    return max + 1;
}

int numLeafNodes(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL) {
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int no = 0;
    for (int i = 0; i < root->children.size(); i++) {
        no += numLeafNodes(root->children.at(i));
    }
    return no;
}


void postOrder(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output in specified format.
     */
    if(root == NULL) {
        return;
    }
    for(int i = 0; i < root->children.size(); i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int sum = root->data;
    for(int i = 0; i < root->children.size(); i++) {
        sum += sumOfNodes( root->children.at(i));
    }
    return sum;
}



int helper(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    int sum = root->data;
    //cout << "for node " << root->data << " " ;
    for(int i = 0; i < root->children.size(); i++) {
        sum += root->children[i]->data;
    }
    //cout << sum << endl;
    return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    if(root->children.size() == 0){
        return root;
    }
    TreeNode<int> * node = root ;
    for( int i = 0; i < root->children.size(); i++) {
        if( helper(node) < helper(maxSumNode(root->children[i]))){
            node = maxSumNode(root->children[i]);
        }
    }
    
    return node;
}




int main(){
    /* 
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* child1 = new TreeNode<int>(2);
    TreeNode<int>* child2 = new TreeNode<int>(3);
    TreeNode<int>* child4 = new TreeNode<int>(4);
    TreeNode<int>* child5 = new TreeNode<int>(5);
    root->children.push_back(child1);
    root->children.push_back(child2);
    root->children[0]->children.push_back(child4);
    root->children[0]->children.push_back(child5);
    */
    TreeNode<int>* root = inputTreeLevelWise();
    printLevelWise(root);
    cout << "no of nodes " << numOfNodes(root) << endl;
    cout << "sum of all nodes " << sumOfNodes(root) << endl;
    cout << "max data " << maxDataNode(root)->data << endl;
    cout << " height of tree : " << height( root ) << endl;
    cout << "no of leaf nodes " << numLeafNodes(root) << endl;
    cout << " post order : ";
    postOrder(root); 
    cout << endl;
    cout << "node with max sum of child " << maxSumNode(root)->data << endl;
}