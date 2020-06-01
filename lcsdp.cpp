#include<iostream>
#include<string>
using namespace std;

int helper(string s1 , string s2, int **ans){
    
    if(s1.length() == 0 || s2.length() == 0){
        return 0;
    }
    if(ans[s1.length()][s2.length()] != -1){
        return ans[s1.length()][s2.length()];
    }
    if(s1[0] == s2[0]){
        return 1 + ans[s1.length()-1][s2.length()-1];
    }
    int a = helper(s1.substr(1) , s2.substr(1) , ans);
    int b = helper(s1 , s2.substr(1) , ans);
    int c = helper(s1.substr(1) , s2 , ans);
    return  max(a , max(b , c));
}

int lcs(string s1 , string s2 , int **ans ){
    int l1 = s1.length() ;
    int l2 = s2.length() ;
    for(int i = 0; i <= l1; i++){
        for(int j = 0; j <= l2; j++){
            ans[i][j] = helper(s1.substr(l1 - i) , s2.substr(l2 - j) , ans);
        }
    }
    return ans[s1.length()][s2.length()];
}
int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int **a = new int*[s1.length()+1];
    for(int i = 0; i < s1.length()+1; i++){
        a[i] = new int[s2.length()+1];
    }
    for(int i = 0; i < s1.length()+1 ; i++){
        for(int j = 0; j < s2.length()+1; j++){
            a[i][j] = -1;
        }
    }
    cout << lcs(s1 , s2 , a);
    return 0;
}