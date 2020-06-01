#include <iostream>
using namespace std;



/***************
 * Following is the main function that er are using internally
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
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
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
*******************/
#include<bits/stdc++.h>
using namespace std;
class PriorityQueue {
    // Complete this class
    vector<int> pq;
    void heapify(){
        int size = pq.size();
        int limit = log2(size);
        limit = pow(2 , limit) - 1;
        int i = 0;
        while(i < limit){
            int maxIndex = i;
            if((2*i) + 1 < size){
                if(pq[(2*i)+1] > pq[maxIndex] ){
                    maxIndex = 2*i + 1;
                }
            }
            
            if((2*i)+2 < size ){
                if(pq[(2*i)+2] > pq[maxIndex]){
                    maxIndex = 2*i + 2;
                }
            }
            if(maxIndex == i){
                break;
            }
            else{
                int t = pq[maxIndex];
                pq[maxIndex] = pq[i];
                pq[i] = t;
                i = maxIndex;
            }
        }
    }
    public:
    int getSize(){ 
    return pq.size();
    }
    bool isEmpty(){
        return pq.size() == 0;
    }
    void insert(int d){
        pq.push_back(d);
        int size = pq.size() - 1;
        while(size > 0 && pq[size] > pq[(size-1)/2]){
            int t = pq[size];
            pq[size] = pq[(size-1)/2];
            pq[(size-1)/2] = t;
            size = (size-1)/2;
        }
    }
    int getMax(){
        if(pq.size() == 0){
            return INT_MIN;
        }
        return pq[0];
    }
    int removeMax(){
        if(pq.size() == 0){
            return INT_MIN;
        }
        int temp = pq[0];
        if(pq.size() == 1){
            pq.pop_back();
            return temp;
        }
        int size = pq.size();
        pq[0] = pq[size - 1];
        pq.pop_back();
        heapify();
        return temp;
    }
    void print(){
        int size = pq.size();
        for(int i = 0 ; i < size; i++){
            cout << pq[i] << " " ;
        }
        cout << endl;
    }
};



int main() {
    PriorityQueue pq;
    int a[] = { 37,38,21,10,1,11,-7,14,45};
    for ( int i = 0 ; i < 9; i++){
        pq.insert(a[i]);
        pq.print();
    }
    cout << endl;
    while(!pq.isEmpty()){
        cout << pq.removeMax() << endl;
        pq.print();
    }
    
    /*
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                pq.print();
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                pq.print();
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                pq.print();
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
    */
}
