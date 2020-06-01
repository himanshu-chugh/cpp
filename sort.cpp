#include<Bits/stdc++.h>
using namespace std;
bool comp(int &a ,int &b){
    return a<b;
}
int main(){
    int a[] = {5,4,1,78,6,1,56,4,555};
    for(int i = 0; i < 9; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a, a+9 , comp);
    for(int i = 0; i < 9; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}