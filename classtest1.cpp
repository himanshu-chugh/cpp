#include<iostream>
#include<string>
using namespace std;


bool checksequenece(char large[] , char*small) {
    if(large[0] == '\0' && small[0] == '\0'){
        return true;
    }
    else if(small[0] == '\0'){
        return true;
    }
    else{
    int len = 0;
    for(int i=0;large[i]!='\0';i++){
        len++;
        if(large[i] == small[0]){
            return checksequenece(large+i+1 , small+1);
        }
    }
    return false;
    }
}


int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
