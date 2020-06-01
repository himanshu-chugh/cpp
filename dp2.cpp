#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n, int x = 0 , int y = 0) {
    if(m-1 == x && n-1 == y){
        return input[x][y];
    }
    int mini = INT_MAX;
    if(x < m-1){
        mini = min(mini ,minCostPath(input , m , n , x+1 , y));
    }
    if(y < n-1){
        mini = min(mini , minCostPath(input , m , n , x , y+1));
    }
    if(x < m-1 && y < n-1){
        mini = min(mini , minCostPath(input , m , n  , x+1 , y+1));
    }
    return input[x][y] + mini;
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
    cout << minCostPath(arr, n, m) << endl;
}
