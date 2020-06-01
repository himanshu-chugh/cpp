#include<iostream>
using namespace std;
#include <vector>
#include<unordered_map>
#include<climits>
#include<queue>

vector<int> longestSubsequence(int *a, int n){
	// Write your code here
    unordered_map<int , bool> m ;
    if(n == 0){
        vector<int> v;
        return v;
    }
    int maxcount = 0;
    for(int i = 0; i < n; i++) {
        m[a[i]] = true;
    }
    int count;
    int max_len = 0;
    vector<int> v;
    for(int i=0; i<n; i++){
        count = 1;
        //cout<<"looking for : "<<a[i] <<endl;
        if(m[a[i]] == true){
            vector<int> v2 , v1;
            v2.push_back(a[i]);
            m[a[i]] = false;
            int inc = 1;
            //cout<<"\t going forward and found : ";
            while(m.count(inc + a[i]) && m[inc + a[i]]){
                //cout<<inc+a[i] <<" ";
                v2.push_back( (a[i] + inc));
                m[a[i]+inc] = false;
                inc++;
                count++;
            }
            //cout<<endl;
            int dec = -1;
            //cout<<"\t going backward and found : ";
            while(m.count(dec + a[i]) && m[dec + a[i]]){
                //cout<<dec+a[i] <<" ";
                v1.push_back( (a[i] + dec));
                m[a[i]+dec] = false;
                dec--;
                count++;
            }
            //cout<<endl;
            //cout<<"\t count now "<<count<<endl;
            if(maxcount < count){
                v.clear();
                while(!v1.empty()){
                    //cout<<v1.back()<<" \\\\\""" ";    
                    v.push_back(v1.back());
                    v1.pop_back();
                }
                for(int i = 0;  i < v2.size(); i++){
                    v.push_back(v2[i]);
                }
                maxcount = count;

            }
        }
    }
    return v;



    
}
int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	vector<int> output = longestSubsequence(input, n);
	for(int i = 0; i < output.size(); i++) {
		cout << output[i] << endl;
	}
}
