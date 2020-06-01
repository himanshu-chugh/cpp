#include<iostream>
#include<string>
using namespace std;
void prin(int *a , int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
int fun(string s , int last = 0, int secondLast = 0){
    int len = s.length();
    char lastchar = '\0'
    for(int i = 0; i < len; i++){
        if(s.)
    }
    
}

int main(){
    string s;
    cin >> s;
    int len = s.length();
    int *a = new int[len+1];
    for(int i = 0; i < len+1; i++){
        a[i] = -1;
    }
    cout << fun(s , a);
    cout << endl;
    prin(a , len+1);
    delete[] a;
    return 0;
}