#include<bits/stdc++.h> 

using namespace std;


class PriorityQueue{
    vector<int> pq;
    void hiepify( vector<int> v){
        int i = 0;
        int limit = log2(v.size());
        limit = pow(2 , limit);
        while(  i < limit && (v[i] > v[(2*i)+1] || v[i] > v[(2*i)+2])  ){
            int mini = min( v[(2*i)+1]  ,  v[(2*i)+2]);
            if(mini  == v[(2*i)+1]){
                int temp = v[(2*i)+1];
                v[(2*i)+1] = v[i];
                v[i] = temp;
                i = (2*i) + 1;
            }
            else{
                int temp = v[(2*i)+2];
                v[(2*i)+1] = v[i];
                v[i] = temp;
                i = (2*i) + 2;
            }
        }
    }
    public:
    PriorityQueue(){

    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(this->isEmpty())
        {
            return pq.at(0);
        }
        else
        {
            return 0;
        }
    }
    void insert(int d){
        pq.push_back(d);
        int i = pq.size() - 1;
        while(pq[i] < pq[(i-1)/2] && i >=0 ){
            int temp = pq[i];
            pq[i] = pq[(i-1)/2];
            pq[(i-1)/2] = temp;
            i = (i-1)/2;         
        }
    }
    int removeMin(){
        if(!this->isEmpty()){    
            int i = pq.size() - 1;
            int temp = pq[0];
            pq[0] = pq[i];
            pq[i] = temp;
            hiepify(pq);
            pq.pop_back();
            return temp;
        }
        return 0;
    }

};