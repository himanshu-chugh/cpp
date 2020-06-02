#include<bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
        int a[256] = {0};
        for(int i = 0;  i < ransomNote.length(); i++){
            int index = ransomNote[i];
            a[index]--;
            cout << "incoming " << index << endl;
        }
        for(int i = 0;  i < magazine.length(); i++){
            int index = magazine[i];
            a[index]++;
            cout << "outgoing " << index << endl;
        }
        for(int i = 0; i < 256; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        for(int i = 0;i < 265; i++){
            if(a[i] < 0){
                return false;
            }
        }
        return true;
}


int main(){
    string s,ss;
    getline(cin ,  s);
    getline(cin, ss);
    cout << canConstruct(s , ss) << endl;
    return 0;
}
