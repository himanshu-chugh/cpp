#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int size ;
	    cin >> size;
        int *a = new int[size];
	    int *b = new int[size];
        int total = 0;
        int i;
        for(i = 0; i < size; i++){
            cin >> a[i];
        }
        b[total] = a[i-1];
        total++;
        for(i = size-2; i >= 0; i--){
            if(a[i] >= b[total-1]){
                b[total] = a[i];
                total++;
            }
        }
        for(i = total-1; i >= 0; i--){
            cout << b[i] << " ";
        }
        cout << endl;
        delete [] b;
	    delete [] a;
	}
	return 0;
}