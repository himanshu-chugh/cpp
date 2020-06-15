#include<bits/stdc++.h>
#define ll long long int 
#define vl vector<ll>
using namespace std;

// bool mycompare(vector<ll>& a, vector<ll>& b) {
//     return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
// }
// ll orientation(vector<ll>& a, vector<ll>& b, vector<ll>& c) {
//     return (b[0] - a[0])*(c[1] - b[1]) - (b[1] - a[1])*(c[0] - b[0]);
// }
// vector<vector<ll>> outerTrees(vector<vector<ll>>& polls) {
//     ll n = polls.size();
//     vector<vector<ll>> ans;
//     sort(polls.begin(), polls.end(), mycompare);
//     for (ll i = 0; i < n; ++i) {
//         while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), polls[i]) < 0) 
//             ans.pop_back();
//         ans.push_back(polls[i]);
//     }
//     if (ans.size() == n) return ans;
//     for (ll i = n-2; i >= 0; --i) {
//         while (ans.size() > 1 && orientation(ans[ans.size()-2], ans.back(), polls[i]) < 0) 
//             ans.pop_back();
//         ans.push_back(polls[i]);
//     }
//     ans.pop_back();
//     return ans;
// }


using namespace std; 
  
struct Point { 
  
    ll x, y; 
  
    bool operator<(Point p) 
    { 
        return x < p.x || (x == p.x && y < p.y); 
    } 
}; 
  
// Cross product of two vectors OA and OB 
// returns positive for counter clockwise 
// turn and negative for clockwise turn 
ll cross_product(Point O, Point A, Point B) 
{ 
    return (A.x - O.x) * (B.y - O.y) 
           - (A.y - O.y) * (B.x - O.x); 
} 
  
// Returns a list of points on the convex hull 
// in counter-clockwise order 
vector<Point> convex_hull(vector<Point> A) 
{ 
    int n = A.size(), k = 0; 
  
    if (n <= 3) 
        return A; 
  
    vector<Point> ans(2 * n); 
  
    // Sort points lexicographically 
    sort(A.begin(), A.end()); 
  
    // Build lower hull 
    for (int i = 0; i < n; ++i) { 
  
        // If the point at K-1 position is not a part 
        // of hull as vector from ans[k-2] to ans[k-1]  
        // and ans[k-2] to A[i] has a clockwise turn 
        while (k >= 2 && cross_product(ans[k - 2],  
                          ans[k - 1], A[i]) <= 0) 
            k--; 
        ans[k++] = A[i]; 
    } 
  
    // Build upper hull 
    for (size_t i = n - 1, t = k + 1; i > 0; --i) { 
  
        // If the point at K-1 position is not a part 
        // of hull as vector from ans[k-2] to ans[k-1]  
        // and ans[k-2] to A[i] has a clockwise turn 
        while (k >= t && cross_product(ans[k - 2], 
                           ans[k - 1], A[i - 1]) <= 0) 
            k--; 
        ans[k++] = A[i - 1]; 
    } 
  
    // Resize the array to desired size 
    ans.resize(k - 1); 
  
    return ans; 
}


///////////////////////////////////////////////////////////////////////
// ll orient(vl &p, vl &q, vl &r) {
//     ll val = (q[1] - p[1]) * (r[0] - q[0]) -
//               (q[0] - p[0]) * (r[1] - q[1]);
  
//     if (val == 0) return 0;  // colinear
//     return (val > 0)? 1: 2; // clock or counterclock wise
// }

ll orient(Point &p ,Point &q , Point &r) {
    ll val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool onSegment(Point &p, Point &q, Point &r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}



bool doIntersect(Point &p1, Point &q1, Point &p2, Point &q2) {
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

bool isInside(vector<Point> &polygon, Point &p) {
    ll n = polygon.size();
    if (n < 3)  return false;
    // vector<Point> extreme(2,0);
    Point extreme = p;
    extreme.x = INT_MAX;
    // extreme[0] = INT_MAX;
    // extreme[1] = p[1];
    
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

// bool collinear(vector<Point> &hull){
//     Point p1 = hull[0]  , p3 = hull.back() , p2 = hull[1] ;
//     ll val = orient(p3 , p1 , p2);
//     ll val = (q[1] - p[1]) * (r[0] - q[0]) -
//               (q[0] - p[0]) * (r[1] - q[1]);
  
//     if (val == 0) return 0;  // colinear
//     return (val > 0)? 1: 2; // clock or counterclock wise
// }

// bool colinearcheck(Point.x)
int main(){
    int t;
    cin >> t;
    while(t--){
        ll n , q;
        cin >> n >> q;
        vector<Point> points;
        for(int i = 0; i < n; i++){
            int x , y;
            cin  >> x >> y;
            Point p;
            p.x = x;
            p.y = y;
            points.push_back(p);
        }
        vector<vector<Point>> polygons;
        while(points.size()>2){
            vector<vector<ll>> res; 
            sort(points.begin(),points.end());
            vector<Point> polygon = convex_hull(points);
            Point p1 = polygon[0] ,p2 = polygon[1] ,p3 = polygon.back();
            bool colinear = colinearcheck(p1 ,p2 ,p3);
            if(colinear){
                break;
            }
            polygons.push_back(polygon);
            vector<Point> newv;
            for(int i  = 0; i < points.size(); i++){
                if(isInside(polygon , points[i])){
                    newv.push_back(points[i]);
                }
            }
            points = newv;
            // std::sort(points.begin(), points.end());
            // std::sort(polygon.begin(), polygon.end());
            // set_symmetric_difference(points.begin() , points.end() , polygon.begin(),polygon.end(),back_inserter(res));
            // points = res;
            // for(int i = 0; i<points.size(); i++){
                // cout << points[i][0] << " " << points[i][1] << ", ";
            // }
            // cout << endl;
        }
        cout <<"pppppp" <<  polygons.size() << endl ;
        for(int i = 0; i< polygons.size(); i++){
            for(int j = 0; j<polygons[i].size(); j++){
                cout << polygons[i][j][0] << " " << polygons[i][j][1] << endl;
            }
            cout << endl << endl;
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