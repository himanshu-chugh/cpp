#include<iostream>
using namespace std;
bool fun(int a , int b, int c){
    if((a > b && b > c) ||(a<b && b<c) ){
        return 1;
    }
    return 0;
}
int main(){
    int count = 0;
    for(int  i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            for(int k = 1; k<= 10; k++){
                if(fun(i , j , k)){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;
}