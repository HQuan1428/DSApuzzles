#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

/*
    TOPIC: GRAPH TRAVERSALS (DFS, BFS)
*/

// Depth First Search[DFS]
int Visited[1000] = {0}; 
void DFS(Graph *G, int u) {
    Visited[u] = 1;
    for (int v = 0; v < G->V; v++) {
        /* For example, if the adjacency matrix is used for representing the graph,
            then the condition to be used for finding unvisited adjacent 
            vertex of u is: if(!Visited[v] && G->Adj[u][v]) */
        
        /* for each unvisited adjacnet node v of u {
            DFS(G, v)
        }*/
    }
}
void DFSTraversal(Graph *G) {
    for (int i = 0; i < G->V; i++) {
        if(!Visited[i]) {
            DFS(G, i); 
        }
    }
}
//Time complexity: O(V + E)

//Breadth First Search[BFS]

void BFS(Graph *G, int u) {
    std::queue<int> Q;
    Q.push(u); 
    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();

        //Process u
        Visited[v] = 1;
        /*
        For example, if the adjacency matrix is used for representing the graph,
        then the condition be used for finding unvisited adjacent vertex of u is:
        if(!Viseted[v]! && G->Adj[u][v])
        */
        // for each unvisited adjacent node v of u{
        //  Q.push(v);
        //}
    }
}
void BFSTraversal(Graph *G) {
    for (int i = 0; i < G->V; i++) {
        if(!Visited[i]) {
            BFS(G, i);
        }
    }
}
//Time complexity: O(V + E)

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}