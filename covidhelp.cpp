#include<bits/stdc++.h>
using namespace std;


int ans[61][61] = {0};

void q2(){
    int a[61][61] = {0};
    for(int i =1; i<= 31; i++){
        for(int j = 1; j <= 31; j++){
            cout << 1 << ' ' << i << ' ' << j  << ' ' << 60 << " "  << 60 << endl;
            // cin >> a[i][j];
            // if(a[i][j] == -1){
            //     exit(1);
            // }
        }
    }
    for(int i =1; i<31; i++){
        for(int j = 1; j<31; j++){
            ans[i][j] = a[i][j] - (a[i+1][j] + a[i][j+1] - a[i+1][j+1]);
        }
    }
}

void q3(){
    int a[61][61] = {0};
    for(int i = 30; i < 61; i++){
        for(int j = 1; j <= 31; j++){
            cout << 1 << ' ' << 1 << ' ' << j  << ' ' << i << " "  << 60 << endl;
            // cin >> a[i][j];
            // if(a[i][j] == -1){
            //     exit(1);
            // } 
        }
    }
    for(int i = 31; i <= 60; i++){
        for(int j = 1; j <= 30; j++){
            ans[i][j] = a[i][j] - (a[i-1][j] + a[i][j+1] - a[i-1][j+1]);
        }
    }
}
void q4(){
    int a[61][61] = {0};
    for(int i = 30; i<=60; i++){
        for(int j = 30; j<= 60; j++){
            cout << 1 << ' ' << 1 << ' ' << 1  << ' ' << i << " "  << j << endl;
            // cin >> a[i][j];
            // if(a[i][j] == -1){
            //     exit(1);
            // }
        }
    }
    for(int i = 31; i <= 60; i++){
        for(int j = 31; j<=60; j++){
            ans[i][j] = a[i][j] - (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
        }
    }
}

void q1(){
    int a[61][61] = {0};
    for(int i =1; i<= 31; i++){
        for(int j = 30; j <= 30; j++){
            cout << 1 << ' ' << i << ' ' << 1  << ' ' << 60 << " "  << j << endl;
            // cin >> a[i][j];
            // if(a[i][j] == -1){
            //     exit(1);
            // }
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 31; j <= 60; j++){
            ans[i][j] = a[i][j] - (a[i][j-1] + a[i+1][j] - a[i+1][j-1]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        // int n , p;
        // cin >> n  >> p;
        // p *= 36;
        // q2();
        q3();
        // q4();
        // q1();
    }

}