#include<iostream>
using namespace std;


string helper(int n){
    if(n == 2){
        return  "abc";
    }
    else if(n == 3){
        return "def";
    }
    
    else if(n == 4){
        return "ghi";
        
    }
    
    else if(n == 5){
        return "jkl";

    }
    
    else if(n == 6){
        return "mno";
        //return 3;
    }
    
    else if(n == 7){
        return "pqrs";
        //return 4;
    }
    
    else if(n == 8){
        return "tuv";
        //return 3;
    }
    
    else if(n == 9){
        return "wxyz";
        //return 4;
    }
    else
    {
        return 0;
    }
    
}
void printKeypad(int n , string output = ""){
    if(n>0){
        int pow = 10;
        while(n / pow){
            pow = pow * 10;
        }
        pow = pow /10;
        int first_num = n / pow;
        string s = helper(first_num);
        int itre = s.length();
        for( int i = 0; i < itre; i++){
            printKeypad(n%pow , output + s[i]);
        }
    }
    else{
        cout<< output << endl;
    }
}

int main(){
    //system("CLS");
    int n;
    cin >> n;
    printKeypad(n);
    return 0;
}