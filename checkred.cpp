#include <iostream>
using namespace std;
#include<stack>

bool checkRedundantBrackets(char *input) {
    stack<int> s;
	// Write your code here
    int i=0;
    while(input[i]!='\0'){
        int count = 0;
        if(input[i]==')'){
            char c = s.top();
            while(c!= '('){
                s.pop();
                c = s.top();
                count++;
            }
            if(count == 0){
                return true;
            }
            s.pop();
        }
        else
        {
            s.push(input[i]);
        }
        
        i++;
    }
    return false;
}


int main() {
    char input[1000000];
    cin.getline(input, 1000000);

    if(checkRedundantBrackets(input)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }

}
