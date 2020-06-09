#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
bool query(vector<pair<int,int>> & range){
    int start = range.front().first;
    int end = range.front().second;
    range.pop();
    if(start == end){
        cout << start << endl;
        char c;
        cin >> c;
        if(c == 'E'){
            return 1 ;
        }
        return 0;
    }

    int mid = (start+end)/2;
    cout << mid << endl;
    char c;
    cin >> c;
    if(c == 'E'){
        return 1;
    }
    else if(c == 'G'){
        int temp = end;
        end = mid-1;
        mid = (start+end)/2;
        cout << mid<< endl;
        cin >> c;
        if(c == 'E'){
            return 1;
        }
        else if(c == 'G'){
            range(mid+1 , temp)
        }
    }
    else{

    }
}


int main(){
    int n;
    cin >> n;
    queue<pair<P , bool>> range;
    P p(1,n);
    pair<P, bool> q(p , 0);
    range.push(q);

    while(!range.empty()){
        query(queue);
    }
}