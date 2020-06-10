#include<bits/stdc++.h>
#define ll long long
// #define P pair<ll , ll>


using namespace std;


struct range{
    ll start = 0 , end = 0;
    ll size = 0;
};
struct mids{
    ll mid=0 , lmid=0, rmid = 0;
};


mids getmids(vector<range> &v){
    sort(v.begin(), v.end() );
    ll total = 0 ,help = 0, help1 = 0 , help2 = 0,mid , lmid , rmid;
    for(int i =0; i< v.size();i++){
        total += (v[i].end-v[i].start +1);
    }
    help = total/2;
    if(total%2){
        help++;
    }
    ll total1 , total2;
    total1 = help-1;
    total2 = total - help;

    help1 = total1/2;
    if(total1%2){
        help1++;
    }

    help2 = total2/2;
    if(total2%2){
        help2++;
    }

    ////////////////
    help2 += help;
    ////////////////

    ll traversal = 0;
    bool foundl = 0 , foundm = 0 , foundr = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].end-v[i].start+1 > help1 and !foundl){
            lmid = v[i].start + total1 -1;
            foundl = 1
        }
        else{
            help1 -= (v[i].end-v[i].start+1);
        }
        ////////////////////////////////////
        if(v[i].end-v[i].start+1 > help and !foundm){
            mid = v[i].start + total1 -1;
            foundm = 1
        }
        else{
            help -= (v[i].end-v[i].start+1);
        }
        ////////////////////////////////////
        if(v[i].end-v[i].start+1 > help2 and !foundr){
            rmid = v[i].start + total1 -1;
            foundr = 1
        }
        else{
            help2 -= (v[i].end-v[i].start+1);
        }
    }
    mids ans;
    ans.lmid = lmid;
    ans.rmid = rmid;
    ans.mid = mid;
    return ans;
}


void solve(vector<range> &ranges){
    mids middle = getmids(ranges);
    char c1 , c2;
    cout << middle.mid << endl;
    cin >> c1;
    if(c1=='E'){
        exit(0) ;
    }
    else if(c1 == 'G'){
        cout << middle.lmid << endl;
        cin >> c2;
        if(c2 == 'E'){
            exit(1);
        }
        else if(c2 == 'G'){
            // range change
        }
        else{
            // easy range change;
        }
    }
    else{
        cout << middle.rmid << endl;
        cin >> c2;
        if(c2 == 'E'){
            exit(1);
        }
        else if(c2 == 'L'){
            // range change
        }
        else{
            // easy range change
        }
    }

    
}


int main(){
    int n;
    vector<range> v;
    range r;
    r.start = 1;
    r.end = n;
    v.push_back(r);
    while(1){
        solve(v);
    }
}

