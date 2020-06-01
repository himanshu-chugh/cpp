#include<iostream>
using namespace std;
int main(){
    int a = 16705;
    int *p = &a;
    char *c = (char *)p;
    for(int i=0; i<3; i++){
        cout<<*(c+i)<<endl;
    }
    return 0;

}