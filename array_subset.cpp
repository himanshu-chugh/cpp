#include <iostream>
using namespace std;


/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    if( n == 0){
        output[0][0] = 0;
        return 1;
    }
    else{
        int small_row = subset(input , n-1 , output);
        int add_now = input[n-1];
        int i,j;
        for(i=0; i<small_row; i++){
            for(j=1;j<output[i][0]+1; j++){
                output[i + small_row][j] = output[i][j];
            }
            output[i+small_row][j] = add_now;
            output[i+small_row][0] = output[i][0] + 1 ;
        }
        return 2*small_row;
    }

}



int main() {
  int input[20],length, output[350][20];
  cout<< " ------------------------------\n";
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
