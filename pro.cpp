#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int cur = 0;
int matrix[12][12];
bool visited[12];
deque<int>que;

void fun(int n){
    cout << cur << " ";
    visited[cur] = 1;
    que.push_back(cur);
    do{
        for(int j = 0; j < n; j++){
            if(matrix[cur][j] == 1 && !visited[j])
            {
                que.push_back(j);
                cout << j << ' ';
                visited[j] = 1;
            }
        }
        que.pop_front();
        if(!que.empty())
        cur = que.front();
    }while(!que.empty());

}

int main(){
    int n = 11;
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << " done bro  ";
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    fun(n);
    
    return 0;

}