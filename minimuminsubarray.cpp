#include<bits/stdc++.h>
using namespace std;


void buildTree(int*a , int *tree , int start , int end , int node){
    if(start == end){
        tree[node] = a[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(a, tree,  start, mid, node*2);
    buildTree(a, tree, mid+1, end, node*2+1);
    tree[node] = min(tree[node*2] , tree[node*2+1]);
}

void updateTree(int*a , int* tree, int start , int end, int node , int idx , int value){
    if(start == end){
        tree[node] = value;
        a[idx] = value;
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid){
        updateTree(a, tree, mid+1, end, node*2+1, idx, value);
    }
    else{
        updateTree(a, tree, start, mid, node*2, idx, value);
    }
    tree[node] = min(tree[node*2] , tree[node*2+1]);
}

int queryTree(int* tree, int start, int end, int node, int left, int right){
    if(left > end or right < start){
        return INT_MAX;
    }
    if(left <= start and end <= right){
        return tree[node];
    }
    else{
        int mid = (start+end)/2;
        return min( queryTree(tree , start, mid, node*2, left, right) 
        , queryTree(tree, mid+1, end, node*2+1, left, right) );
    }
}

int main() {
    int n,q;
    cin >> n >> q;
    int*a = new int[n];
    int*tree = new int[4*n];
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    // cout << "before tree building  " << endl;
    buildTree(a , tree , 0 , n-1 , 1);
    // for(int i = 1; i < 4*n; i++){
    //     cout << tree[i] <<" ";
    // }
    // cout << endl;
    for(int i  = 0; i < q; i++){
        char c;
        int index1,index2;
        cin >> c;
        cin >> index1 >> index2;
        index1--;
        if(c == 'q'){
            index2--;
            cout << queryTree(tree , 0 , n-1 , 1, index1 , index2) << endl;
        }
        else{
            updateTree(a , tree , 0 , n-1 , 1 , index1, index2);
            // for(int k = 0; k < n; k++){
            //     cout << a[k] <<  " ";
            // }
            // cout << endl;
        }
    }
    
    delete[] a;
    delete[] tree;
}