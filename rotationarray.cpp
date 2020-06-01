#include <iostream>
//#include "solution.h"
using namespace std;


// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int a[], int d, int size) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output.
     * Taking input and printing the output is handled automatically.
     */
    int *temp = new int[d];
    for(int i=0; i< d;i++){
        temp[i] = a[i];
        a[i] = a[(i+d)%size];        
    }
    for(int i=d; i<(size-d); i++){
        a[i] = a[(i+d)%size];
    }
    for(int i=size-d; i<size;i++){
        a[i] = temp[i-d+size];
    }
    
    
    delete [] temp;
}	




int main() {

	int size;
	int d;
	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	cin >> d;
    
    Rotate(input,d,size);
	for(int i=0;i<size;i++)
		cout<<input[i]<<" ";
	return 0;

}
