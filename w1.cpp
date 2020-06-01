#include<iostream>
using namespace std;
void im(int *a ){
    *a = *a-1;
    cout<<*a<<endl;
}
int main(){
    int a=10;
    int *p = &a ;
    im(p);
    cout<<a;
}