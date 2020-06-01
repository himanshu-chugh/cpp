#include<iostream>
#include<queue>
using namespace std;
void print_DFS(int **a , int n ,int sv, bool *visited){
    if(visited[sv] == 0)
    cout << sv << " ";
    visited[sv] = 1;
    for(int i = 0; i < n; i++){
        if(visited[i] == 1 || i == sv){
            continue;
        }
        if(a[sv][i] == 1){
            print_DFS(a , n , i , visited);
        }
        
    }
}
void print_BFS(int **a , int n , bool *visited , queue<int> &q ){
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " " ;
        visited[node] = 1;
        for(int i = 0; i < n; i++){
            if(a[node][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    
}
void BFS(int ** a , int n){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    queue<int> q;
    for(int i = 0; i < n; i++){
        if(visited[i] == 0){
            q.push(i);
            print_BFS(a , n , visited , q);
        }
    }
    delete[] visited;
}

void DFS(int ** a , int n){
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < n; i++){
        print_DFS(a , n , i , visited);
    }
    delete[] visited;
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
    cout << "BFS of a graph " << endl;
    BFS(edges , n);
    cout << endl;
    cout << "DFS of a graph " << endl;
    DFS(edges , n);
    for(int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;
    return 0;
}