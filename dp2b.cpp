#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int helper(int **input , int m ,int n ,int x , int y, int **output){
    
    output[x][y] = INT_MAX;
    if(x < m){
        output[x][y] = min(output[x][y] , output[x+1][y]);
    }
    if(y < n){
        output[x][y] = min(output[x][y] , output[x][y+1]);
    }
    if(y < n && x < m){
        output[x][y] = min(output[x][y] , output[x+1][y+1]);
    }
    return (output[x][y] + input[x][y]);
}
int minCostPath(int **input, int m, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int **b = new int*[m];
    for(int i = 0; i < m; i++){
        b[i] = new int[n];
    }
    // CALL FOR LAST ROW AND LAST COLUMN
    b[m-1][n-1] = input[m-1][n-1];
    for(int i = m-2 ; i >=0 ; i--){
        b[i][n-1] = b[i+1][n-1] + input[i][n-1];
    }
    for(int i = n-2 ; i >=0 ; i--){
        b[m-1][i] = b[m-1][i+1] + input[m-1][i];
    }
    // CALLING FOR INNER MATRIXS ONLY 
/* 
*/
    for(int i = m-2; i >= 0; i--){
        for(int j = n-2; j >= 0; j--){
            cout << " calling for i:" << i << " and j:" << j ;
            b[i][j] = helper(input , m , n, i , j ,b);        
            cout << endl;
            for(int i = 0 ; i < m; i++){
                for(int j = 0 ; j < n ; j++){
                    cout << b[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    for(int i = 0 ; i < m; i++){
        for(int j = 0 ; j < n ; j++){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return b[0][0];
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
