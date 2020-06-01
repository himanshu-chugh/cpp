#include<iostream>
using namespace std;


int countZeros(int n) {
    // Write your code here
    if(n == 0){
        return 0;
    }
    int smallans = countZeros( n/10 );
    if(n%10 == 0){
        return 1 + smallans ;
    }
    return smallans;
}

int main(){
    cout << countZeros(1001);
    return 0;
}

