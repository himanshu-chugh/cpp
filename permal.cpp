#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    string s;
        cin >> s;
	    // cin.ignore();
	    // getline(cin , s);
	    unordered_map<int,vector<int>> ma;
	    for(int i = 0; i< s.length(); i++){
	        ma[s[i]-'a'].push_back(i);
	    }
        // for(auto it:ma){
        //     char c = it.first+'a';
        //     cout << c << " " << it.second.size() << endl;
        // }
	    int count = 0;
	    for(auto it:ma){
	        if(it.second.size() %2 == 1){
	            count++;
	        }
	        if(count>1){
	            break;
	        }
	    }
	    if(count >1){
	        cout << -1 << endl;
	    }
	    else{
	        int index1 = 0 , index2 = s.length()-1;
	        int *a = new int[s.length()];
            // cout << "array declared " << s.length() << endl;
	        for(auto it:ma){
                // char ccc = it.first+'a';
                // cout << "talking about " << ccc << " " << it.second.size() << endl;
                int k= 0;
                if(it.second.size()%2 == 1){
                    int middle = s.length()/2;
                    a[middle] = it.second[k]+1;
                    k++;
                }
	            for(k; k < it.second.size(); k+=2){
	                
                    a[index1++] = it.second[k]+1;
                    a[index2--] = it.second[k+1]+1;
                    
	            }
	        }
            for(int k = 0; k < s.length(); k++){
                cout << a[k] << " ";
            }
            cout << endl;
            delete[] a;
	    }
	}
	return 0;
}
