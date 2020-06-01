#include<iostream>
using namespace std;
int main(){
    system("CLS");
    int *p = new int [5];
    cout<< sizeof(p) << " " << sizeof(*p) <<endl;
    delete [] p;
    return 0;
    
} 