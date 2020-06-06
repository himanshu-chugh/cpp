#include<bits/stdc++.h>
using  namespace std;
int main(){
    int t;
    cin  >> t;
    while(t--){
        long long int n;
        cin >> n;
        int **a = new int*[n];
        for(int i = 0; i < n; i++){
            a[i] = new int[n];
        }
        int p = 1;
        
        if(n%2){
            for(int i =0; i< n; i++){
                for(int j =0; j < n; j++){
                    a[i][j] = p++;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(i%2 == 0){
                    for(int j = 0; j  < n; j++){
                        a[i][j] = p++;
                    }
                }
                else{
                    for(int j = n-1; j>=0;j--){
                        a[i][j]  = p++;
                    }
                }
            }
        }

        for(int  i = 0; i< n;i++){
            for(int j = 0; j < n;  j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        
            // cout << endl;
        for(int i =0; i< n;  i++){
            delete[] a[i];
        }
        delete[] a;
        
    }
}