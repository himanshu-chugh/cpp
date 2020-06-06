#include<bits/stdc++.h>
using namespace std;

    int firstUniqChar(string s) {
        if(s.length() == 0){
            return -1;
        }
        queue<int> q;
        int a[26] = {0};
        int latest = s.length()-1;
        for(int i = s.length()-1;  i >= 0; i--){
            int index = s[i] - 'a' ;
            a[index]++;
            if(a[index] == 1){
                latest = i;
                q.pu
            }
        }
        for(int i = 0; i < 26; i++){
            cout << a[i] << " " ;
        }
        cout << endl;
        int index = s[latest] -'a';
        cout << "checking index " << index << endl;
        if(a[index] == 1){
            return latest;
        }
        return -1;
    }


int main(){
    string s;
    getline(cin , s);
    cout << firstUniqChar(s) << endl;
    return 0;
}