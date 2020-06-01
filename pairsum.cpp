#include <iostream>
//using namespace std;
//#include "solution.h"


#include<bits/stdc++.h>
using namespace std;

void pairSum(int input[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
    sort(input , input + size);
    int i=0,j=size-1;
    while(i<j){
        if(input[i] + input[j] == x){
            int temp = j;
            while((input[i] + input[j] == x) && i<j){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                cout<<input[i]<<" "<<input[j]<<endl;
                j--;
            }
            j = temp;
            i++;
        }
        if((input[i] + input[j] < x) && i<j){
            while((input[i] + input[j] < x) && i<j){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                i++;
            }
        }
        else{
            while(input[i] + input[j] > x && i<j){
                //cout<<"working on index i:j  "<<i<<"  "<<j<<endl;
                j--;
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
	pairSum(input,size,x);
		
	return 0;
}
