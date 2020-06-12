#include<bits/stdc++.h>
using namespace std;


int solve2(int** map ){
    int total = 0;
    int a[61][61];
    for(int i = 1; i <= 31; i++){
        for(int j = 1; j <= 31; j++){
            cout << 1 << " " << i << " " << j << " " << 60 << " " << 60<< endl;
            int x;
            cin >> x;
            if(x==-1){
                exit(2);
            }
            else{
                a[i][j] = x;
            }
        }
    }
    for(int i = 1; i <= 30 ; i++){
        for(int j = 1; j <= 30 ; j++){
            map[i][j] = a[i][j] - (a[i][j+1] + a[i+1][j] - a[i+1][j+1]);
            if(map[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

int solve1(int**map  ){
    int a[61][61];
    for(int i = 1; i <= 30; i++){
        for(int j = 30; j <= 60; j++){
            cout << 1 << " " << i << " " << 1 << " " << 60 << " " << j << endl;
            int x;
            cin >> x;
            if(x==-1) exit(1);
            else{
                a[i][j] = x;
            }
        }
    }
    int total = 0;
    for(int i = 1; i <= 30 ; i++){
        for(int j = 31; j <= 60; i++){
            map[i][j] = a[i][j] - (a[i][j-1] + a[i+1][j] - a[i+1][j-1]);
            if(map[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

int solve3(int**map){
    int a[61][61];
    int total = 0;
    for(int i = 30; i<= 60; i++){
        for(int j = 1; j <= 31; j++){
            cout << 1 << " " << 1 << " " << j << " " << i << " " << 60 << endl;
            int x;
            cin >> x;
            if(x==-1) exit(1);
            else{
                a[i][j] = x;
            }
        }
    }
    for(int i = 31; i <= 60; i++){
        for(int j = 1; j <= 30 ; j++){
            map[i][j] = a[i][j] - (a[i-1][j] + a[i][j+1] - a[i-1][j+1]);
            if(map[i][j] == 1){
                total++;
            }
        }
    }
    return total;
}

void solve4(int** map){
    int a[61][61];
    for(int i = 30; i <= 60; i++ ){
        for(int j = 30; j<=60; j++){
            cout << 1 << " " << 1 << " " << 1 << " " << i << " " << j << endl;
            int x;
            cin >> x;
            if(x==-1) exit(1);
            else{
                a[i][j] = x;
            } 
        }
    }
    for(int i = 31; i <  61; i++){
        for(int  j =31; j < 61;  j++){
            map[i][j] = a[i][j]-(a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n , q;
        cin >> n >> q;
        int**a = new int*[61];
        for(int i =0; i <=  n; i++){
            a[i] = new int[61];
        }
        for(int i = 1; i <  61; i++){
            for(int j = 1; j < 61; j++){
                a[i][j] = 0;
            }
        }
        int q2  = solve2(a );
        
        int q1 = solve1(a );
        
        int q3 = solve3(a);
        
        solve4(a);
        cout << n << endl;
        for(int i =1; i<= n;i++){
            for(int j =1;  j <= n; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        for(int i =0; i<= n; i++){
            delete[] a[i];
        }
        delete[] a;
    }
}