#include<bits/stdc++.h>
using namespace std; 
// #define INT_MAX INT_MAX;

struct Point 
{ 
    int x, y; 
}; 
  
Point p0; 

bool onSegment(Point p, Point q, Point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
        return true; 
    return false; 
} 

Point nextToTop(stack<Point> &S) 
{ 
    Point p = S.top(); 
    S.pop(); 
    Point res = S.top(); 
    S.push(p); 
    return res; 
} 
  
int swap(Point &p1, Point &p2) 
{ 
    Point temp = p1; 
    p1 = p2; 
    p2 = temp; 
} 
  
int distSq(Point p1, Point p2) 
{ 
    return (p1.x - p2.x)*(p1.x - p2.x) + 
          (p1.y - p2.y)*(p1.y - p2.y); 
} 
  
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 
  
int compare(const void *vp1, const void *vp2) 
{ 
   Point *p1 = (Point *)vp1; 
   Point *p2 = (Point *)vp2; 
  
   int o = orientation(p0, *p1, *p2); 
   if (o == 0) 
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1; 
  
   return (o == 2)? -1: 1; 
} 
  
vector<Point> convexHull(Point points[], int n) 
{ 
   int ymin = points[0].y, min = 0; 
   for (int i = 1; i < n; i++) 
   { 
     int y = points[i].y; 
     if ((y < ymin) || (ymin == y && 
         points[i].x < points[min].x)) 
        ymin = points[i].y, min = i; 
   } 
  
   swap(points[0], points[min]); 
  
   p0 = points[0]; 
   qsort(&points[1], n-1, sizeof(Point), compare); 

   int m = 1; // Initialize size of modified array 
   for (int i=1; i<n; i++) 
   { 
       while (i < n-1 && orientation(p0, points[i], 
                                    points[i+1]) == 0) 
          i++; 
  
  
       points[m] = points[i]; 
       m++;  // Update size of modified array 
   } 
  
   if (m < 3) return; 
  
   stack<Point> S; 
   S.push(points[0]); 
   S.push(points[1]); 
   S.push(points[2]); 
  
   for (int i = 3; i < m; i++) 
   { 
      while (orientation(nextToTop(S), S.top(), points[i]) != 2) 
         S.pop(); 
      S.push(points[i]); 
   } 
    vector<Point> ans;
   while (!S.empty()) 
   { 
       Point p = S.top(); 
        ans.push_back(p);
       S.pop(); 
   } 
   return ans;
} 

bool doIntersect(Point p1, Point q1, Point p2, Point q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
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



bool isInside(Point polygon[], int n, Point p) 
{ 
    // There must be at least 3 vertices in polygon[] 
    if (n < 3)  return false; 
  
    // Create a point for line segment from p to INT_MAXinite 
    Point extreme = {INT_MAX, p.y}; 
  
    // Count intersections of the above line with sides of polygon 
    int count = 0, i = 0; 
    do
    { 
        int next = (i+1)%n; 
  
        // Check if the line segment from 'p' to 'extreme' intersects 
        // with the line segment from 'polygon[i]' to 'polygon[next]' 
        if (doIntersect(polygon[i], polygon[next], p, extreme)) 
        { 
            // If the point 'p' is colinear with line segment 'i-next', 
            // then check if it lies on segment. If it lies, return true, 
            // otherwise false 
            if (orientation(polygon[i], p, polygon[next]) == 0) 
               return onSegment(polygon[i], p, polygon[next]); 
  
            count++; 
        } 
        i = next; 
    } while (i != 0); 
  
    // Return true if count is odd, false otherwise 
    return count&1;  // Same as (count%2 == 1) 
}


int main() 
{ 
    int t;
    cin >> t;
    while(t--){
        int n , q;
        cin >> n >> q;
        Point *points = new Point[n];
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            points[i].x = x;
            points[i].y = y;
        }
        convexHull(points, n); 
        delete[] points;
    }
    return 0; 
} 