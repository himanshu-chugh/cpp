#include<iostream>
using namespace std;

void removeX(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return;
    }
    else{
        if(input[0] == 'x'){
            for(int i = 0; input[i] != '\0'; i++){
                input[i] = input[i+1];
            }
            removeX(input);
        }
        else
        {
            removeX(input+1);
        }
        
        
    }

}


int main(){
    char a[] = "xx";
    removeX(a);
    cout<< a << endl;
    return 0;
}