#include<bits/stdc++.h>
using  namespace std;
int main(){
    int t;
    cin  >> t;
    while(t--){
        long long int n;
        cin >> n;
        if(n%2 == 1){
            cout << n/2 << endl;
        }
        else{
            // int level = 0;
            // long long int temp  = 2;
            do{
                n /= 2;
                // level++;
            }while(n %2 == 0);
            cout << n/2  << endl;
        }
    }
}