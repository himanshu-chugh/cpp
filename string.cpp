#include<iostream>
using namespace std;

int main (){
    string s = "ndcnhnhimasnhu";
    string *sp = new string;
    *sp = "himan";
    cout << s.size() << " " << s << " " << endl << s.substr(0,14);
    return 0;

}