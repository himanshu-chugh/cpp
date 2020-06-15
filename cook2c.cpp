#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    queue<ll> q;
    ll n , m;
    cin >> n >> m;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    n--;
    ll count = 0;
    for(ll i = 0; i < m; i++){
        ll nu ;
        cin >> nu;
        ll max;
        for(count; count < nu; count++){
            if( n >= 0 and (q.empty() or q.front() <= a[n])){
                max = a[n];
                n--;
            }
            else{
                max = q.front();
                q.pop();
            }
            // else{}
            if(max/2 > 0){
                q.push(max/2);
            }
            // cout << "MAX "  << max << endl;
            // cout << "q size " << q.size() << "  and now array " ;for(int j = 0; j <= n; j++) cout << a[j] << " " ;
            // cout << endl; 
        }
        cout << max << endl;
    }
}