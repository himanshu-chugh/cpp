
#include<bits/stdc++.h>
using namespace std;
bool checkBalanced(char *exp) {
	// Write your code here
    stack<char> c;
    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            c.push(exp[i]);
        }
        else if(exp[i] == '['){
            c.push(exp[i]);
        }
        else if(exp[i] == '{'){
            c.push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(c.empty()){
                return false;
            }
            if(c.top() != '('){
                return false;
            }
            c.pop();
        }
        else if(exp[i] == '}'){
            if(c.empty()){
                return false;
            }
            if(c.top() != '{'){
                return false;
            }
            c.pop();
        }
        else if(exp[i] == ']'){
            if(c.empty()){
                return false;
            }
            if(c.top() != '['){
                return false;
            }
            c.pop();
        }    
        else{
            continue;
        }
    }
    return c.empty();

}


int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
