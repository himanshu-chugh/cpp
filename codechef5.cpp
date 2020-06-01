#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v , xoer ;
        int m;
        for(int i = 0; i < n; i++){
            cin >> m;
            v.push_back(m);
        }
        xoer.push_back(v[0]^v[1]);
        for(int i = 2; i < n; i++){
            xoer.push_back(v[i] ^ xoer[i-2]);
        }
        int ans = 0;
        for(int i = 0; i < xoer.size(); i++){
            if(xoer[i] == 0){
                ans = ans + i + 1;
            }
            cout << xoer[i] << ". " ;
        }
        cout << endl;
        unordered_map<int  , vector<int> > map;
        for(int i = 0; i < xoer.size(); i++){
            map[xoer[i]].push_back(i);
        }
        int ans2 = 0;
        for(auto i : map){
            if(i.second.size() > 1){
                for(int j = 0; j < i.second.size()-1; j++){
                    for(int k = 1; k < i.second.size(); k++){
                        ans2 += i.second[j] - i.second[k];
                    }
                }
            }
        }
        

        cout << ans + ans2 << endl;
    }
}