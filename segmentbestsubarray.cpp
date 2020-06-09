#include<bits/stdc++.h>
using namespace std;
struct data{
    int sum = 0, maxsum = 0, bestpre = 0 , bestpost = 0;
}

void buildTree(int*a , data*tree , int start , int end , int node){
    if(start == end){
        tree[node].sum = a[start];
        tree[node].maxsum = a[start];
        tree[node].bestpre = a[start];
        tree[node].bestpost = a[start];
        return ;
    }
    int mid = (start+end)/2;
    buildTree(a , tree, start , mid , node*2);
    buildTree(a , tree, mid+1 , end, node*2 + 1);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
    tree[node].best
}



int main() {
    int n , m;
    cin >>  n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    data *tree = new data[n*3];
    buildTree(a, tree, 0 , n-1, 1);
    cin >> m;
    for(int i = 0; i < m; i++){
        int index1 , index2;
        cin >> index1 >> index2;
        data ans = query(tree, 0 , n-1 , index1-1 , index2-1);
        int final = max(ans.sum , max(ans.maxsum , max(bestpre , bestpost)));
        cout << final << endl;
    }
    
    delete[] data;

}