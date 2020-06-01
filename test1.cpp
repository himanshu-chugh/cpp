#include<iostream>
using namespace std;
int main(){
    char c[] = "shun";
    cout << sizeof(c) << endl;
    char *p = c;
    cout << sizeof(*p) << endl;
}