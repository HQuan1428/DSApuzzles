/*
    TOPIC: SHORTEST PATH ALGORITHMS
*/

#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

int Distance[1000];
int Path[1000];

//Unweighted Graph
void UnweightedShortestPath(Graph *G, int s) {
    std::queue<int> Q;
    Q.push(s);
    for (int i = 0; i < G->V; i++) {
        Distance[i] = -1;
    }
    Distance[s] = 0;

    while(!Q.empty()) {
        int v = Q.front();
        Q.pop();
        int w;
        // for each w adjancent to v
            if(Distance[w] == -1){
                Distance[w] = Distance[v] + 1;
                Path[w] = v;
                Q.push(w);
            }
    }
}
// Time complexity: O(E + v) with Adjancency lists
// Time complexity: O(V^2) with matrix

//Weighted Graph[Dijkstra's]
void Dijkstra(Graph *G, int s) {
    std::priority_queue<int, std::vector<int> , std::greater<int>> PQ;
    PQ.push(s);
    for (int i = 0; i < G->V; i++) {
        Distance[i] = -1;
    }
    Distance[s] = 0;
    while(!PQ.empty()) {
        int v = PQ.top();

        int w;
        //for all adjacent vertices w of v
            int d;
            // Compute new distance d = Distance[v] + weight[v][w]
            if (Distance[w] == -1) {
                Distance[w] = d;
                //Insert w in the priorit queue with priority d
                Path[w] = v;
            }
            if(Distance[w] > d) {
                Distance[w] = d;
                // Update priority of vertex w to be d;
                Path[w] = v;
            }
    }
}





int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}