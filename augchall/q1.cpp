#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<int> v;
    while(t--){
        int n;
        cin >> n;
        vector<int> v1 , v2 ;
        int m ;
        for(int i = 0; i < n; i++){
            cin >> m;
            v1.push_back(m);
        }
        for(int i = 0; i < n; i++){
            cin >> m;
            v2.push_back(m);
        }
        
        int max = 0;
        int ans;
        for(int i = 0; i < n; i++){
            if(max <= v1[i]*2 - v2[i]){
                max = v1[i]*2 - v2[i];
                ans = v1[i];
            }
        }
        if(max > 0){
            v.push_back(ans*20);
        }
        else{
            v.push_back(0);
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}