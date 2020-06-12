#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define pp pair<P , int>
#define fi first
#define se second
#define ex exit(9)
using namespace std;

void solvetr(list<P> &, list<P> &);

ll getmid(list<P> &l , bool rightm = false, ll total = 0){
    l.sort();
    // for(auto it:l){
    //     cout << it.first << " " << it.second << endl;
    // }
    if(total == 0){
    for(auto it:l){
       total += (it.se - it.fi + 1); 
    }}
    // cout << total << "total " << endl;
    ll mid = (total+1)/2;
    if(rightm){
        int temp = total - mid;
        int mid1 = (temp+1)/2;
        mid += (mid1);
    }
    for(auto it:l){
        if(mid <= (it.se-it.fi+1)){
            return (it.first+mid-1);
        }
        else{
            mid -= (it.se-it.fi+1);
        }
    }
    return total;
}


void solvefr(list<P> tr , list<P> fs){
    int mid = getmid(fs);
    // fs.sort();
    tr.sort();
    cout << mid << endl;
    char cc;
    cin >> cc;
    if(cc == 'E'){
        ex;
    }
    else if(cc == 'G'){
        P q = fs.front();
        while(q.second <= mid){
            fs.pop_front();
            q = fs.front();
        }
        if(q.second > mid and q.first <= mid){
            q.first = mid+1;
            fs.pop_front();
            fs.push_front(q);
        }
    }
    else{
        P q = fs.back();
        while(q.first >= mid){
            fs.pop_back();
            q = fs.back();
        }
        if(q.second >= mid and q.first < mid){
            q.second = mid-1;
            fs.pop_back();
            fs.push_back(q);
        }
    }
    // order change because of partationing;
    list<P> temp = fs;
    fs = tr;
    tr = temp;
    // return {fs , tr};
}


void solvetr(list<P> &tr , list<P> &fs){
    if(fs.size() != 0){
        solvefr(tr,fs);
    }
    ll mid = getmid(tr);

    cout << mid << endl;
    char c1 , c2;
    cin >> c1;
    if(c1 == 'E'){
        ex;
    }
    else if(c1 == 'G'){
        int mid2 = getmid(tr , 0,mid-1);
        cout << mid2 << endl;
        cin  >> c2;
        if(c2 == 'E'){
            ex;
        }
        else if(c2 == 'G'){
            P q = tr.front();
            while(q.second <= mid2){
                tr.pop_front();
                q = tr.front();
            }
            if(q.first <= mid2+1 and q.second > mid2+1){
                tr.pop_front();
                q.first = mid2+1;
                tr.push_front(q);
            }
            // solvetr(tr , fs);
        }
        else{
            P q = tr.back();
            while(q.first >= mid+1){
                fs.push_front(q);
                tr.pop_back();
                q = tr.back();
            }
            if(q.first < mid+1 and q.second >= mid+1){
                q.first = mid+1;
                fs.push_front(q);
                // fs.pop_back();
            }
            q = tr.back();
            while(q.first >= mid2){
                tr.pop_back();
                q = tr.back();
            }
            if(q.first < mid2 and q.second >= mid2){
                q.second = mid2-1;
                tr.pop_back();
                tr.push_front(q);
            }
            // solvetr(tr , fs);
        }
    }
    else{
        int mid1 = getmid(tr , 1);
        // cout << "right mid " << mid1 << endl;
        cout << mid1 << endl;
        char c1 , c2;
        cin >> c1;
        if(c1 == 'E'){
            ex;
        }      
        else if(c1 == 'L'){
                // right region discard of mid1

                // right region handle
                P q = tr.back();
                while (q.first >= mid1)
                {
                    tr.pop_back();
                    q = tr.back();
                }
                if(q.first < mid1 and q.second > mid1){
                    q.second = mid1-1;
                    tr.pop_back();
                    tr.push_back(q);
                }
        }
        else{
                // discard region mid to mid1 and  put region start to mid into fs!
                // left region handle
                P q = tr.front();
                while(q.second < mid){
                    fs.push_back(q);
                    tr.pop_front();
                    q = tr.front();
                }
                if(q.first < mid and q.second >= mid){
                    q.second = mid-1;
                    fs.push_back(q);
                }
                q = tr.front();
                while(q.second <= mid1){
                    tr.pop_front();
                    q = tr.front();
                }
                if(q.first <= mid1 and q.second >mid1){
                    q.first = mid1+1;
                    tr.pop_front();
                    tr.push_front(q);
                }
                fs.sort();
                tr.sort();
        }

    }
    solvetr(tr,fs);

}

int main(){
    list<P> tr ,fs;
    int n;
    cin >> n;
    P p(1,n);
    tr.push_back(p);
    
    solvetr(tr , fs);
}