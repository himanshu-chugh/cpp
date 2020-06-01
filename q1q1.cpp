#include <iostream>
using namespace std;


/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/


int subsetSumToK(int input[], int n, int **output, int k ) {
    // Write your code here
    if(k==0){
        output[0][0] = 0;
        return 1;
        
    }else if(k<0||n<0){
        return 0;
    }
    else{
        int **output1 = new int*[100];
        int **output2 = new int*[100];
        for(int i=0;i<100;i++){
            *(output1+i) = new int[50];
            *(output2+i) = new int[50];
        }
        int c1,c2;
        c1 = subsetSumToK(input+1 , n , output1 , k );
        c2 = subsetSumToK(input+1 , n-1 , output2 , k-input[0] );
        
        int i;
        for(i=0; i < c1; i++){
            output[i][0] = output1[i][0];
            for(int j =0;j<output[i][0];j++){
                output[i][j+1] = output1[i][j+1];
            }
        }
        int k;
        for(k=0;k<c1;k++){
            output[i+k][0] = output2[k][0] + 1;
            output[i+k][1] = input[0];
            for(int j=0; j<output2[i][0];j++ ){
                output[i+k][j+2] = output2[k][j+1];
            }
        }

        
        for(int i=0;i<100;i++){
            delete[] ((*output1)+i);
            delete[] ((*output2)+i);
        }
        delete[] output2;
        delete[] output1;

        return c1 + c2;
    }

}




int main() {
  int input[20],length,  k, **output = new int*[100];
  for(int i=0;i<100;i++){
      *(output+i) = new int [50];
  }
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
  for(int i=0;i<100;i++){
      delete[] *(output+i) ;
  }
  delete[] output;
}
