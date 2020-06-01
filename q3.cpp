#include<iostream>
using namespace std;
int main(){
    system("CLS");
    int i = 65;
    int *p = &i;
    char *c = (char*) p;
    for ( int i=0; i<3; i++){
        cout<< c[i] << endl;
    }
    return 0;
}