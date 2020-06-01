#include<iostream>
using namespace std;
int count = 0;


void merge(int input[] , int size ){
    //cout << "-----------------------------------------" << count++ << "--------------------------------------------------\n";    
    int mid = size/2;
    int *a = new int[mid];
    int *b = new int[size-mid];
    
    for(int i = 0; i < mid; i++){
        a[i] = input[i];
        //cout << a[i] << " ath arr" ;
    }
    //cout << endl;
    for(int i = 0; i < size-mid; i++){
        b[i] = input[i+mid];
        //cout << b[i] << " bth arr";
    }
    //cout << endl;
    ///cout<<a[0]<<" -- "<< b[0]<<endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////
    
    // FUCK ME MERGE LOGIC
    int i=0,j=0,k=0;
    while( i < mid && j < size-mid){
        if(a[i] < b[j]){
            input[k] = a[i];
            //cout<<input[k] << "a ";
            i++;
        }
        else{
            input[k] = b[j];
            //cout<<input[k] << "b ";
            j++;
        }
        k++;
    }
    while( i < mid){
        input[k] = a[i];
        //cout<<input[k] << "c ";
        i++;
        k++;
    }
    while( j < size-mid){
        input[k] = b[j];
        //cout<<input[k] << "d ";
        j++;
        k++;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    delete[] a;
    delete[] b;
    //cout<<"printitng merge array\n";
    //for(int i=0;i<size;i++){
        //cout<<input[i]<<" ";
        //cout<<endl;
    //}

}

void mergeSort(int input[], int size){
	// Write your code here
    if(size>1){
        int mid = size/2;
        //cout << "size of array " << size << endl;
        //cout << input[0] << " " << input[mid] << " " << input[size-1] << endl << endl;
        mergeSort(input , mid );
        //cout << "==============================================================================\n";
        mergeSort(input + mid, size - mid);
        //cout<< input[0] << " " << input[mid] << " " << input[size -1] << endl;
        merge(input , size);
    }
}



int main(){
    system("CLS");
    int a[] = { 1,2,3,4,5,6,7,5,3,2,34,4,23,42,2,4,5,3};
    //int a[] = { 0,1,2,3,4};
    int size = sizeof(a)/sizeof(a[0]);
    mergeSort(a,size);
    for(int i = 0; i < size; i++){
        cout << i + 1 << ".   " << a[i] << endl;
    }
    cout << endl ;
    return 0;
}