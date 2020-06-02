#include<bits/stdc++.h>
using namespace std;


int findComplement(int num) {
        string s = "";
        while(num != 0){
            if(num%2){
                s = '0'+s;
            }
            else{
                s =  '1'+s;
            }
            num /=2;
        }
        int ans = 0;
        cout << s << endl;
        int i = 0;
        // while(s[i] == 0 and i < s.length()){
        //     i++;
        // }
        for(i; i < s.length(); i++){
            int value = 0;
            if(s[i] == '1'){
                value = 1;
            }
            ans = ans*2 + value;
        }
        // cout << s << endl;
        return ans;
    }

int main(){
    int k;
    cin >> k;
    cout << findComplement(k) << endl;
    return 0;
}