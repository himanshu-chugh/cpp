#include <iostream>
using namespace std;



void printSubsetsOfArray(int input[], int size , int *output = NULL ,int o_size=0) {
	// Write your code here
  if(size == 0){
    for(int i=0; i<o_size; i++){
       cout<< output[i] << " ";
    }
    cout<<endl;
  return ;
  }
  else{
    int *output1 = new int[o_size+1];
    int i;
    for( i=0;i<o_size;i++){
      output1[i] = output[i];
    }
    output1[i] = input[0];

    printSubsetsOfArray(input+1 , size -1 ,output1  , o_size);
    printSubsetsOfArray(input+1 , size -1 , output1 ,o_size+1);
    delete[] output1;
  }
        
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
