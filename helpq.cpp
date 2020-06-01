#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> c;
    c.push_back(8);
    cout << c.back() << endl;
    cout << c.size() << endl;
    c.pop_back();
    cout << c.size() << endl;
    cout << c.back() << endl;
    return 0;
}