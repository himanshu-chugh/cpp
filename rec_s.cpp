#include <iostream>
using namespace std;
//#include "Solution.h"

void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/

    if(input[0] != '\0'){
        if(input[0] == input[1]){
            int i;
            for(i = 0; input[i] != '\0'; i++){
                input[i] = input[i+1];
            }
            removeConsecutiveDuplicates(input);
        }
        else{
            removeConsecutiveDuplicates(input + 1);
        }

    }
    else{
        return;
    }


}


int main() {
    char input[1000000];
    char c1, c2;
    cin >> input;
    //cin >> c1 >> c2;
    removeConsecutiveDuplicates(input);
    cout << input << endl;
}
