#include<iostream>
#include<cstring>
using namespace std;


void pairStar(char input[]) {
    // Write your code here
    if(input[0] == '\0'){
        return ;
    }
    else{
        if(input[0] == input[1]){
            int i;
            for(i = 1; input[i] != '\0'; i++){
            }
            for(int j = i; j > 1; j--){
                input[j] = input[j-1]  ;  
            }
            input[1] = '*';
            input[i+1] = '\0';
            pairStar(input + 2);
            
            
        }
        else{
            pairStar(input + 1);
        }
    }

}






int main(){
    char a[100] = "abhabhsaasdnxkadcsnsnsnsnnnnsnnnnsbujxbwusxuwxusdssss";
    cout << strlen(a) << endl;
    pairStar(a);
    cout << a;
    return 0;
}