/*
    TOPIC: TOPOLOGICAL SORT
*/

#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

int indegree[1000]; // Number of edges into it.
int TopologicalOrder[1000];

void TopologicalSort(Graph *G) {
    std::queue<int> Q;
    int counter;
    int v, w;
    for (v = 0; v < G->V; v++) {
        if(indegree[v] == 0) {
            Q.push(v);
        }
        while(!Q.empty()) {
            v = Q.front();
            Q.pop();
            TopologicalOrder[v] = ++counter;
            // for each w adjacent to v
                if(--indegree[w] == 0) {
                    Q.push(w);
                }
        }
    }
    if(counter != G->V) {
        std::cout << "Graph has cycle\n";
    }
}

//Time complexity: O(E+V)

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}