#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void bfscount(int ** a , int n , int &count){
    queue<int> q;
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++){
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            if(visited[node] == 0){
                visited[node] = 1;
            }
            for(int j = 0; j < n; j++){
                if(a[node][j] == 1 && visited[j] == 0 && j != node){
                    q.push(j);
                    visited[j] = 1;
                    count++;
                }
            }
            q.pop();
        }
        

    }
    delete[] visited;
}


int main(){
    int caseid = 1;
    int t;
    cin >> t;
    while(t--){
        int black = 0;
        int n , m;
        cin >> n >> m;
        int ** a = new int*[n];
        for(int i = 0; i < n; i++){
            a[i] = new int[n];
        }
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = 0;
            }
        }
        int e1 , e2;
        for(int i = 0; i < m; i++){
            cin >> e1 >> e2;
            a[e1-1][e2-1] = 1;
            a[e2-1][e1-1] = 1;
        }

        bfscount(a , n , black);
        black += (2*(n-1-black)) ;
        cout << "Case #" << caseid++ << ": " << black << endl;
        for(int i = 0; i < n; i++){
            delete[] a[i];
        }
        delete[] a;
    }
    return 0;
}