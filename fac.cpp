#include<iostream>
using namespace std;
void print(int n){
    if(n == 1){
        cout << n << " ";
    }else{
     print(n - 1);
     cout << n << " ";
    }
}

int main(){
    print(3);
    cout << endl;
    return 0;
}