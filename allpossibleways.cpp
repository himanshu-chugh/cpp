#include<bits/stdc++.h>
using namespace std;

pair<bool , int> helper(int x , int n , int **a = NULL , int width = 0 , int no = 1){
    if(x == 0){
        if(a[x][no-1] != -1){
            return a[x][no-1];
        }
        pair<bool , int> p;
        p.first = 1;
        p.second = 1;
       // cout << "                                                                   Hell yeah " << endl;
        a[x][no-1] = 1;
        return p;
    }
    if(x < 0 || x < pow`(no , n)) {
        pair<bool , int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<bool , int> ans1 , ans2 , toReturn;
    toReturn.second = 0;
    toReturn.first = 0;
    if(a[x][no] != -1){
        ans1.second = a[x][no];
        ans1.first = 1;
    }
    else{
        ans1 = helper(x , n , a , width , no+1); // not considering no
        a[x][no] = ans1.second;
    }
    int tt = x-pow(no , n);
    if(a[tt][no] != -1){
        ans2.first = 1;
        ans2.second = a[tt][no];
    }
    else{
        ans2 = helper(tt , n , a , width , no+1); // considering no
        a[tt][no] = ans2.second;
    }
    if(ans1.first){
    //    cout << " called for " << x-pow(no ,n) << " " << no+1 << " : " << ans1.second << endl;
        toReturn.second += ans1.second;
    }
    if(ans2.first){
    //    cout << " called for " << x<< " " << no+1 << " :" << ans2.second << endl;
        toReturn.second += ans2.second;
    }

    toReturn.first = ans1.first || ans2.first;
    a[x][no-1] = toReturn.second;
    return toReturn;
}

int allWays(int x, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int i = 1;
    while(pow(i , n) < x){
        i++;
    }
    i--;
    int **a = new int*[x+1];
    for(int j = 0; j < x+1; j++){
        a[j] = new int[i];
    }
    for(int k = 0; k < x+1; k++){
        for(int j = 0; j < i; j++){
            a[k][j] = -1;
        }
    }

    pair<bool , int > ans = helper(x , n , a , i);
    for(int m = 0; m < x+1; m++){
        for(int j = 0; j < i; j++){
            cout << a[m][j] << " ";
        }
        cout << endl;
    }
    if(ans.first){
        return ans.second;
    }
    return 0;
    
}
int main()
{
    int x, n;
    cin >> x >> n;
    cout << allWays(x, n);
    return 0;
}
