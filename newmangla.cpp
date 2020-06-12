#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    vector< pair<long long int,long long int> > region;
    region.push_back({1,n});
    char ch1, ch2;
    while(true){
        sort(region.begin(),region.end());
        vector< pair<long long int,long long int> > newregion;
        long long int size1 = 0;
        for(auto i:region)  size1 = size1 + i.second - i.first + 1;
        long long int val1 = size1 / 2;
        long long int midVal1;
        long long int midVal2;
        long long int i;
        for(i=0;i<region.size();i++){
            if(val1 > region[i].second - region[i].first + 1) val1 = val1 - (region[i].second - region[i].first + 1);
            else{
                midVal1 = region[i].first + val1 - 1;
                break;
            }
        }
        cout<<midVal1<<endl;
        cin>>ch1;
        if(ch1 == 'E' )   return 0;
        if(ch1 == 'L'){
            for(long long int x=0;x<i;x++){
                newregion.push_back(region[x]);
            }
            if(midVal1 - 1 >= region[i].first){
                newregion.push_back({region[i].first, midVal1-1});
            }
            long long int size2 = 0;
            midVal1++;
            if(midVal1 <= region[i].second){
                size2 = region[i].second - midVal1 + 1;
            }
            for(long long int j = i+1;j<region.size();j++){
                size2 = size2 + region[j].second - region[j].first + 1;
            }
            long long int val2 = size2/2;
            long long int k = i;
            if(val2 > region[i].second - midVal1+1){
                val2 = val2 - (region[i].second - midVal1+1);
                for(k=i+1;k<region.size();k++){
                    if(val2 > region[k].second - region[k].first + 1){
                        val2 = val2 - (region[k].second - region[k].first + 1);
                    }
                    else{
                        midVal2 = region[k].first + val2 - 1;
                        break;
                    }
                }
            }
            else    
            {
                midVal2 = midVal1 + val2-1;
            }
            cout<<midVal2<<endl;
            cin>>ch2;
            if(ch2 == 'E'){  return 0;}
            if(ch2 == 'L'){
                if(k==i){ 
                    newregion.push_back({midVal1,midVal2-1});
                }
                else{
                    if(midVal1 <= region[i].second)  newregion.push_back({midVal1,region[i].second});
                    for(long long int x = i+1;x<k;x++) newregion.push_back(region[x]);
                    if(midVal2 - 1 >= region[k].first)    newregion.push_back({region[k].first , midVal2-1});
                }
                
            }
            if(ch2 == 'G'){
                if(midVal2+1 <= region[k].second){    
                    newregion.push_back({midVal2+1, region[k].second});
                }
                for(long long int x = k+1;x<region.size();x++){
                    newregion.push_back(region[x]);
                }
            }
            
        }
        if(ch1 == 'G'){
            if(midVal1 + 1 <= region[i].second){    
                newregion.push_back({midVal1+1,region[i].second});
            }
            for(long long int x = i+1;x<region.size();x++){ 
                   newregion.push_back(region[x]);
            }
            long long int size2 = 0;
            midVal1--;
            for(int j = 0;j<i;j++)    size2 = size2 + region[j].second - region[j].first + 1;
            if(region[i].first <= midVal1)    size2 = midVal1 - region[i].first + 1;
            long long int val2 = size2/2;
            long long int midVal2;
            
            long long int k;
            for(k = 0;k<=i;k++){
                if(val2 > region[k].second - region[k].first + 1)    val2 = val2 - (region[k].second - region[k].first + 1);
                else{
                    midVal2 = region[k].first + val2 - 1;
                    break;
                }
            }
            cout<<midVal2<<endl;
            cin>>ch2;
            if(ch2 == 'E')  return 0;
            if(ch2 == 'L'){
                for(long long int x = 0;x<k;x++)   newregion.push_back(region[x]);
                if(midVal2 - 1 >= region[k].first)    newregion.push_back({region[k].first,midVal2-1});
            }
            if(ch2 == 'G'){
                if(k==i)    newregion.push_back({midVal2+1,midVal1-1});
                else{
                    if(region[k].second >= midVal2+1)    newregion.push_back({midVal2+1,region[k].second});
                    for(long long int x = k+1;x<i;x++)    newregion.push_back(region [x]);
                    if(midVal1 - 1 >= region[i].first)    newregion.push_back({region[i].first, midVal1-1});
                }
                
            }
        }
        region.clear();
        region = newregion;
    }
    
}