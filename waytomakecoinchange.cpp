#include<iostream>
using namespace std;
#include<bits/stdc++.h>
using namespace std;

int helper(int *input , int size , int value , int ** a , int pos = 0){
    if(value == 0 && pos < size+1){
        a[value][pos] = 1;
        return 1;
    }
    else if(value < 0 || pos >= size){
        return 0;
    }
    if(a[value][pos] != -1){
        return a[value][pos];
    }
    int r = 0;
    int cost = value ;
        cout << "calling for " << input[pos] << " " << cost << endl;
    r += helper(input , size , value , a , pos+1);
        cout << " r " << r << endl;
    while(cost >= 0){
        cost = cost - input[pos];
        cout << "calling for " << input[pos] << " " << cost << endl;
        r += helper(input , size , cost , a , pos+1 );
        cout << " r " << r << endl;
    }
    a[value][pos] = r;
    return r;
}

int countWaysToMakeChange(int *input, int size, int value){
    sort(input , input + size);
    int ** a = new int*[value+1];
    for(int i = 0; i <= value; i++){
        a[i] = new int[size];
    }
    for(int i = 0; i <= value; i++){
        for(int j = 0; j < size; j++){
            a[i][j] = -1;
        }
    }
    int ans = helper(input , size , value , a);
    for(int i = 0; i <= value; i++){
        for(int j = 0; j < size; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i <= value; i++){
        delete [] a[i];
    }
    delete[] a;
    return ans;
}

int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


