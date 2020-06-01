#include<iostream>
using namespace std;
int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
     
  */
    if(size == 0){
        return -1;
    }
    cout << input[0] << endl ;
    if( input[0] == x){
        return 0;
    }
    int smallans = firstIndex( input+1 , size - 1 , x);
    if (smallans+1)
    return 1 + smallans;
    else
    return -1;

}

int main(){
    int a[]={1,1,1,1,1,1};
    for(int i=0; i < 6; i++){
        cout << a[i] << " ";
    }
    cout << endl << "======================================================================\n";
    cout << firstIndex(a, 6, 2);
}