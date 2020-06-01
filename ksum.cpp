#include<bits/stdc++.h>
#include<queue>
using namespace std;

bool kSortedArray(int *a , int size  , int k) {
    priority_queue<int> p;
    for(int i = 0 ; i < k ; i++){
        p.push(a[i]);
    }
    int j = 0;
    for(int i = k; i < size ; i++){
        a[j] = p.top();
        p.pop();
        p.push(a[i]);
        j++;
    }
    for(int i = 0; i < k; i++){
        a[j] = p.top();
        p.pop();
        j++;
    }
    int o = a[0];
    bool flag = 0;
    for( int i = 1; i < size; i++){
        if(a[i] < o){
            flag = 1;
            break;
        }
        o = a[i];
    }
    if(flag){
        return false;
    }
    return true;
}
int main(){

}
