#include <iostream>
using namespace std;


int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if( n==0 ){
        if(k==0){
        output[0][0] = 0;
        //output[0][1] = input[0];
        return 1;
        }
        else{
            return 0;
        }

    }
    
    else{
        int c1=0,c2=0;
        int output1[1000][50],output2[1000][50];
        c1 = subsetSumToK(input+1 , n-1 , output1 , k );
        c2 = subsetSumToK(input+1 , n-1 , output2 , k-input[0] );

        for(int i=0;i<c2;i++){
            int length = output2[i][0];
            output[i][0] = output2[i][0] + 1;
            output[i][1] = input[0];
            for(int j =0; j< length; j++){
                output[i][j+2] = output2[i][j+1];
            }
        }


        for(int i=0;i<c1;i++){
            int length = output1[i][0];
            for(int j=0 ; j<= length; j++){
                output[i+c2][j] = output1[i][j];
            }
        }

        return c1+c2;
    }
}

bool splitArray(int *input, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    int sumA=0,sumB=0,*a=new int[size], n=0,total=0;
    for(int i=0;i<size;i++){
        total += input[i];
        if(input[i]%5 == 0 && input[i]%3 != 0){
            sumA += input[i];
        }
        else if(input[i]%3 == 0 && input[i]%5 !=0){
            sumB += input[i];
        }
        else
        {
            a[n] = input[i];
            n++;
        }
        
    }
    if(total %2 == 1){
        return false;
    }
    if(n == 0 && sumA == sumB){
        return true;
    }
    int output[1000][50];
    int pop = subsetSumToK(a, n, output, total/2 - sumA);
    if(pop>0){
        return true;
    }else{
        return false;
    }

    delete a;
}


int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

	
	return 0;

}
