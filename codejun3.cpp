#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin  >> t;
    while(t--){
        int n;
        cin  >> n;
        int a[n];
        int coins[3] = {0};
        bool ans = 1;
        for(int  i =0; i< n; i++){
            cin >> a[i];
        }
        for(int i=0; i< n; i++){
            // cin >> a[i];
            if(a[i] == 5){
                coins[0]++;
            }
            else if(a[i] == 10){
                if(coins[0] <=  0){
                    // cout << "NO" << endl;
                    ans = 0;
                    break;
                }
                else{
                    coins[0]--;
                    coins[1]++;
                }
            }
            else{
                if(coins[0] > 1 or coins[1] > 0){
                    if(coins[1] > 0){
                        coins[1]--;
                        coins[2]++;
                    }
                    else{
                        coins[0]--;
                        coins[0]--;
                        coins[2]++;
                    }
                }
                else{
                    // cout << "NO" << endl;
                    ans = 0;
                    break;
                }
            }
        }
        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}