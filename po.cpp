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

list<pl> tr;
int main(){
    ll temp;
    cin>>temp;
    tr.pb(mp(1,temp));
    char curr,curr2;
    while(!tr.empty()){
        pl region = tr.front();
        tr.pop_front();
        if(region.ff > region.ss)   continue;
        int mid = (region.ff + region.ss)/2;
        cout<<mid<<endl;
        cin>>curr;
        if(curr == 'E')   return 0;
        if(curr == 'G'){
            tr.pb(mp(mid+1,region.ss));
            int mid2 = (region.ff + mid-1)/2;
            cout<<mid2<<endl;
            cin>>curr2;
            if(curr2 == 'E')   return 0;
            if(curr2 == 'L')   tr.pb(mp(region.ff, mid2-1));
            if(curr2 == 'G')   tr.pb(mp(mid2+1, mid-1));
        }
        else{
            tr.pb(mp(region.ff, mid - 1));
            int mid2 = (mid+1 + region.ss)/2;
            cout<<mid2<<endl;
            cin>>curr2;
            if(curr2 == 'E')   return 0;
            if(curr2 == 'L')   tr.pb(mp(mid+1, mid2-1));
            if(curr2 == 'G'1)   tr.pb(mp(mid2+1, region.ss));
        }
    }
}