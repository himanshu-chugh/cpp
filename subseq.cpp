#include<iostream>
using namespace std;

int subseq(string input, string * output){
    if(input == ""){
        output[0] = "";
        return 1;
    }
    else{
        int key = subseq(input.substr(1) , output);
        for(int i = 0; i < key; i++){
            output[key+i] = input[0] + output[i];
        }
        return 2*key;
    }
}

int main(){
    string s;
    cin >> s;
    string *output = new string[1000];
    int no = subseq(s , output );
    cout << "total no of subseq are: "<< no << endl;
    for(int i = 0; i < no; i++){
        cout << output[i] << " \n";
    }
    return 0;
}