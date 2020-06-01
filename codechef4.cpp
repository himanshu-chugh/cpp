#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>& s , int beg , int  end ){
    if(beg < 1){
        beg = 1;
    }
    if(end > s.size()-1){
        end = s.size()-1;
    }
    s[beg-1] += 1;
    s[end] -= 1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> v,v2;
        int n;
        cin >> n;
        int m;
        for(int i = 0; i < n; i++){
            cin >> m;
            v.push_back(m);
        }
        for(int i = 0; i < n; i++){
            cin >> m;
            v2.push_back(m);
        }
        vector<int> s;
        for(int i = 0; i <= n; i++){
            s.push_back(0);
        }
        for(int i = 0 ; i < n; i++){
            helper(s , i+1 - v[i] , i+1 + v[i] );
        }
        for(int i = 1; i < n; i++){
            s[i] += s[i-1];
        }
        s.pop_back();
        sort(s.begin() , s.end());
        sort(v2.begin(), v2.end());
        int count = 0;
        for(int i = 0; i < n; i++){
            if(v2[i] == s[i]){
                count++;
            }
        }
        if(count == n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}