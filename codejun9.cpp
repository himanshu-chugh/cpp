#include<bits/stdc++.h>
using namespace std;

int solve(int start , int end ){
    // cout << "call came for " << start << " " << end << endl;
    if(end-start+1 <4){
        for(int i = start; i <= end; i++){
            cout << i << endl;
            char c;
            cin >> c;
            if(c == 'E'){
                return i;
            }
        }
        return -1;
    }
    int middle ;
    if((end-start+1) %2){
        // cout << "odd " << endl;
        middle = (end-start+1)/2 + start ;
    }
    else{
        // cout << "even"<< endl;
        middle =  (end-start)/2 + start ;
    }
    
    char c;
    int g = 0,l= 0;
    for(int i = -1; i < 2; i++){
        cout << middle+i << endl;
        cin >> c;
        if(c == 'E'){
            return middle+i;
        }
        else if(c == 'G'){
            g++;
        }
        else{
            l++;
        }
    }
    if(g > l){
        return solve(middle+1 , end);
    }
    else{
        return solve(start , middle-1);
    }

}

int main(){
    int n;
    cin >> n;
    cout << solve(1 , n) << endl;
    return 0;
}