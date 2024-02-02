/*
    TOPIC: the problems of Graph
*/

#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

// Problem 10:

int Visited[1000] = {0};

int HasSimplePath(Graph *G, int s, int d) {
    Visited[s] = 1;
    if(s == d){
        return 1;
    }
    for (int t = 0; t < G->V; t++) {
        if(G->Adj[s][t] && !Visited[t]) {
            if(HasSimplePath(G, t, d)) {
                return 1;
            }
        }
    }
    return 0;
}
// Time complexity: O(E).
// Space complexity: O(V).


//Problem 11:
static int count = 0; // variable store the numbers of simple path from s to d
void CountSimplePaths(Graph *G,int s, int d){
    Visited[s] = 1;
    if(s == d) {
        count += 1;
        Visited[s] = 0;
        return;
    }
    for (int t = 0; t < G->V; t++) {
        if(G->Adj[s][t] && !Visited[t]) {
            CountSimplePaths(G, t, d);
            Visited[t] = 0;
        }
    }
}


int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}