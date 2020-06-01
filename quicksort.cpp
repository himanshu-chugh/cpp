#include<iostream>
using namespace std;
int count=0;
int partation( int input[] ,int size){
    cout<<"---------------------------------"<<count++<<"------------------------------------------\n";
    cout<<"size: "<<size<<endl;
    cout<<endl<<"array right 0.now\n";
    for(int jj=0;jj<size;jj++){
        cout<<input[jj]<<" ";
    }
    cout<<endl;

    int si = input[0];
    cout<<"si: "<<si<<endl;
    int index = 0;
    for(int i = 1; i < size; i++){
        if(input[i] < si){
            index++;
        }
    }
    cout<<"index: "<<index<<endl;
    int temp = input[index];
    input[index] = input[0];
    input[0] = temp;
    cout<<"After setting middle\n";
    cout<<"input[0]: "<<input[0]<<endl;
    cout<<"input[index]: "<<input[index]<<endl;
    int i = 0;
    int j = size - 1;
    while(i < j){
            
        cout<<endl<<"array right 1.now\n";
        for(int jj=0;jj<size;jj++){
            cout<<input[jj]<<" ";
        }
        cout<<endl;
        while(input[i] < input[index]){
            i++;
        }
        while(input[j] >= input[index]){
            j--;
        }
        cout<<"i: "<<i<<"  j: "<<j<<endl;
        if(i < j ){//&& i != index && j != index
            cout<<"exchange b/wn  i:"<<i<<" input[i]:-"<<input[i]<<"   j:"<<j<<"  input[j]:-"<<input[j]<<endl;
            temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            
        }
    }

    cout<<endl<<"array right 2.now\n";
    for(int jj=0;jj<size;jj++){
        cout<<input[jj]<<" ";
    }
    cout<<endl;
    
    cout<<"===========================================================\n\n";
    return index;
    

}


void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    if(size>1){
        int key = partation(input , size);
        cout<<"input[key]: "<<input[key]<<" \nkey: "<<key<<endl;
        //cout<<"size: "<<size<<" \nkey: "<<key<<endl;
        quickSort(input, key);
        quickSort(input + key+1, size-key-1);
    }
}


int main(){
    system("CLS");
    int a[] = { 1,2,3,4,5,6,7,5,3,2,34,4,23,42,2,4,5,3};
    //int a[] = { 4,3,2,1,0,1,5,8,0,1};
    int size = sizeof(a)/sizeof(a[0]);
    quickSort(a,size);
    cout<<endl;
    for(int i = 0; i < size; i++){
        cout <<"   " << a[i] ;
    }
    cout << endl ;
    return 0;
}