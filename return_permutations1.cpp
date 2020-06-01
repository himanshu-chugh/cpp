#include <iostream>
#include <string>
//#include "solution.h"
//using namespace std;

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    int length = input.length();
    if(length == 1){
        output[0] = "";
        output[0] = output[0] + input[0];
        return 1;
    }
    else if(length == 2){
        returnPermutations(input.substr(1) , output);
        output[1] = output[0] + input[0];
        output[0] = input[0] + output[0];
        return 2;
    }
    else{
        int smallOutputSize = returnPermutations(input.substr(1) , output);
        int l = output[0].length();
        
        for(int i=0;i<l;i++){
            for(int j=0;j<smallOutputSize;j++){
                output[j + smallOutputSize + (smallOutputSize*i)] = output[j].substr(0,i+1) + input[0] + output[j].substr(i+1);
            }
        }

        for(int i=0;i<smallOutputSize;i++){
            output[i] = input[0] + output[i];
        }
        return (l+1)*smallOutputSize;
    }

}



int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    cout<<count<<"======================\n";
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
