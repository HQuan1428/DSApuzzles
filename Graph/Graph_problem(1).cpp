#include <bits/stdc++.h>
#define ll long long

// Problem 12: All pairs shortest path problem.
int Distance[1000];
int Path[1000];
typedef std::pair<int, int> ii;
void Dijkstra(int graph[][100], int V, int E, int src) {
    for (int i = 0; i < 1000; i++) {
        Distance[i] = INT_MAX;
    } 
    std::priority_queue<ii, std::vector<ii>, std::greater<ii>> PQ;

    Distance[src] = 0;
    PQ.push({0, src});
    while(!PQ.empty()) {
        ii temp = PQ.top();
        PQ.pop();
        int weight = temp.first;
        int u = temp.second;
        for (int v = 0; v < E; v++) {
            if (graph[u][v] && Distance[v] > Distance[u] + graph[u][v]){
                Distance[v] = Distance[u] + graph[u][v];
                Path[v] = u;
                PQ.push({Distance[v], v}); 
            }
        }
    }
    std::cout << "Vertex \t\t Distance from Source" << std::endl;
    for (int i = 0; i < V; i++)
        std::cout << i+1 << " \t\t\t" << Distance[i] << std::endl;
}


//Problem 13: Floyd - Warshall algorithm. 
    // Refer to the dynamic programming chapter. 




int main(int argc, char const *argv[]){
    int V = 9;
    int E = 9;
    int graph[100][100] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    Dijkstra(graph, E, V, 0); 
    system("pause");
    return 0;
}