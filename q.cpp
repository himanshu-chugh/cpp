#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n1 , n2, n3;
	cin >>  n1 >> n2 >> n3;
	int a[n1+n2+n3];
	for(int i = 0; i < n1+n2+n3; i++){
	    cin >> a[i];
	}
// 	for(int i = 0 ; i< n2; i++){
// 	    cin >> b[i];
// 	}
// 	for(int i = 0; i < n3; i++){
// 	    cin >> c[i];
// 	}
	sort(a , a+n1+n2+n3);
    vector<int> v;
    for(int i = 1; i< n1+n2+n3-1; i++){
        if(a[i] == a[i-1] and a[i]!= a[i+1]){
            // cout << a[i-1] << " " << a[i] << " " <<  a[i+1] << endl;
            v.push_back(a[i]);
        }
    }
    cout << v.size() << endl;
    for(int i  = 0; i<v.size(); i++){
        cout << v[i] << endl;
    }
	return 0;
}
