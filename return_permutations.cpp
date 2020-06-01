#include <iostream>
#include <string>
//#include "solution.h"
using namespace std;

#include <string>
//using namespace std;

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
        int smalloutput = returnPermutations( input.substr(1) , output);
        cout<< smalloutput <<endl;
        for(int i=0;i<smalloutput;i++){
            cout<<output[i]<<"  ||\n";
        }
        int tot = output[0].length();
        int i;
        for(i = 0; i<smalloutput; i++){
            int j;
            for(j = 1; j<tot; j++){
       //         cout<<"\t"<<(smalloutput*i)+ smalloutput + j - 1<<".\n";
     //           cout<<output[i]<<"  WORKING on!!\n";
   //             cout<<output[(smalloutput*i)+ smalloutput + j - 1]<<" ))  "<<input[0]<<" >>  " <<output[0].substr(0,j)<<" || "<<output[0].substr(j)<<"\n";
                output[(smalloutput*i)+ smalloutput + j - 1] = output[i].substr(0,j) + input[0] + output[i].substr(j);
 //               cout<<output[(smalloutput*i)+ smalloutput + j - 1]<<" after work\n";
            }
            //cout<<"\t"<<(smalloutput*i)+ smalloutput + j - 1<<".\n";    
            int m = (smalloutput*i)+ smalloutput + j - 1;
            cout<<m<<"  .=.\n";
            output[m] = output[i] + input[0];
            //cout<<"test end "<<output[(smalloutput*i)+ smalloutput + j - 1]<<endl;
            output[i] = input[0] + output[i];
            //cout<<"\t"<<i<<".\n";
            //cout<<"abouve change to "<<output[i]<<endl<<endl;
        }

        return (tot+1) * smalloutput;
    }

}



int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
