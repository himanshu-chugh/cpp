#include<bits/stdc++.h>
using namespace std;


void buildTree(int*a , int *tree, int start , int  end , int treenode ){
    if(start == end){
        tree[treenode]  = a[start];
        return ;
    }
    int mid = (start+end)/2;
    buildTree(a , tree , start , mid , 2*treenode);
    buildTree(a , tree , mid+1 , end , 2*treenode+1);
    tree[treenode] = tree[treenode*2] + tree[treenode*2 + 1];
}


void updateTree(int *a , int*tree , int start, int end , int treenode , int idx , int value){
    if(start == end){
        tree[treenode] = value;
        a[idx] = value;
        return;
    }
    int mid = (start+end)/2;
    if(idx > mid){
        updateTree(a , tree , mid+1 , end , 2*treenode+1 , idx , value);
    }
    else{
        updateTree(a , tree , start , mid , 2*treenode , idx , value);
    }
    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}


int  queryTree(int*tree , int start , int end , int node , int left , int right){
    if(left > end or right < start){
        return 0;
    }
    if(left <= start    &&     end <= right){
        return tree[node];
    }
    int mid = (start+end)/2;
    int s1 = queryTree(tree, start , mid , node*2 , left, right);
    s1 += queryTree(tree, mid+1 , end , node*2 +1 , left , right);
    return s1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8 ,9};
    int sum = 0;
    for(int i = 0; i < 9; i++){
        sum += arr[i];
        cout << sum << " ";
    }
    cout << endl;
    int *tree = new int[18];
    buildTree(arr , tree , 0 , 8 , 1);
    for(int i = 1; i < 18; i++){
        cout << tree[i] << " ";
    }
    int index = 0;
    int value;
    while(1){
        cout << "enter index " << endl;
        cin >> index;
        if(index < 0){
            break;
        }
        cout << "enter value " << endl;
        cin >> value;
        updateTree(arr , tree ,  0 , 9 , 1 , index , value);
        cout << "array now" << endl;
        for(int i =0; i < 9; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "tree now " << endl;
        for(int i= 1; i< 18; i++){
            cout << tree[i]  << " ";
        }
        cout << endl;
    }
    cout << "enter a range to query " << endl;
    int  left , right ;
    cin >> left >> right;
    cout << queryTree(tree , 0 , 8 , 1 , left , right) << endl;
    cout << endl;
}