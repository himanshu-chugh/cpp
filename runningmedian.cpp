#include <iostream>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void print(int *a , int size){
    for(int i = 0;  i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void maxHeapify(int *a , int size , int j){
    while(j < size){
        int workingIndex = j;
        if(2*j + 1 < size && a[2*j + 1] > a[workingIndex]){
            workingIndex = 2*j + 1;
        }
        if( 2*j + 2 < size && a[2*j + 2] > a[workingIndex]){
            workingIndex = 2*j + 2;
        }
        if( workingIndex == j){
            break;
        }
        else{
            int temp = a[workingIndex];
            a[workingIndex] = a[j];
            a[j] = temp;
            j = workingIndex;
        }
    }
}

void heapSort(int *a , int size){
    for(int i = size/2 -1; i >= 0; i--){
        maxHeapify(a , size , i);
    }
    for(int i = size - 1; i >= 1; i--){
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        maxHeapify(a , i , 0);
    }
}

/* 
void findMedian(int a[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     
    cout << a[0] << endl;
    for( int i = 1; i < n ; i++){
        heapSort(a , i+1);
        int medianIndex = (i+1)/2;
        if(i%2 == 1){
            cout << (a[medianIndex] + a[medianIndex-1])/2 << endl;
        }
        else{
            cout << a[medianIndex] << endl;
        }
    }
}
*/

void findMedian(int a[], int n){
    priority_queue < int , vector<int> , greater<int>> minq;
    priority_queue<int> maxq;
    int median = a[0];
    int mins = 0 , maxs = 0;
    for(int i = 0 ; i < n ; i ++){
        if(median <= a[i]){
            if(i%2 == 0){
                minq.push(a[i]);
                mins++;
            }
            else{
                minq.push(a[i]);
                maxq.push(minq.top());
                minq.pop();
                maxs++;
            }
        }
        else{
            if(i%2 == 0){
                maxq.push(a[i]);
                minq.push(maxq.top());
                maxq.pop();
                mins++;
            }
            else{
                maxq.push(a[i]);
                maxs++;
            }
            
        }
        if(i%2 == 0){
            median = minq.top();
            cout << median << endl;
        }
        else{
            median = (minq.top() + maxq.top())/2;
            cout << median << endl;            
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}
