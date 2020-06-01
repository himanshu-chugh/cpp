#include<iostream>
#include<queue>
using namespace std;
void print(int **a , int n , bool *visited , queue<int> &q ){
    while(!q.empty()){
        int node = q.front();
        cout << node << " " ;
        q.pop();
        for(int i = 0; i < n; i++){
            if(a[node][i] == 1 && visited[i] == 0){
                visited[i] = 1;
                q.push(i);
            }
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
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    print(edges , n ,visited ,q);

    delete[] visited;
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}