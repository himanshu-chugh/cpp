#include<iostream>
using namespace std;

bool che(int a[], int size){
    if(size<2){
        return true;
    }
    if(a[0]>a[1]){
        return false;
    }
    return che(a+1 , size - 1);

}
int main(){
    int a[]={1,2,3,4,5};
    cout << che(a , 5);
    return 0;
}