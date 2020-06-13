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
#define inf 1e18
#define min3(a,b,c)   min(a,min(b,c))
#define max3(a,b,c)   max(a,max(b,c))

bool mycompare(vl & a, vl & b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}

ll orientation(vl &a, vl &b, vl &c) {
    return (b[0] - a[0])(c[1] - b[1]) - (b[1] - a[1])(c[0] - b[0]);
}

vector<vl> outerTrees(vector<vl>& points) {
        // Andrew's monotone chain method
        ll n = points.size();
        vector<vl> ans;
        boot notposs = true;
        for(int i=0;i<points.size()-1;i++)  
            if(orient(points[i],points[i+1]) != 0 ){ 
                notposs = false;
                break;
            }
        if(notposs) return ans;
        sort(points.begin(), points.end(), mycompare);
        // left to right
        for (ll i = 0; i < n; ++i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        // if all points along a line, ans.size() is n after left to right procedure
        if (ans.size() == n) return ans;
        // right to left
        for (ll i = n-2; i >= 0; --i) {
            while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), points[i]) < 0) 
                ans.pop_back();
            ans.push_back(points[i]);
        }
        ans.pop_back();
        return ans;
    }


bool onSegment(vl p, vl q, vl r) {
    if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) &&
            q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1]))
        return true;
    return false;
}

ll orient(vl p, vl q, vl r) {
    ll val = (q[1] - p[1]) * (r[0] - q[0]) -
              (q[0] - p[0]) * (r[1] - q[1]);
  
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(vl p1, vl q1, vl p2, vl q2) {
    ll o1 = orient(p1, q1, p2);
    ll o2 = orient(p1, q1, q2);
    ll o3 = orient(p2, q2, p1);
    ll o4 = orient(p2, q2, q1);
  
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
  
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
  
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false; // Doesn't fall in any of the above cases
}

bool isInside(vector<vl> polygon, vl p) {
    ll n = polygon.size();
    if (n < 3)  return false;
    vl extreme(2,0);
    extreme[0] = INT_MAX;
    extreme[1] = p[1];
    
    ll count = 0, i = 0;
    do{
        int next = (i+1)%n;
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            if (orient(polygon[i], p, polygon[next]) == 0)
               return false;
  
            count++;
        }
        i = next;
    } while (i != 0);
    return count%2 == 1;  // Same as ()
}



int main(){
    w(test){
        ll n,q;
        cin>>n>>q;
        vector<vl> points(n,vl(2,0));
        forn(i) cin>>points[i][0] >> points[i][1];
        vector< vector< vl > > region;
        while(1){
            vector<vl> ans = outerTrees(points);
            if(ans.size()==0)   break;
            region.pb(ans);
            vector<vl> newpoints;
            for(ll i=0;i<points.size();i++){
                bool found = false;
                for(ll j=0;j<ans.size();j++){
                    if(ans[j][0] == points[i][0] && ans[j][1] == points[i][1]){
                        found = true;
                        break;
                    }
                }
                if(!found)  newpoints.pb(points[i]);
            }
            points.clear();
            points = newpoints;
        }
        reverse(all(region));
        while(q--){
            ll layers = 0;
            vl candle(2,0);
            cin>>candle[0]>>candle[1];
            bool found = false;
            for(ll i=0;i<region.size();i++){
                if(isInside(region[i],candle)){
                    layers = region.size() - i;
                    found = true;
                    break;
                }
            }
            if(found)    cout<<layers<<endl;
            else    cout<<0<<endl;
        }
    }
}