#include<iostream>
#include<math.h>
using namespace std;

double geometricSum(int k) {
    // Write your code here
    if( k == 0){
        return (double)1;
    }
    double smallans = geometricSum( k-1);
    return smallans + pow(.5,k); 
    

}




int main(){
    cout << geometricSum(2);
    return 0;
}

