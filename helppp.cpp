#include<bits/stdc++.h>
using namespace std;
void myfun(int&a , int&b){
    int c = a;
    a = b;
    b = c;
}
int main(){
    int a = 10;
    int b = 15;
    myfun(a , b);
    cout << a << " " << b << endl;
    return 0;
}