#include<iostream>
using namespace std;
#include <vector>
#include<queue>

vector<int> kSmallest(int *input, int n, int k) {
	// Write your code here
    priority_queue<int> q;
    for(int i = 0; i < k ; i++){
        q.push(input[i]);
    }
    for( int i = k; i < n; i++){
        if(q.top() > input[i]){
            q.pop();
            q.push(input[i]);
        }
    }
    vector<int> v;
    for(int i = 0; i < k; i++){
        v.push_back(q.top());
        q.pop();
    }
}

int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	vector<int> output = kSmallest(input, n, k);
	for(int i = 0; i < output.size(); i++){
		cout << output[i] << endl;
	}
}
