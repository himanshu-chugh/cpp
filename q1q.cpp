#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map<int ,int> m;
    m[0] = 1;
    m[-0]++;
    cout<< m[0] << "  " << m[-0];
    return 0;
}