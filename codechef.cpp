#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int p1 , p2 , p3;
        cin >> p1 >> p2 >> p3;
        vector<pair<int,int>> v;
        pair<int , int> p ,q;
        for(int i = 0; i < n-1; i++){
            cin >> p.first >> p.second;
            q.first = p.second;
            q.second = p.first;
            v.push_back(p);	
            v.push_back(q);
        }
        int count = 0;
        for(int i = 0; i < v.size(); i++){
            if(p1 > p2){
                if(v[i].first > v[i].second){
                    for(int j = 0; j < v.size(); j++){
                        if( v[i].first != v[j].second && v[i].second == v[j].first && ( ((p2 < p3) && (v[j].first < v[j].second))  || ((p2 > p3) && (v[j].first > v[j].second)))){
                            count++;
                            //cout << count << " " << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << endl;
                        }
                    }
                }
            }
            if(p1 < p2){
                if(v[i].first < v[i].second){
                    for(int j = 0; j < v.size(); j++){
                        if(v[i].first != v[j].second && v[i].second == v[j].first && ( ((p2 < p3) && (v[j].first < v[j].second))  || ((p2 > p3) && (v[j].first > v[j].second)))){
                            count++;
                            //cout << count << " " << v[i].first << " " << v[i].second << " " << v[j].first << " " << v[j].second << endl;
                        }
                    }
                }
            }
        }
        if((p1 > p2 && p2 > p3) || (p1 < p2 && p2 < p3) || (p1 < p2) && (p2 > p3) )
        cout << count << endl;
        else
        cout << count/2 << endl;
    }
    return 0;
}

