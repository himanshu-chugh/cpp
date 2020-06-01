#include<iostream>
using namespace std;
void replacePi(char input[]) {
	// Write your code here
    cout << input << endl;
    if(input[0] == '\0'){
        return;
    }
    else{
        if( input[0] == 'p' && input[1] == 'i'){
            int i;
            for (i = 2; input[i] != '\0'; i++){}
            for(int j = i; j >= 2; j--){
                input[j+2] = input[j];
            }
            input[0]='3';
            input[1]='.';
            input[2]='1';
            input[3]='4';
            replacePi(input+4);
        }
        else
        {
            replacePi(input+1);
        }
        
        
    }
}

int main(){
    char a[100] = "himasnhupoipipi";
    char b[] = "pi";
    char c[] = "3.14";
    cout << sizeof(b) << " " << sizeof(c) << endl;
    replacePi(a);
    cout<< a;

    return 0;
}