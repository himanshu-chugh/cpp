#include<iostream>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
struct node{
    bool first = true;
    bool second = true;
    int times = 0;
};
void printPairs(int *input, int n, int k) {
	// Write your code here
    unordered_map<int , node> m ;
    for(int i = 0; i < n; i++){
        m[input[i]].times++; 
    }
    for(int i=0;i<n;i++){
        if(m[input[i]].first){
            if(m.count(input[i] - k)>0){
                int lol = m[input[i]-k].times;
                if(k == 0){
                    lol = m[input[i]-k].times / 2;
                }
                for(int oo=0; oo < lol * m[input[i]].times; oo++){
                    cout<<input[i]-k<<" " << input[i]<<endl;
                }
                m[input[i]-k].second = false;
                m[input[i]].first = false;
            }
        }
        if(k != 0){
        if(m[input[i]].second){
            if(m.count(input[i] + k) > 0){
                for(int oo=0; oo < m[input[i]+k].times * m[input[i]].times; oo++){
                    cout<<input[i]<<" " << input[i]+k<<endl;
                }
                m[input[i]].second = false;
                m[input[i] + k].first = false;
            }
        }}
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
	printPairs(input, n, k);
}
