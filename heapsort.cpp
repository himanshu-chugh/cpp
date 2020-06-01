#include<bits/stdc++.h>
using namespace std;



void  heapify(int *a , int size , int index){
    int j = index; 
    while( j < size){
        int workingIndex = j;
        if((2*j) + 1 < size ){
            if(a[(2*j) + 1] > a[workingIndex]){
                workingIndex = (2*j) + 1;
            }
        }
        if((2*j) + 2 < size ){
            if(a[(2*j) + 2] > a[workingIndex]){
                workingIndex = (2*j) + 2;
            }
        }
        if(workingIndex == j){
            break;
        }
        else{
            int temp = a[j];
            a[j] = a[workingIndex];
            a[workingIndex] = temp;
            j = workingIndex;
        }
    }
}
void print(int *a , int size=0){
    for(int i = 0; i < size; i++){
        cout << a[i] << " " ;
    }
    cout << endl;
}

int main(){
    int a[] = { 9,4,6,7,3,1,2,11,52,53 , -4};
    int size = 11;
    print(a, size);

    // creating inplace heap;

    for( int i = size/2 -1 ; i >=0; i--){
        heapify(a, size , i);
    }
    // heap created !! ;

    print(a, size);

    // sorting yo ...
    //cout << " doing stuff " << endl;
    for(int i = 0; i < size - 1; i++){
        int temp = a[0];
        a[0] = a[size-1 - i];
        a[size-1 -i] = temp;
        heapify(a , size -1 - i , 0);
        print(a, size);
    }

    print(a, size);

}