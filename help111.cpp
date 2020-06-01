#include<iostream>
using namespace std;
int main(){
    int * p = new int[5]{0};
    int **k=&p;
    for(int i=0;i<5;i++)
    cout<<sizeof(k)<<" "<<endl;
    cout << endl;    
}