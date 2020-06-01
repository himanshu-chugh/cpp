#include <iostream>
using namespace std;


#include <stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
	// Write your code here
    if(extra.empty()){
        while(!input.empty()){
            extra.push(input.top());
            input.pop();
        }
    }
    if(extra.empty())
    {
        return;
    } 
    int m = extra.top();
    //cout<< m << " <-\n";
    extra.pop();
    reverseStack(input , extra);
    input.push(m);
}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}
