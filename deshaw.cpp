#include<bits/stdc++.h>
using namespace std;

int fun(int *a , int size , bool pos = 1){
    if(size == 2){
        int m = a[0] - a[1];
        return(m , max(a[0] , a[1]));
    }
    bool n = (pos != 1);
    int ans = fun(a+1 , size -1 , n); // including a[0]
    int ans2 = fun(a+1 , size-1 , pos); // not including a[0]
    if(pos == 1){
        return max(ans + a[0] , ans2);
    }
    else{
        return max(ans - a[0] , ans2);
    }

}

int main(){
    int a[] = {1,1,1,1,1,1};
    cout << fun(a ,6 );
    return 0;
}