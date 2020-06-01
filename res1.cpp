#include<iostream>
using namespace std;

int firstIndex(int a[],int size , int x ){
    if(size == 0)
    return -1;
    if(a[size-1] == x){
        return size - 1; 
    }
    return firstIndex(a,size-1,x);
}
int main(){
    int a[]={1,2,1,2,2,3,4,56,56};
    cout << firstIndex(a, 9,1 );
}