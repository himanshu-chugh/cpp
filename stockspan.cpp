#include <iostream>
using namespace std;

#include<stack>
int* stockSpan(int *p, int size) {
	// Write your code here
    stack<int> s;
    int *a = new int[size];
    int i=1;
    a[0] = 1;
    s.push(0);
    while(i<size){
        int m = p[i];
        //cout<< " m "<< m <<endl;
        while(m > p[s.top()]){
            s.pop();
            if(s.empty()){
                break;
            }
        }
        if(s.empty()){
            a[i] = i+1;
            s.push(i);
        }
        else
        {
            a[i] = i - s.top();
            s.push(i);
        }
        

        i++;
    }
    return a;
}


int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for(int i = 0; i < size; i++) {
    	cin >> input[i];
    }
    int *output = stockSpan(input, size);
    for(int i = 0; i < size; i++) {
    	cout << output[i] << " ";
    }
}
