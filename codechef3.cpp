#include <iostream>
#include <string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    string s;
	    int c = 0;
	    cin >> s;
	    int len = s.length();
	    for(int i = 0; i < len; i++){
	        if(s[i] == '1'){
	            c++;
	        }
	    }
	    if(c%2 == 0){
	        cout << "LOSE" << endl;
	    }
	    else{
	        cout << "WIN" << endl;
	    }
	}
	return 0;
}
