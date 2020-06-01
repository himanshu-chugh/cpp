#include<iostream>
using namespace std;

int fun(int a[] , int size , int x , int ans[]){
    if(size == 0){
        return 0;
    }
    
    int si = fun(a+1 , size - 1 , x , ans);
    
    for( int i=0 ; i < si ; i++){
        ans[i]++;
    }

    if(a[0] == x){
        for(int i = si; i > 0  ; i--){
            ans[i] = ans[i-1];
        }
        ans[0] = 0;
        cout << si << " ";
        return si + 1;
    }
    return si;
}


int main(){
    int a[] = {1,2,3,4,5,4,3,2,1};
    int b[9];
    for( int kk = 5; kk >=0 ; kk--){
            
        int t = fun(a , 9 , kk , b);
        cout << "\n =================================================================== "  << endl;
        cout << t << "  \n";
        for(int i = 0; i < t; i++){
            cout << b[i] << " " ;
        }
        cout << " \n\n\n ________________________________________________________________________________";
    }
    return 0;
}