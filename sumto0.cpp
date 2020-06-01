#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
using namespace std;
 	
void PairSum(int *input, int n) {
    unordered_map <int , int> m;
    for(int i = 0; i < n ; i++){
        int a = input[i];
        if(m.count(-a) > 0){
            int k = m[-a];
            for(int i = 0 ;i < k; i++ ){
                 
                if(a > 0){
                    cout << -a << " " << a << endl;
                }
                else
                {
                    cout << a << " " << -a << endl;
                }
            }
        }
        m[a]++;
    }
}
int main()
{
    int n;
    int arr[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    PairSum(arr, n);
    return 0;
}
