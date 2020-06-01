#include<stdio.h>
#include<bits/stdc++.h>
typedef int lli;
using namespace std;

int getMostWork(vector <int> v, int m)
{
 
 int l=0,r=0;
 int size=v.size();
 for(int i=0;i<size;i++)
 {
  r+=v[i];
 }
 
 for(int i=0;i<size;i++)
  {
   l=max(l,v[i]);
  }
  
  int ret=r;
  int ff=0;
  while(l<=r)
   {
    if(l==r) ff=1;
      int mid=(l+r)/2;
      int cov=1;
      int sum=0;
      for(int i=0;i<size;i++)
       {
         if(sum+v[i]>mid)
          {
            cov++;
            sum=v[i];
     }
     else
     {
        sum+=v[i];
     }
         
    }
    
   //  cout<<" l "<<l<<" "<<r<<"  count "<<cov<<" mid "<<mid<<endl;
    if(cov<=m)
     {
       //if(cov==m)
        ret=min(ret,mid);
        r=mid;
     }
     else
     {
       l=mid+1;
     }
     if(ff==1) break;
   }
   return ret;
 
}



int arr[1000000];
int main()
{
 int t;
 cin>>t;
  while(t--)
   {
    int n,m;
     cin>>n>>m;
     vector<int> v;
     for(int i=0;i<n;i++)
       {
        int a;
         cin>>a;
         v.push_back(a);
     }
     
     int ans=getMostWork(v,m);
      cout<<ans<<endl;
   }
  

} 