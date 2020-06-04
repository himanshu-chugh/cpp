#include<bits/stdc++.h>
using namespace std;


int singleNonDuplicate(vector<int>& nums) {
    stack<int> s;
    int up = INT_MAX;
    for(int i = 0; i  < nums.size(); i++){
        if(s.empty()){
            s.push(nums[i]);
        }
        else{
            int k = s.top();
            if(k == nums[i]){
                s.pop();
            }
            else{
                s.push(nums[i]);
            }
        }
    }

    // cout << "ans to be returned " << s.top() << endl;
    return s.top();
}


int main(){
    int n;
    cin >> n;
    vector<int> v;
    
    for(int i = 0; i< n; i++){
        int m;
        cin >> m;
        v.push_back(m);
    }

    for(int i = 0;  i< v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    cout << singleNonDuplicate(v) << endl;
    return 0;
}
