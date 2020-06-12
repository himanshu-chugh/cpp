#include<bits/stdc++.h>
using namespace std;


int ans[61][61] = {0};

int q2(){
    int a[61][61] = {0};
    for(int i =1; i<= 31; i++){
        for(int j = 1; j <= 31; j++){
            // cout << 1 << ' ' << i << ' ' << j  << ' ' << 60 << " "  << 60 << endl;
            cout << 1 << ' ' << i << ' ' << j  << ' ' << 60 << " "  << 60 << endl;
            cin >> a[i][j];
            if(a[i][j] == -1){
                exit(1);
            }
        }
    }
    int total = 0;
    for(int i =1; i<31; i++){
        for(int j = 1; j<31; j++){
            ans[i][j] = a[i][j] - (a[i+1][j] + a[i][j+1] - a[i+1][j+1]);
            if(ans[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

int  q3(){
    int a[61][61] = {0};
    for(int i = 30; i < 61; i++){
        for(int j = 1; j <= 31; j++){
            cout << 1 << ' ' << 1 << ' ' << j  << ' ' << i << " "  << 60 << endl;
            // cout << 1 << ' ' << i << ' ' << j  << ' ' << 1 << " "  << 60 << endl;
            cin >> a[i][j];
            if(a[i][j] == -1){
                exit(1);
            } 
        }
    }
    int  total = 0;
    for(int i = 31; i <= 60; i++){
        for(int j = 1; j <= 30; j++){
            ans[i][j] = a[i][j] - (a[i-1][j] + a[i][j+1] - a[i-1][j+1]);
        if(ans[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}
int q4(){
    int total = 0;
    int a[61][61] = {0};
    for(int i = 30; i<=60; i++){
        for(int j = 30; j<= 60; j++){
            cout << 1 << ' ' << 1 << ' ' << 1  << ' ' << i << " "  << j << endl;
            cin >> a[i][j];
            if(a[i][j] == -1){
                exit(1);
            }
        }
    }
    for(int i = 31; i <= 60; i++){
        for(int j = 31; j<=60; j++){
            ans[i][j] = a[i][j] - (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
            if(ans[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

int q1(){
    int total = 0;
    int a[61][61] = {0};
    for(int i =1; i<= 31; i++){
        for(int j = 30; j <= 60; j++){
            cout << 1 << ' ' << i << ' ' << 1  << ' ' << 60 << " "  << j << endl;
            cin >> a[i][j];
            if(a[i][j] == -1){
                exit(1);
            }
        }
    }
    for(int i = 1; i <= 30; i++){
        for(int j = 31; j <= 60; j++){
            ans[i][j] = a[i][j] - (a[i][j-1] + a[i+1][j] - a[i+1][j-1]);
            if(ans[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , p;
        cin >> n  >> p;
        p *= 36;
        p-= q1();
        if( p <= 0){
            goto lable;
        }
        p -= q2();
        if( p <= 0){
            goto lable;
        }
        p -= q3();
        if( p <= 0){
            goto lable;
        }
        q4();
        lable:
        cout << 2 << endl;
        for(int i = 1; i< 61; i++){
            for(int j = 1; j<61;j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        int x;
        cin >> x;
        if(x == -1){
            break;
        }
    }

}