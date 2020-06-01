#include<iostream>
using namespace std;

int stringToNumber(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return 0;
    }
    else{
        int i;
        for(i = 0; input[i] != '\0'; i++){}
        int now = input[i-1]-'0';
        cout << now << " <- " << endl;
        input[i-1] = '\0';
        int smallans = stringToNumber(input);
        return smallans*10 + now;
    }
}


int main(){
    char a[] = "12301";
    cout << stringToNumber(a) << endl;
    return 0;


}