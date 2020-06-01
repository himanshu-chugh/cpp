#include <iostream>
#include <vector>
using namespace std;

int helper(string s1, string s2 , int **a){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    if(a[s1.length()][s2.length()] != -1){
        return a[s1.length()][s2.length()];
    }
	if(s1.length() == 0 || s2.length() == 0){
        int m = s1.length();
        int n = s2.length();
        m = max(m , n );
        a[s1.length()][s2.length()] = m;
        return m;
    }
    if(s1[0] == s2[0] ){
        a[s1.length()][s2.length()] = helper(s1.substr(1) , s2.substr(1) ,a);
        return a[s1.length()][s2.length()];
    }
    
    // delete
    int ans = 1 + helper(s1.substr(1) , s2 ,a);
    // replace 
    ans = min(ans , 1 + helper(s1.substr(1) , s2.substr(1) ,a));
    // insert
    ans = min(ans , 1 + helper(s1 , s2.substr(1) , a));
    a[s1.length()][s2.length()] = ans;    
    return ans;
}

int editDistance(string s1, string s2 ){
    int l = s1.length() + 1;
    int m = s2.length() + 1;
    int **a = new int*[l];
    for(int i = 0 ; i < l; i++){
        a[i] = new int[m];
    }
    for(int i = 0; i < l; i++){
        for(int j = 0; j < m ; j++){
            a[i][j] = -1;
        }
    }
    helper(s1 , s2 , a);
    return a[l-1][m-1];
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}