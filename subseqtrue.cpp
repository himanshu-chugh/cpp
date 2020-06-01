#include<iostream>
using namespace std;

void subseq(string input, string output = ""){
    if(input == ""){
        cout << output << endl; 
    }
    else{
        subseq(input.substr(1) ,output);
        subseq(input.substr(1) , output + input.substr(0,1));
    }

}


int main(){
    string s;
    cin >> s;
    cout<<endl;
    subseq(s);
    return 0;
}