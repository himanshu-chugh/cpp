#include<bits/stdc++.h>
using namespace std;

    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> m;
        for(int i = 0; i  < nums.size(); i++){
            int key = nums[i];
            m[key]++;
        }
        int ans , times = 0;
        for(auto i:m){
            cout << times <<  endl;
            if(times < i.second){
                times = i.second;
                cout << i.first << " " << i.second << endl;
                ans = i.first;
            }
        }
        return ans;
    }



int main(){
    vector<int> n;
    int k;
    cin >> k;
    for(int i  = 0; i< k; i++){
        int pp;
        cin >>  pp;
        n.push_back(pp);
    }
    cout << majorityElement(n) << endl;
}