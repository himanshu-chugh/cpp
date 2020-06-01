#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int*a = new int[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(n == 1 || n == 2 || n == 3){
            cout << "YES" << endl;
            continue;
        }
        bool flag = 0;
        int now = a[1] - a[0];
        for(int i = 1; i < n; i++){
            now = a[i] - a[i-1];
            if(!(abs(now) == n-1 || abs(now) == 1)){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }


        delete[] a;
    }
}