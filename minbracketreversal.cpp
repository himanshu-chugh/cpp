#include <iostream>
using namespace std;

#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
    stack<char> s;
    int i=0;
    int count = 0;
    while(input[i] != '\0'){
        if(input[i] == '{'){
            s.push('{');
        }
        else if(input[i] == '}'){
            if(s.empty()){
                count++;
                s.push('{');
            }
            else if(s.top() == '{'){
                s.pop();
            }
            else{
                s.push('}');
            }
        }
        else{
        }
        i++;
    }
        if(s.size()%2 == 1){
            return -1;
        }
        else{
            return count + s.size()/2;
        }
    
}




int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}