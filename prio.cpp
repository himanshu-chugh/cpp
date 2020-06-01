#include <iostream>
using namespace std;
#include <climits>
#include <vector>

/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/
#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;
    void hiepify(){
        int i = 0;
        int limit = log2(pq.size())  ;
        limit = pow(2 , limit);
        while(  i < limit   ){
            int mini_index = i;
            if( (2*i)+1 < limit){
                if( pq[mini_index] > pq[(2*i) + 1] ){
                    mini_index = (2*i )+ 1;
                }
            }
            if( (2*i) + 2  < limit){
                if(pq[mini_index] > pq[(2*i)+2]){
                    mini_index = (2*i) + 2;
                }
            }
            if(mini_index != i ){
                int temp = pq[mini_index];
                pq[mini_index] = pq[i];
                pq[i] = temp;
                i = mini_index;
            }
            else{
                break;
            }
        }
    }
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    void print(){
        for(int i = 0 ; i < pq.size(); i++){
            cout << pq[i] << " " ;
        }
        cout << endl;
    }
    
    int removeMin(){
        if(pq.size() > 0){    
            int i = pq.size() - 1;
            int temp = pq[0];
            pq[0] = pq[i];
            pq[i] = temp;
            pq.pop_back();
            hiepify();
            return temp;
        }
        return 0;
    }
    
    
};

int main() {
    PriorityQueue pq;
    int a[] = {1, 2, 6, 11, 15, 10 ,8};
    for(int i = 0; i < 7 ; i++){
        pq.insert(a[i]);
        pq.print();
    }
    cout << endl;
    cout << "deadline " << endl;
    while(pq.getSize() != 0){
        cout << pq.removeMin() << endl;
        pq.print();    
    }
    cout << endl;
    return 0;
}
