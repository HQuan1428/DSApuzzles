/*
    TOPIC: MINIMAL SPANNING TREE
        + Prim's Algorithm
        + Kruskal's Algorithm
*/

#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

int Distance[1000] = {-1}; // all element of array is -1
int Path[1000] = {0};

//Prim's Algorithm 
void Prims(Graph *G, int s) {
    std::priority_queue<int> PQ;
    int v, w;
    PQ.push(s);
    Distance[s] = 0; 
    while(!PQ.empty()) {
        /*  for all adjacent vertices w of v {
            Compute new distance d = Distance[v] + wieght[v][w];
            if(Distance[w] == -1) {
                Distance[w] = weight[v][w];
                Insert w in the priority queue with priority d
                Path[w] = v;
            }
            if (Distance[w] > new distance d) {
                Distance[w] = weight[v][w];
                Update priotity of vetex w to be d;
                Path[w] = v;
            }
        }
        */
    }
}

// Kruskal's Algorithm
void Kruskals(Graph *G) {
    //S -> At the end S will xontains the edges of munimum spanning trees
    for (int v = 0; v < G->V; v++) {
        // MakeSet(v); -> creat Disjoint Sets
    }
    // Sort edges of E by increasing weights w
    // for each edge(u, v) in E {
    // from sorted list
    // if(FIND(U) != FIND(v)) {
        // S = S U {(u, v)};
        // UNION(u, v);
    //}
    //}
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}
