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


int keypad(int n, string * output){

    if(n/10 == 0){
        string s;
        s = helper(n);
        int itr = s.size();
        for(int i=0; i < itr; i++){
            //cout<< s[i] << " - ";
            output[i] = s[i];
        }
        return itr;
    }
    else{
        string s;
        s = helper(n%10);
        int itr = s.size();
        int k=0;
        int small_ans_size = keypad(n/10 , output);
        for(int i=0; i<small_ans_size;i++){
            for(int j=1;j<itr;j++){
                output[small_ans_size + k] = output[i] + s[j];
                k++;
            }
        }
        for(int i=0;i<small_ans_size;i++){
            output[i] = output[i] + s[0];
        }


        return itr * small_ans_size;
    }
}

int main(){
    //system("CLS");
    int n;
    cin >> n;
    string *output = new string[10000];
    int no = keypad(n , output );
    cout << "total no of subseq are: "<< no << endl;
    for(int i = 0; i < no; i++){
        cout << i+1 << ". " << output[i] << " \n";
    }
    return 0;
}