#include<iostream>
using namespace std;
int main(){
    int i = 0;
    const int * j = &i;
    i++;
    (*j)++;
    cout << i << " " << *j;
    return 0;
}