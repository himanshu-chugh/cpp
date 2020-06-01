#include<iostream>
using namespace std;
int main(){
    char a[] = "himanshu";
    const char *p = "ahiad" ;
    cout << p << "  " << &p << " "<< &a << " " << p;

    char qq[] = a;
    return 0;
}