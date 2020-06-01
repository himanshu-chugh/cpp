#include<iostream>
using namespace std;


#include<climits>
using namespace std;


int helper(int n , int *a){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        int mini = INT_MAX;
        int i = 1;
        int sq = i;
        while(sq < n){
            mini = min(mini , a[sq] + a[n-sq]);
            i++;
            sq = i*i;
        }
        if(sq == n){
            return 1;
        }
        else{
            return mini;
        }

    }

}

int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    int *a = new int[n+1];
    for(int i = 0; i < n+1; i++){
        a[i] = helper(i , a);
    }
    return a[n];
}
int main(){
    
    int num;
    cin >> num;
    cout << minCount(num);
    
}

