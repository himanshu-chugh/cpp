#include<bits/stdc++.h>
using namespace std;


void reverseString(vector<char>& s) {
    int l = s.size()-1;
    int i = 0;
    while(i < l){
        char c =  s[l];
        s[l] = s[i];
        s[i] = c;
        i++;
        l--;
    }

}

int  main(){
    vector<char> s;
    int n;
    cin  >> n;
    
    for(int i=0 ;i < n; i++)
    {
        char c;
        cin >> c;
        s.push_back(c);
    }
    cout << s.size() << endl;
    
    for(int i= 0; i< n; i++){
        cout << s[i];
    }
    cout << endl;
    reverseString(s);
    for(int i= 0; i< n; i++){
        cout << s[i];
    }
    cout << endl;
}