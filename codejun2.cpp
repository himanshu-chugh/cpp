#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin , s);
        int l = s.length();
        // bool v[l] = {0};
        long long int ans  = 0 , count = 0;
        cout << s << endl;
        for(int i = 0; i< l; i++){
            cout << i  ;
        }
        cout << endl;
        for(int i = 0; i < l; i++){
            cout << i << " ";
            if(s[i] != s[i+1] and s[i+1] != '\0'){
                count++;
                i++;
            }
        }
        cout << count << endl;
    }
}