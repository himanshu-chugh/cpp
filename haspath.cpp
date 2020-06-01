#include<iostream>
#include<queue>
using namespace std;
bool fun(int** a , int n , int e1 ,int e2){
    queue<int > q;
    
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    visited[e1] = 1;
    int node = e1;
    q.push(e1);
    while(!q.empty()){
        for(int i = 0; i < n; i++){
            if(visited[i] == 0 && a[node][i] == 1){
                if(i == e2){
                    return true;
                }
                q.push(i);
            }
        }
        node = q.front();
        q.pop();
    }
    return false;
}

int main(){
    int n ;
    int e;
    cin >> n >> e;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        int f , s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int e1 , e2;
    // cout << " Enter in which you want to check path is there or not " << endl;
    cin >> e1 >> e2;
    if(fun(edges , n , e1 , e2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}