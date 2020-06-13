#include<bits/stdc++.h>
#define ll long long int 
#define vl vector<ll>
using namespace std;

bool mycompare(vector<ll>& a, vector<ll>& b) {
    return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
}
ll orientation(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
    return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
}
vector<vector<ll>> outerTrees(vector<vector<ll>>& polls) {
    ll n = polls.size();
    vector<vector<ll>> ans;
    sort(polls.begin(), polls.end(), mycompare);
    for (ll i = 0; i < n; ++i) {
        while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), polls[i]) < 0) 
            ans.pop_back();
        ans.push_back(polls[i]);
    }
    if (ans.size() == n) return ans;
    for (ll i = n-2; i >= 0; --i) {
        while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), polls[i]) < 0) 
            ans.pop_back();
        ans.push_back(polls[i]);
    }
    ans.pop_back();
    return ans;
}



///////////////////////////////////////////////////////////////////////
ll orient(vl p, vl q, vl r) {
    ll val = (q[1] - p[1]) * (r[0] - q[0]) -
              (q[0] - p[0]) * (r[1] - q[1]);
  
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool onSegment(vl p, vl q, vl r) {
    if (q[0] <= max(p[0], r[0]) && q[0] >= min(p[0], r[0]) &&
            q[1] <= max(p[1], r[1]) && q[1] >= min(p[1], r[1]))
        return true;
    return false;
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

///////////////////////////////////////////////////////////////////////




int main(){
    int t;
    cin >> t;
    while(t--){
        ll n , q;
        cin >> n >> q;
        vector<vector<ll>> points;
        for(int i = 0; i < n; i++){
            int x , y;
            cin  >> x >> y;
            vector<ll> v;
            v.push_back(x);
            v.push_back(y);
            points.push_back(v);
        }
        vector<vector<vector<ll>>> polygons;
        while(points.size()>2){
            vector<vector<ll>> res; 
            sort(points.begin(),points.end());
            vector<vector<ll>> polygon = outerTrees(points);
            polygons.push_back(polygon);
            set_symmetric_difference(points.begin() , points.end() , polygon.begin(),polygon.end(),back_inserter(res));
            points = res;
        }
        for(int i = 0; i< q; i++){
            int  x, y;
            cin >> x >> y;
            vl vv;
            vv.push_back(x);
            vv.push_back(y);
            int ans = polygons.size();
            for(int i = polygons.size()-1; i>=0 ; i--){
                bool tt = isInside(polygons[i] , vv);
                if(tt){
                    break;
                }
                else{
                    ans--;
                }
            }
            cout << ans <<endl;
        }

    }
}