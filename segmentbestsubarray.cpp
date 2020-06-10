#include<bits/stdc++.h>
using namespace std;
struct data{
    int sum = 0, maxsum = 0, bestpre = 0 , bestpost = 0;
};

void buildTree(int*a , data*tree , int start , int end , int node){
    // cout << "ever ccame " << endl;
    if(start == end){
        tree[node].sum = a[start];
        tree[node].maxsum = a[start];
        tree[node].bestpre =a[start];
        tree[node].bestpost = a[start];
        return ;
    }
    int mid = (start+end)/2;
    buildTree(a , tree, start , mid , node*2);
    buildTree(a , tree, mid+1 , end, node*2 + 1);
    tree[node].sum = tree[node*2].sum + tree[node*2+1].sum;
    int l = node*2;
    int r = node*2+1;
    tree[node].maxsum = max(tree[l].maxsum ,
                        max(tree[r].maxsum ,
                        max(tree[l].sum+tree[r].bestpre ,
                        max(tree[r].sum + tree[l].bestpost ,
                        tree[l].bestpost+tree[r].bestpre))));
    tree[node].bestpre = max(tree[l].bestpre , tree[l].sum+tree[r].bestpre);
    tree[node].bestpost = max(tree[r].bestpost , tree[r].sum+tree[l].bestpost);


    cout << " for node " << node << endl;
    cout << "sum " << tree[node].sum << endl;
    cout << "maxsum " << tree[node].maxsum << endl;
    cout << "bestpre " << tree[node].bestpre << endl;
    cout << "bestpost " << tree[node].bestpost << endl << endl;
}


data query(data*tree , int start , int end,int node, int left , int right){
    if(left > end or right < start){
        data d;
        return d;
    }
    if(left <= start    and    end <= right){
        return tree[node];
    }
    int mid = (start+end)/2;
    data d1 = query(tree , start , mid ,node*2 , left , right );
    data d2 = query(tree , mid+1 , end ,node*2+1 , left , right );
    data ans;
    int l= node*2 ;
    int r = l+1;
    cout << "node for which answers are: " << l << endl;
    

    ans.sum = d1.sum + d2.sum;
    ans.maxsum = max(d1.maxsum ,
                        max(d2.maxsum ,
                        max(d1.sum+d2.bestpre ,
                        max(d2.sum + d2.bestpost ,d1.bestpost+d2.bestpre))));
    ans.bestpre = max(d1.bestpre , d1.sum+d2.bestpre);
    ans.bestpost = max(d2.bestpost , d2.sum+d1.bestpost);
    cout << "node which returned " << node << endl;
    cout <<" sum " << ans.sum << endl;
    cout <<" maxsum " << ans.maxsum << endl;
    cout << " best pre " << ans.bestpre << endl;
    cout << " best post " << ans.bestpost << endl;
    cout << endl;
    return ans;
}

int main() {
    int n , m;
    cout << "enter n " << endl;
    cin >>  n;
    int *a = new int[n];
    cout << "enter array " << endl;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "array input finished " << endl;
    data *tree = new data[n*3];
    buildTree(a, tree, 0 , n-1, 1);
    cout << "things came here " << endl;
    cin >> m;
    for(int i = 0; i < m; i++){
        int index1 , index2;
        cin >> index1 >> index2;
        data ans = query(tree, 0 , n-1 , 1,index1-1 , index2-1);
        int final = max(ans.sum , max(ans.maxsum , max(ans.bestpre , ans.bestpost)));
        cout << final << endl;
    }
    delete[] a;
    delete[] tree;

}