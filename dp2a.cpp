#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int helper(int **input, int m, int n, int **a = NULL , int x = 0 , int y = 0) {
    if(m-1 == x && n-1 == y){
        a[x][y] = input[x][y];
        return input[x][y];
    }
    if(a[x][y] != INT_MAX){
        return a[x][y];
    }
    int mini = INT_MAX;
    if(x < m-1){
        mini = min(mini ,helper(input , m , n , a , x+1 , y));
    }
    if(y < n-1){
        mini = min(mini , helper(input , m , n , a , x , y+1));
    }
    if(x < m-1 && y < n-1){
        mini = min(mini , helper(input , m , n  , a , x+1 , y+1));
    }
    a[x][y] = input[x][y] + mini;
    return input[x][y] + mini;
}


int minCostPath(int **input , int m , int n , int x = 0 , int y = 0){
    if(m-1 == x && n-1 == y){
        return input[x][y];
    }
    int **b = new int*[m];
    for(int i = 0; i < m; i++){
        b[i] = new int[n];
    }
    for(int i = 0 ; i < m; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = INT_MAX;
        }
    }
    return helper(input , m , n , b );
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m , 0, 0) << endl;
}
