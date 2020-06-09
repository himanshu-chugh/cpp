#include<bits/stdc++.h>
using namespace std;


pair<int,int> max4(pair<int,int> &p ,pair<int,int> &q ){
    pair<int,int> r;
    int arr[4] = {p.first , p.second , q.first , q.second};
    // cout <<" sorting of numbers" << endl;
    // for(int i  = 0; i < 4; i++){
    //     cout << arr[i] <<  " ";
    // }
    // cout <<endl;
    sort(arr, arr+4);
    r.first = arr[3];
    r.second = arr[2];
    // cout <<" sorted number reported "<< r.first << " " << r.second << endl;
    return r;
}

void build(int *a , pair<int,int> *tree , int start , int end , int node){
    if(start == end){
        tree[node] = {a[start] , INT_MIN};
        return;
    }
    int mid = (start+end)/2;
    build(a , tree , start, mid , 2*node);
    build(a , tree , mid+1 , end , 2*node+1);
    tree[node] = max4(tree[node*2] , tree[node*2+1]);
}

void update(int *a , pair<int,int>*tree , int start , int end ,int node, int idx , int value){
    if(start == end ){
        tree[node].first = value;
        a[start] = value;
        tree[node].second = INT_MIN;
        // cout << "acutallly done sometthing on node " << node << endl;
        return;
    }
    pair<int,int > p1=tree[node*2] , p2 = tree[node*2+1];
    int mid = (start+end)/2;
    if(mid >= idx){
        update(a , tree , start , mid, node*2 , idx , value);
    }
    else{
        update(a , tree, mid+1 , end , node*2+1 ,idx , value);
    }
    // if(tree[node*2] != p1 or tree[node*2+1] != p2){
    //     cout << endl;
    //     cout << "change in node " << node << endl;
    //     cout << "change from " << p1.first << " to " << tree[node*2].first << endl;
    //     cout << "change from " << p1.second << " to " << tree[node*2].second << endl;
    //     cout << "change from " << p1.first << " to " << tree[node*2+1].first << endl;
    //     cout << "change from " << p2.second << " to " << tree[node*2+1].second << endl << endl;
    // }

    tree[node] = max4(tree[node*2] , tree[node*2+1]);
}


pair<int,int> query(pair<int,int>*tree , int start , int end , int node ,int left , int right){
    if(end < left or right < start){
        return {INT_MIN , INT_MIN};
    }
    if(start >= left and right >= end ){
        // cout <<  tree[node].first << " " << tree[node].second << endl;
        return tree[node];
    }
    pair<int,int> p ,q;
    int mid = (start+end)/2;
    
    p = query(tree , start , mid , node*2 , left , right);
    q = query(tree , mid+1 , end , node*2+1 , left , right);
    return max4(p , q); 
}

int main(){
    int n , q;
    cin >> n;
    int *a = new int[n];
    pair <int,int> *tree = new pair<int, int>[n*4];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> q;
    char c;
    int index1 , index2;
    build(a , tree , 0 , n-1 , 1);

    // cout <<  " tree has been built " << endl;
    // for(int i = 1; i <= n*2+1; i++){
    //     cout << tree[i].first << "-" << tree[i].second << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << i<<" " ;
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << a[i]<<" " ;
    // }
    // cout << endl;
    for(int i = 0; i< q; i++){
        cin >> c;
        cin >> index1 >> index2;
        if(c == 'Q'){
            // cout << "came in Q " << endl ;
            pair<int, int> r = query(tree , 0  , n-1 , 1,index1-1 , index2-1);
            // cout << "came out of query " << endl;
            int ans = r.first + r.second;
            cout << ans << endl;
        }
        else if (c == 'U'){
            // cout << "tree before update " << endl;
            // for(int i =1; i <= 2*n+1; i++){
            //     cout << tree[i].first << "-" << tree[i].second << " ";
            // }
            // cout << endl;
            // for(int i = 0; i< n; i++){
            //     cout << a[i] << " " ;
            // }
            // // cout << endl;
            update(a , tree , 0 , n-1 , 1, index1-1 , index2);
            // for(int i = 0; i< n; i++){
            //     cout << a[i] << " " ;
            // }
            // cout << endl;
            // for(int i =1; i <= 2*n+1; i++){
            //     cout << tree[i].first << "-" << tree[i].second << " ";
            // }
            // cout << endl;
        }
        else{}
    }


    delete[] a, tree;

}