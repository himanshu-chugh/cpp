#include<bits/stdc++.h>
using namespace std;
class my
{
public:
	long long val;
	int last;
	int c;
	my()
	{
		c=0;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],pa[n+1];
		long long ans = 0;
		unordered_map<int,my> map;

		for(int i=0;i<n;i++)
			cin>>a[i];
		pa[0]=0;
		pa[1]=a[0];		
		for(int i=2;i<=n;i++)
			pa[i]=pa[i-1]^a[i-1];

		for(int i = 0; i < n; i++){
			cout << pa[i] << " ";
		}
		cout << endl;
		for(int i=0;i<=n;i++)
		{
			if(map[pa[i]].c==0)
			{

				map[pa[i]].val=0;
				map[pa[i]].last=i;
				map[pa[i]].c++;
				// cout<<map[pa[i]].val<<" "<<map[pa[i]].last<<" "<<map[pa[i]].c<<endl;
				continue;			
			}
// 		cout<<ans<<endl;
            
			ans+= map[pa[i]].val + (map[pa[i]].c - 1)*(i- map[pa[i]].last) +(i- map[pa[i]].last -1 );
// 		cout<<ans<<endl;
			map[pa[i]].val= map[pa[i]].val + (map[pa[i]].c - 1)*(i- map[pa[i]].last) + (i- map[pa[i]].last -1);
			map[pa[i]].last=i;
			map[pa[i]].c++;		
		}

		cout<<ans<<endl;
	}
}