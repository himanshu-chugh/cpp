#include <bits/stdc++.h>
using namespace std;
int getmax(queue<int> &q , int*a , int &endpointer){

    if(q.size() == 0){
        int ans = a[endpointer];
        endpointer--;
        q.push(a[endpointer+1]/2);
        return ans;
    }
    else{
        if(endpointer == -1){
            int ans = q.front();
            q.push(ans/2);
            q.pop();
            return q.front();
        }
        else if(q.front() >= a[endpointer]){
            int ans = q.front();
            q.pop();
            q.push(ans/2);
            return ans;
        }
        else{
            int ans = a[endpointer];
            endpointer--;
            q.push(ans/2);
            return ans;
        }
    }
}
int main() {
	// your code goes here
	queue<int> q;
	q.push(0);
	int n ,m;
	cin >> n >> m;
	int a[n];
	for(int i = 0; i < n; i++){
	    cin >> a[i];
	}
	sort(a , a+n);
	int endpointer = n-1;
	int count = 0;
	for(int i = 0; i < m; i++){
	    int input;
	    cin  >> input;
	    int ans = a[endpointer];
        
	    while(count != input){
	        count++;
	        ans = getmax(q , a, endpointer);
	    }
	    cout << ans << endl;
        for(int j= 0; j<= endpointer; j++){
            cout << a[j] << " ";
        }
        cout << endl;
	}
	
	return 0;
}
