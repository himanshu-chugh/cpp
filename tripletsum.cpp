#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//#include "solution.h"

// arr - input array
// size - size of array
// x - sum of triplets

void FindTriplet(int a[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    sort(a , a+size);
	int i=0;
	for(; i < size-2; i++ ){
		int j=1+i,k=size-1;
		int new_x = x - a[i];
		

		while(j<k){
        if(a[j] + a[k] == new_x){
            int temp = k;
            while((a[j] + a[k] == new_x) && j<k){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
                k--;
            }
            k = temp;
            j++;
        }
        if((a[j] + a[k] < new_x) && j<k){
            while((a[j] + a[k] < new_x) && j<k){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                j++;
            }
        }
        else{
            while(a[j] + a[k] > new_x && j<k){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                k--;
            }
        }
        
        
    }
		

	}
}


int main() {

	int size;

	int x;
	cin>>size;
	
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin>>x;

	FindTriplet(input,size,x);
		
	return 0;
}

