#include<iostream>

using namespace std;

bool checkAB(char input[] ){
    int l=0;
    for(int i=0; input[i] != '\0'; i++){
        l++;
    }

    if( l == 1){
        if(input[0] == 'a'){
            return true;
        }
        else {
            return false;
        }
    }
    else if(l == 2){
        if(input[l-1] == 'a' && input[0] == 'a'){
            return true;
        }
        else{
            return false;
        }
    }
    else if( l > 2){

        if(input[l-1] == 'a'){
            input[l-1] = '\0';
            return checkAB(input);
        }
        else if( input[l-1] == 'b' && input[l-2] == 'b'){
            if(input[l-3] != 'b'){
                input[l-2] = '\0';
                return checkAB(input);
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }



    }
    else{
        return  false;
    }



}




int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
