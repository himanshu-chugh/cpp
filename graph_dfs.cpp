#include<iostream>
using namespace std;
void print(int **a , int n ,int sv, bool *visited){
    cout << sv << " ";
    visited[sv] = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] == 1 || i == sv){
            continue;
        }
        if(a[sv][i] == 1){
            print(a , n , i , visited);
        }
        
    }
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
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    print(edges , n, 0 ,visited);
    delete[] visited;
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}