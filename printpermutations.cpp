#include <iostream>
#include <string>
//#include "solution.h"

#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input , string output = ""){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int length = input.length();
    if(length == 0){
        cout<<output<<endl;
        return;
    }
    else{
        int oSize = output.length();
        for(int i=0;i<=oSize;i++){
            printPermutations(input.substr(1) , output.substr(0,i) + input[0] + output.substr(i));
            //printPermutations(input.substr(1) , output + input[0]);
        }
    }


}







int main(){
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
