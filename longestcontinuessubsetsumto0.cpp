#include<iostream>



#include<unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
    unordered_map<int , int > m;
    long long int sum = 0;
    int count = 0;
    for(int i = 0; i < size; i++){
        sum += arr[i];
        if(m.count(sum) == 0 ){
            m[sum] = i;
        }
        else if(count < ( i - m[sum]))
        {
            count = i - m[sum];            
        }
        else
        {
            /* code */
        }
        
    }
    return count;
}




using namespace std;


int main(){
  int size;
  
  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}


