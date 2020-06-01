#include <iostream>
//#include "solution.h"
using namespace std;

bool checkPalindrome(char input[]) {
    if(input[0] == '\0')
    return true;
    int i;
    for( i = 0; input[i] != '\0'; i++){
    }
    if(input[0] != input[i-1]){
        return false;
    }
    else{
        input[i-1]='\0';
        return checkPalindrome( input + 1 );
    }
    // Write your code here
        

}






int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
