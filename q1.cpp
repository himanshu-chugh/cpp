#include<bits/stdc++.h>
using namespace std;
void mem(int b[] ,int n){
    
    cout<<b[0];
}
int main(){
    int a[10][2]={{1,1},{2,2},{3,3},{4,4},{5,5},{5,6},{7,7},{3,2},{1,9},{10,10}};
    int b[10]={1,2,3,4,5,5,4,3,2,1};


    char c[]="abc";
    char c1='a';
    char *p1=c;
    char *p2=&c1;
    c1--;
    c1--;
    c1--;

    cout<<c<<" <-c\n"<<c1<<" <-c1\n"<<p1<<" <-p1\n"<<p2<<" <-p2";
    return 0;
}