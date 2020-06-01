#include<bits/stdc++.h>
#include<string>
using namespace std;

int fun(string s1 , string s2 , int ** a){
    int l1 = s1.length() , l2 = s2.length();
    if(s1.length() == 0 || s2.length() == 0){
        return max(s1.length() , s2.length());
    }
    if(s1[0] == s2[0]){
        a[l1][l2] = a[l1-1][l2-1];
        return a[l1][l2];
    }
    int ans1 = min( a[l1-1][l2-1]  ,  min(  a[l1][l2-1]  , a[l1-1][l2]));
    // a[l1][l2] = ans1 + 1;
    return ans1 + 1;

}
int main(){
    int t;
    cin >> t;
    while(t--){
        int p, q;
        cin >> p >> q;
        string s1 ,s2;
        cin >> s1 >> s2;
        int len1 = s1.length() + 1;
        int len2 = s2.length() + 1;
        int **a = new int*[len1];
        for(int i = 0; i <= s1.length(); i++){
            a[i] = new int[len2];
        }
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                a[i][j] = -1;
            }
        }
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                a[i][j] = fun(s1.substr(len1-1-i) , s2.substr(len2-1-j) ,a);
                // cout << s1.substr(len1-1-i) << " " << s2.substr(len2-1-j) << endl;
            }
        }
        cout << a[len1-2][len2-2] << endl;
        // for(int i = 0; i < len1; i++){
        //     for(int j = 0; j < len2; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i = 0; i <= s1.length(); i++){
            delete[] a[i];
        }
        delete[] a;
    }
    return 0;
}