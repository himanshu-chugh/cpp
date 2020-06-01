#include <iostream>
//#include "solution.h"
//using namespace std;

char helper(int n){
        return 96+n;
}

#include <string>
using namespace std;

int getCodes(string input, string output[10000]) {
    int lenght = input.length();
    if(lenght == 0){
        output[0] = "";
        return 1;
    }
    if(lenght == 1){
        int n1 = input[0] - '0';
        char c1 = helper(n1);
        output[0] = c1 ;
        return 1;
    }
    if(lenght >= 2){
        char c1,c2;
        int a1,a2=0;
        int n1 = input[0] - '0';
        int n2 = (n1*10) + (input[1] - '0');
        c1 = helper(n1);
        string *output2;
        if(n2 < 27){
            c2 = helper(n2);
            output2 = new string[lenght];
            a2 = getCodes( input.substr(2) , output2);
        }
        string *output1 = new string[lenght];
        a1 = getCodes( input.substr(1) , output1);
        for(int i = 0; i < a1; i++ ){
            output[i] = c1 + output1[i];
        }
        for(int  i = 0 ; i < a2; i++ ){
            output[a1 + i] = c2 + output2[i];
        }

        delete [] output1;
        if( n2 < 27){
            delete [] output2;
        }
        return  a1 + a2;
    }
    else{
        return 0;
    }

}







int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
