#include<iostream>
using namespace std;

int stepscount(int no , int level){
    int n = no - level;
    int next = n % 5;
    int count = n/5;
    count += next /2;
    next = next%2;
    count += next;
    return count;
}


int main(){
    cout << stepscount(8 , -5) << endl;
    return 0;
}