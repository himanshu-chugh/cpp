#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int maximumProfit(int budget[], int n) {
    // Write your code here
    sort(budget,budget+n);
    int price;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        
        a[i] = budget[i]*(n-i);
    }

    int p = a[0];
    for(int i=1;i<n;i++){
        if(p<a[i]){
            p = a[i];
        }
    }
    delete a;
    return p;

}


int main() {
    int n ,*input,i,*cost;
    cin>>n;
    input = new int[n];
    for(i = 0;i < n;i++)
        cin>>input[i];
    
    cout << maximumProfit(input, n) << endl;
    
}
