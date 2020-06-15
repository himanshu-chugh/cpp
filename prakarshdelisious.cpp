#include <bits/stdc++.h> 
#define ll long long int 
using namespace std; 

struct Point { 

	ll x, y; 

	bool operator<(Point p) 
	{ 
		return x < p.x || (x == p.x && y < p.y); 
	} 
}; 

struct line {
   Point p1, p2;
};

bool onLine(line l1, Point p) {        //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
         return true;

   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;           //colinear
   else if(val < 0)
      return 2;          //anti-clockwise direction
      return 1;          //clockwise direction
}

bool isIntersect(line l1, line l2) {
   //four direction for two lines and points of other line
   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;           //they are intersecting
   if(dir1==0 && onLine(l1, l2.p1))        //when p2 of line2 are on the line1
      return true;
   if(dir2==0 && onLine(l1, l2.p2))         //when p1 of line2 are on the line1
      return true;
   if(dir3==0 && onLine(l2, l1.p1))       //when p2 of line1 are on the line2
      return true;
   if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return true;
   return false;
}

bool checkInside(vector<Point> &poly, int n, Point p) {
   if(n < 3)
      return false;                  //when polygon has less than 3 edge, it is not polygon
   line exline = {p, {9999, p.y}};   //create a point at infinity, y is same as point p
   int count = 0;
   int i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};     //forming a line from two consecutive points of poly
      if(isIntersect(side, exline)) {          //if side is intersects exline
         if(direction(side.p1, p, side.p2) == 0)
            return onLine(side, p);
         count++;
      }
      i = (i+1)%n;
   } while(i != 0);
      return count&1;             //when count is odd
}


ll cross_product(Point O, Point A, Point B) 
{ 
	return (A.x - O.x) * (B.y - O.y) 
		- (A.y - O.y) * (B.x - O.x); 
} 

vector<Point> convex_hull(vector<Point> A) 
{ 
	int n = A.size(), k = 0; 

	if (n <= 3) 
		return A; 

	vector<Point> ans(2 * n); 
	sort(A.begin(), A.end()); 
	for (int i = 0; i < n; ++i) { 

		while (k >= 2 && cross_product(ans[k - 2], 
						ans[k - 1], A[i]) <= 0) 
			k--; 
		ans[k++] = A[i]; 
	} 

	for (size_t i = n - 1, t = k + 1; i > 0; --i) { 
		while (k >= t && cross_product(ans[k - 2], 
						ans[k - 1], A[i - 1]) <= 0) 
			k--; 
		ans[k++] = A[i - 1]; 
	} 
	ans.resize(k - 1); 
	return ans; 
} 

int main() 
{ 
	int t;
    cin >> t;
    while(t--)
    {
    	ll n , q;
        cin >> n >> q;
		vector<Point> points; 
		for(int i = 0; i < n; i++){
            Point abc;
            cin  >> abc.x >> abc.y;
            points.push_back(abc);
        }
        vector< vector<Point> > store;
        while(points.size()>=3)
        {
			vector<Point> hull = convex_hull(points);
			store.push_back(hull);
            // for(auto it:hull){
                
            //         cout << it.x << " " << it.y << ", ";
                
            //     // cout << endl;
            // }
            // cout << endl << endl ;
			vector<Point> temp(points);
			points.clear(); 
			for(auto it:temp)
			{
				if(checkInside(hull, hull.size() , it))
				{
					points.push_back(it);
				}
			}
        }
       for(int i=0;i<q;i++)
        {
        	ll res=0;
        	Point abc;
        	cin>>abc.x>>abc.y;
        	for(auto it:store)
        	{
        		if(checkInside(it , it.size(),abc))
        			res++;
        		else
        			break;
        	}
        	cout<<res<<endl;
        }

    }

	return 0; 
}