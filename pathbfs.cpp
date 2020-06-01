#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
vector<int> * pathbfs(int** a , int n , int x ,int y ){
    queue<int> q;
    bool b = 0 , t = 0;
    unordered_map<int,int> m;
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }
    vector<int>*v = new vector<int>();
    q.push(x);
    visited[x] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            if(a[node][i] == 1 && visited[i] == 0){
                q.push(i);
                visited[i] = 1;
                m[i] = node;
                if(i == y){
                    b = 1;
                    break;
                }
            }
        }
        if(b){
            t = 1;
            break;
        }
        
    }
    if(t){
        int node = y;
        v->push_back(node);
        while(m[node] != x){
            node = m[node];
            v->push_back(node);
        }
        v->push_back(x);
        return v;
    }
    return NULL;
}

int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;

    int** a= new int*[V];
    for(int i = 0; i < V; i++){
        a[i] = new int[V];
    }
    
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < E; i++){
        int e1 , e2;
        cin >> e1 >> e2;
        a[e1][e2] = 1;
        a[e2][e1] = 1;
    }
    cin >> tempX >> tempY ;
    vector<int>* v = pathbfs(a , V , tempX , tempY );
    if(v != NULL)
    for(int i = 0; i < v->size(); i++){
        cout << v->at(i) << " " ;
    }
    else{

    }
    
    delete v;
    for(int i = 0; i < V; i++){
        delete[] a[i];
    }
    delete[] a;
    return 0;
}
