#include<iostream>
#include<string>
using namespace std;
int main(){
string s;
s = "himanshu";

int len = 2;
for(int i = 0 ; i < s.length()-len + 1; i++){
    cout << s.substr(i , len) << endl;
}
return 0;
}