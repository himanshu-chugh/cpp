#include<bits/stdc++.h>
using namespace std;

bool g( vector<int> a, vector<int> b){
    return (abs(a[0] - a[1]) < abs(b[0] - b[1]));
}
int twoCitySchedCost(vector<vector<int>>& costs) {
    int sum = 0;
    int count = 0;
    for(int i =0; i< costs.size(); i++){
        int t= min(costs[i][0] , costs[i][1]);
        sum += t;
        if(t == costs[i][0]){
            count++;
        }
    }
    if(costs.size()/2 == count)
        return sum;
    else{
        
        sort(costs.begin() , costs.end() , g);
        int difference = count  - costs.size()/2;
        // cout << "sum " << sum << endl;
        // cout << "difference " << difference << endl;
        int  i  = 0;
        while(abs(costs[i][0]-costs[i][1]) == 0){
            i++;
        }
        for(i; i < abs(difference); i++){
            cout << "under consideration " ;
            cout << costs[i][0] << " " << costs[i][1] << endl;
            if(difference > 0){
                sum -= costs[i][0];
                sum += costs[i][1];
            }
            else{
                sum += costs[i][0];
                sum -= costs[i][1];
            }
        }
        return sum;
    }
}

int main(){
    int  n;
    cin >> n;
    vector<vector<int>> v(n/2);
    cout << "input from here " <<endl;
    for(int i =0; i < n/2; i++){
        int p , q;
        cin >> p;
        cin >> q ;
        vector<int> vv;
        vv.push_back(p);
        vv.push_back(q);
        // cout << vv.size() << endl;
        v[i] = vv;
    }
    // cout << v.size() << endl;
    // for(int i = 0;  i < v.size(); i++){
    //     for(int j = 0; j < v[i].size(); j++){
    //         cout << v[i][j] << " " << v[i][j] << endl;
    //     }
    // }


    sort(v.begin() , v.end() , g);
    cout << "sorted" << endl;
    for(int i= 0; i< v.size(); i++){
        cout << v[i][0] << " " << v[i][1] << endl;
    }
    cout << "after sorting " << endl;
    cout << twoCitySchedCost(v) << endl;
    return 0;

    
}