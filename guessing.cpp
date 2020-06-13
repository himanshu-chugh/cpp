#include<bits/stdc++.h>
#define ll long long
#define pp pair<ll,ll>
using namespace std;

bool comp(pp &a , pp &b){
    return a.first <= b.first;
}

int getmid(vector<pp> &v){
    int total = 0;
    for(int i = 0; i< v.size(); i++){
        total +=  (v[i].second - v[i].first +1);
    }
    int mid = (total+1)/2;
    for(int i =0; i<v.size(); i++){
        if(mid <= (v[i].second - v[i].first +1)){
            return mid+v[i].first-1;
        }
        else{
            mid -= (v[i].second - v[i].first +1);
        }
    }
    return total;
}


void solve(vector<pp> &tr , vector<pp> &fs , char lastquery){
    sort(tr.begin() , tr.end() , comp);
    sort(fs.begin() , fs.end() , comp);
    if(lastquery == 'G'){
        
    }
}


int main(){
    int n;
    cin >> n;
    vector<pp> tr , fs;
    cout << (n+1)/2 << endl;
    char ch;
    cin >> ch;
    if(ch == 'E'){
        exit(1);
    }
    else if(ch == 'G'){
        pp f(1,(n+1)/2 -1) , t((n+1)/2 +1 , n);
        tr.push_back(t);
        fs.push_back(f);
        solve(tr,fs,ch);
    }
    else{
        pp t(1,(n+1)/2 -1) , f((n+1)/2 +1 , n);
        tr.push_back(t);
        fs.push_back(f);
        solve(tr,fs,ch);
    }
}