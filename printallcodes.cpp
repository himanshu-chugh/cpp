#include <iostream>
//#include "solution.h"
//using namespace std;


#include <string.h>
using namespace std;


char helper(int n){
        return 96+n;
}


void printAllPossibleCodes(string input , string output = "" ) {
    int length = input.length();
    if(length <= 0){
        cout<< output <<endl;
        return;
    }
    else if (length == 1){
        char c = helper( input[0]-'0');
        printAllPossibleCodes( input.substr(1) , output + c  );
        return;  
    }
    else{
        int n1 = input[0] - '0';
        int n2 = (n1*10) + (input[1] - '0');
        char c1 = helper(n1);
        char c2 ;
        printAllPossibleCodes(input.substr(1) , output + c1);
        if(n2 < 27){
            c2 = helper(n2);
            printAllPossibleCodes(input.substr(2) , output + c2);
        }

    }
}




int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
