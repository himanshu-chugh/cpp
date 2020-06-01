#include<bits/stdc++.h>
using namespace std;


int FindUnique(int arr[], int size){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    sort(arr,arr+size);
	int i;
	for(i=0;i<size-1;i+=2){
        if(arr[i] != arr[i+1]){
            
			break;
        }
		cout<<arr[i]<<" <\n";
    }
	return arr[i];
}

int main() {

	int size;

	cin>>size;
	int *input=new int[1+size];	
	
	for(int i=0;i<size;i++)
		cin>>input[i];
	
	cout<<FindUnique(input,size)<<endl;
		
	return 0;
}
