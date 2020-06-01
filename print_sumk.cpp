#include <iostream>
using namespace std;
//#include "solution.h"

void printSubsetSumToK(int input[], int size,  int k , int *output = NULL ,int o_size = 0) {
    // Write your code here
    if(size == 0){
        if( k == 0){
            for(int i=0;i<o_size;i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        else
        {
            return;
        }
        
    }
    else
    {
        int *output1 = new int[o_size + 1];
        output1[o_size] = input[0];
        for(int i=0;i<o_size;i++){
            output1[i] = output[i];
        }
        printSubsetSumToK(input + 1, size - 1 , k , output1 , o_size );
        printSubsetSumToK(input + 1, size - 1 , k - input[0] , output1 , o_size+1 );

    }
    
    
    
    
}


int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
