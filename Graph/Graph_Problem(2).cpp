/*
    TOPIC: THE PROBLEMS OF GRAPH.

    Problem 21: Finding a spanning tree which takes O(|E|) time complexity
                (not necessarily a minimum spanning tree).
        Solution: The test for a cycle can be done in constant time, by marking vertices that have been
                added to the set S. An edge will introduce a cycle, if both its vertices have already been marked. 
    
    Problem 23: Detecting a cycle in an undirected graph. 
    
    Problem 24: Detecting a cycle in DAG. 

    Problem 25: Given a DAG, give an algorithm for finding its depth.

    Problem 26: How many topological sorts of the following dag are there? 

    Problem 27: Unique topological odering.
        Solutin: A directed graph has a unique topological ordering if and only if there is a directed edge between each pair of consecutive 
                vertices in the topological order. This can also be defined as: a directed graph has a unique topological ordering if and only if it has Hamilotonian path.
                If the digraph has muliple topological orderings, then a second topological order can be obtained by swapping a pair of consecutive vertices. 
    
    Problem 28: DAG structure Application. 
    
    Problem 29: Desigin a schedule.  
        Solution: 
            - Find in-degree of all the vertices - O(|V| + |E|).
            - Repeat: 
                + Find a vertex v with in-degree = 0 - 0(|V|). 
                + Output v end remove it from G, along with its edged - O(|V|)
                + Reduce the in-degree of each node u such as (v, u) was an edge in G and keep a list
                 of vertices with in-degree=0 - O(degree(V))
                + Repeat the process until all the vertices are removed
        Time complexity: the same as that of the topological sort and it is O(|V| + |E|).

    Problem 33: How do we check whether they are isomorphic or not? 
        Definition Graphs G1 = {V1, E1} and G2 = {V2, E2} are isomorphic if: 
            1) There is a one-to-one correspondence from V1 to V2 and 
            2) There is a one-to-one correspondence form E1 to E2 that map each edge of G1 to G2. 

    Problem 34: How many simple undirected non-isomorphic graphs are there with n vertices? 
        Solution: The total number of undirected labeled graphs is 2^(nC2).

    Problem 35: Hamiltonian path in DAGs:
        Approximation Algorithm: Compute a topologicalsort and check if there is an edge between each consecutive pair of vertices in the topological order. 

    Problem 36: For a given graph G with n vertices how many trees we can construct? 
        Solution: n^(n-2). This is Arthur Cayley formula.

    Problem 37: For a given graph G with n vertices how many spanning trees can we construct? 
        Soluetion: The same as that of Problem-36. It is just another way of asking the same question.

    Problem 38: The Hamiltonian cycle problem. 
        Solution: refer to the Dynamic Programming chapter.

    Problem 39: What is the difference between Dijkstra's and Prim's algorithm? 
    
    Problem 40: Reversing Graph.

    Problem 41: Travelling Sales Person Problem. 
        Solution: The Traveling Salesman Problem (TSP) is relate to finding a Hamiltonian cycle.

    Problem 42: Discuss Bipartite matchings? 
        Solution: In Bipartite graphs, we divide the graphs in to two disjoint sets, and each edge connects a vertex form one set to a vertex in another subset.
    
    Problem 43: Marriage and Personnel Problem? 
        Solution: The same as that of Problem-42.

    Problem 44: How many edges will be there in completa biparite graph Km,n? 
        Solution: This is because each vertex in the first set can connect all vertices in the second set. 

    Problem 45: if Km,n is a regular graph, what is the relation between m and n? 
        Solution: m = n.
    
    Problem 46: What is the maximum number of edges in the maximum matching of a bipartite graph with n vertices? 
        Solution: n/2.
    
    Problem 47: Discuss Planar Graphs.
    
*/

#include <bits/stdc++.h>
#include "Graph_Implementation.h"
#define ll long long

//Problem 24:
int Visited[1000];
int Predecessor[1000];
int HasCycle(Graph *G, int u) {
    Visited[u] = 1;
    for (int i = 0; i < G->V; i++) {
        if(G->Adj[u][i]) {
            if(Predecessor[i] != u && Visited[i]) {
                return 1;
            }
            else {
                Predecessor[i] = u;
                return HasCycle(G, i); 
            }
        }
    }
    return 0;
}
//Time complexity: O(E + V)

//Problem 25:
int indegree[1000];
int depthInDAG(Graph *G) {
    std::queue<int> Q;
    int counter;
    int v, w;

    counter = 0;
    for (v = 0; v < G->V; v++) {
        if(indegree[v] == 0) {
            Q.push(v);
        }
    }
    Q.push('$'); 

    while(!Q.empty()) {
        v = Q.front();
        Q.pop(); 
        if(v == '$') {
            counter++; 
            if(!Q.empty()) {
                Q.push('$');
            }
        }
        /*
            for each w adjacent to v
                if(--indegree[w] == 0) {
                    Q.push(w);
                }
        */
    }
    return counter;
}
// Time complexity: O(V + E)

//Problem 35:
bool seenTable[32];
int t;
int n;
void HamilotonianPath(Graph *G, int u){
    if(u == t) {
        /* Check that we have seen all vertices. */
    }
    else {
        for (int v = 0; v < n; v++) {
            if(!seenTable[v] && G->Adj[u][v]) {
                seenTable[v] = true;
                HamilotonianPath(G, v);
                seenTable[v] = false;
            }
        }
    }
}

int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}