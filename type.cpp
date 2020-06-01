#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int fab(int n){
    if(n == 1 || n == 0){
        return n;
    }
    return fab(n - 1) + fab(n - 2);
}
int main(){
    for(int i = 0 ; i < 100; i++){
        int n = 45 ;
        cout << "fact of " << i << " : " ;
        auto start = high_resolution_clock::now();
        cout << fab(n) << endl;
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start); 
        cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
        cout << endl;
    }
    return 0;
}