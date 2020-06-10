#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define mod 1000000007
#define inf 1e18
#define mk(arr,n,type)  type *arr = new type[n]
#define w(test)    int test; cin>>test; while(test--)
#define forn(i) for(int i=0;i<n;i++)
#define mem(a,b)    memset(a,(b),sizeof(a))
#define all(cont)   cont.begin(),cont.end()

vector<pl> tr;
int main(){
    ll temp;
    cin>>temp;
    tr.pb({1,temp});
    char curr1, curr2;
    while(1){
        sort(all(tr));
        vector<pl> temp;
        ll size1 = 0;
        for(auto i:tr)  size1 = size1 + i.ss - i.ff + 1;
        ll val1 = size1 / 2;
        ll midVal1;
        ll midVal2;
        ll i;
        for(i=0;i<tr.size();i++){
            if(val1 > tr[i].ss - tr[i].ff + 1) val1 = val1 - (tr[i].ss - tr[i].ff + 1);
            else{
                midVal1 = tr[i].ff + val1 - 1;
                break;
            }
        }
        cout<<midVal1<<endl;
        cin>>curr1;
        if(curr1 == 'E' )   return 0;
        if(curr1 == 'L'){
            for(ll x=0;x<i;x++)    temp.pb(tr[x]);
            if(midVal1 - 1 >= tr[i].ff)    temp.pb({tr[i].ff, midVal1-1});
            ll size2 = 0;
            midVal1++;
            if(midVal1 <= tr[i].ss)  size2 = tr[i].ss - midVal1 + 1;
            for(ll j = i+1;j<tr.size();j++)    size2 = size2 + tr[j].ss - tr[j].ff + 1;
            ll val2 = size2/2;
            ll k = i;
            if(val2 > tr[i].ss - midVal1+1){
                val2 = val2 - (tr[i].ss - midVal1+1);
                for(k=i+1;k<tr.size();k++){
                    if(val2 > tr[k].ss - tr[k].ff + 1)    val2 = val2 - (tr[k].ss - tr[k].ff + 1);
                    else{
                        midVal2 = tr[k].ff + val2 - 1;
                        break;
                    }
                }
            }
            else    midVal2 = midVal1 + val2-1;
            cout<<midVal2<<endl;
            cin>>curr2;
            if(curr2 == 'E')  return 0;
            if(curr2 == 'L'){
                if(k==i)    temp.pb({midVal1,midVal2-1});
                else{
                    if(midVal1 <= tr[i].ss)  temp.pb({midVal1,tr[i].ss});
                    for(ll x = i+1;x<k;x++) temp.pb(tr[x]);
                    if(midVal2 - 1 >= tr[k].ff)    temp.pb({tr[k].ff , midVal2-1});
                }
                
            }
            if(curr2 == 'G'){
                if(midVal2+1 <= tr[k].ss)    temp.pb({midVal2+1, tr[k].ss});
                for(ll x = k+1;x<tr.size();x++)    temp.pb(tr[x]);
            }
            
        }
        if(curr1 == 'G'){
            if(midVal1 + 1 <= tr[i].ss)    temp.pb({midVal1+1,tr[i].ss});
            for(ll x = i+1;x<tr.size();x++)    temp.pb(tr[x]);
            ll size2 = 0;
            midVal1--;
            for(int j = 0;j<i;j++)    size2 = size2 + tr[j].ss - tr[j].ff + 1;
            if(tr[i].ff <= midVal1)    size2 = midVal1 - tr[i].ff + 1;
            ll val2 = size2/2;
            ll midVal2;
            
            ll k;
            for(k = 0;k<=i;k++){
                if(val2 > tr[k].ss - tr[k].ff + 1)    val2 = val2 - (tr[k].ss - tr[k].ff + 1);
                else{
                    midVal2 = tr[k].ff + val2 - 1;
                    break;
                }
            }
            cout<<midVal2<<endl;
            cin>>curr2;
            if(curr2 == 'E')  return 0;
            if(curr2 == 'L'){
                for(ll x = 0;x<k;x++)   temp.pb(tr[x]);
                if(midVal2 - 1 >= tr[k].ff)    temp.pb({tr[k].ff,midVal2-1});
            }
            if(curr2 == 'G'){
                if(k==i)    temp.pb({midVal2+1,midVal1-1});
                else{
                    if(tr[k].ss >= midVal2+1)    temp.pb({midVal2+1,tr[k].ss});
                    for(ll x = k+1;x<i;x++)    temp.pb(tr [x]);
                    if(midVal1 - 1 >= tr[i].ff)    temp.pb({tr[i].ff, midVal1-1});
                }
                
            }
        }
        tr.clear();
        tr = temp;
    }
    
}