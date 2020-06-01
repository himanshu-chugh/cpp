#include <iostream>
using namespace std;



void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n > 2){
        
        towerOfHanoi(n-1 , source , destination , auxiliary);
        cout << source << " " << destination << endl;
        towerOfHanoi(n-1 , auxiliary , source , destination);


    }
    else if( n == 2){
        cout << source << " " << auxiliary <<endl;
        cout << source << " " << destination << endl;
        cout << auxiliary << " " << destination <<endl;
    }
    else if(n == 1){
        cout << source << " " << destination << endl;
    }
    else return;

}


int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
