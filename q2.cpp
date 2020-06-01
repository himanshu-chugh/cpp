#include<iostream>
using namespace std;
int main(){
    system("CLS");
    int a = -65;
    int *p = &a;
    cout << &a << " " << p << endl;

    int **q = &p;
    cout << q << " "<< *q <<" "<< **q <<" "<< p << " "<< *p << endl;

    int b = 20;
    
    *q = &b;
    cout << *q << " " << *p << endl;
    (*p)++;
    char *c = (char*)p;
    
    cout << a << " " << b << endl;
    cout << " printing begins from here \n";
    for(int i=0; i<=3; i++){
        cout<< *(c+i) << endl;
    }
}