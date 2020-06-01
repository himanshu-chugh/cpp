#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n ;
    cin >> n;
    long long int *input = new long long int[n];
    for(long long int i = 0; i < n; i++){
        cin >> input[i];
    }
    stack<long long int> s;
    long long int *right = new long long int[n];
    long long int *left = new long long int[n];
    
    s.push(0);
    for(int i = 1; i < n; i++){
        while(!s.empty() && input[s.top()] < input[i]){
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);

    }
    while(!s.empty()){
        right[s.top()] = -1;
        s.pop();
    }
    s.push(n-1);
    for(int i = n-2; i >= 0; i--){
        while(!s.empty() && input[s.top()] < input[i]){
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        left[s.top()] = -1;
        s.pop();
    }


    long long int max = 0;
    for(long long int i = 0; i < n; i++){
        if(max < ((left[i]+1) * (right[i]+1))){
            max = ((left[i]+1) * (right[i]+1));
        }
    }
    cout << max << endl;
    

    delete[] left;
    delete[] right;
    delete[] input;
}