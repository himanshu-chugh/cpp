#include<iostream>
using namespace std;
int main(){
    system("CLS");
    char c ='q';
    char *p=0;
    p=&c;
    void *c1;
    c1 = &c;
    cout << "-------------\n";
    cout << c1 << endl;
    cout << c << endl;
    cout << &c << endl;
    cout << &c1 << endl;
    cout<<*p;

    return 0;
}