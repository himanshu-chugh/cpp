#include<iostream> 
#include<cmath> 
using namespace std;
 


int main(){
    long long int a[60];
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i < 60; i++){
        a[i] = a[i-1] + a[i-2];
    }
    for(int i = 0; i < 60; i++){
        a[i] = a[i]%10;
    }
    long long int n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        n = log2l(n);
        n = powl(2 , n);
        n = n%60;
        cout << a[n-1] << endl;
        // cout << n << "th fabbo : " ;
        // cout << fib(n-1)%10  << endl;
    }
    return 0;
}