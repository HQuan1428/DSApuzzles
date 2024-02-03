/*
    TOPIC: DFS APPLICATION.

    1. Cut Vertex or Articulation points. 
    2. Cut Bridges or Cut Edges. 
    3. Discuss Euler Circuits.
    4. Finding Strongly Connected Components.
    Algorithm: 
        + Perform DFS on given graph G. 
        + Number vertices of given graph G according to post-oder traversal of depth-first spanning forest.
        + Construct graph Gr, by reversing all edges in G. 
        + Perform DFS on Gr: Always start a new DFS (initial call to Visit) at the highest-connected component. 
    5. Count the number of connected components of Graph G.
*/

#include <bits/stdc++.h>
#define ll long long

// Problem 1(14-15):
int adjMatrix[256][256];
int dfsnum[256]; // Sequence number of the vertex visits
int num = 0;     // Sequence number.
int low[256];    // Small sequence number that can be travled from the vertex current u or its child vertices through non-returning edges.
void CutVertices(int u)
{
    low[u] = dfsnum[u] = num++;
    for (int v = 0; v < 256; v++)
    {
        if (adjMatrix[u][v] && dfsnum[v] == -1)
        {
            CutVertices(v);
            if (low[u] > dfsnum[u])
            {
                std::cout << "Cut Vetex: " << u << " ";
            }
            low[u] = std::min(low[u], low[v]);
        }
        else // (u,v) is a back edge.
            low[u] = std::min(low[u], dfsnum[v]);
    }
}

//Problem 2(16):
void Bridges(int u)
{
    low[u] = dfsnum[u] = num++;
    for (int v = 0; v < 256; v++)
    {
        if (adjMatrix[u][v] && dfsnum[v] == -1)
        {
            CutVertices(v);
            if (low[u] > dfsnum[u])
            {
                std::cout << "Bridges: (" << u << " " << v << ") " << std::endl;
            }
            low[u] = std::min(low[u], low[v]);
        }
        else // (u,v) is a back edge.
            low[u] = std::min(low[u], dfsnum[v]);
    }
}

// Problem 4(18)
int adjMatrix[256][256], table[256]; 
std::vector<int> st;
int counter = 0;
//This table contains the DFS Search number
int dfsnum[256], num = 0, low[256];
void StronglyConnectedComponents(int u) {
    low[u] = dfsnum[u] = num++;
    st.push_back(u);
    for (int v = 0; v < 256; v++) {
        if(adjMatrix[u][v] & table[v] == -1) {
            if(dfsnum[v] == -1) {
                StronglyConnectedComponents(v); 
            }
            low[u] = std::min(low[u], low[v]);
        }
    }
    if(low[u] == dfsnum[u]) {
        while(table[u] != counter) {
            table[st.back()] = counter;
        }
        ++counter;
    }
}

//Problem 5(19-20)
int Visited[1000] = {0};
int CountConnectedComponent(int E, int V, int u) {
    int count = 0;
    //This loop is required if the graph has more than one component.
    for (int i = 0; i < V; i++) {
        if(!Visited[i]) {
            // DFS(G, i) or BFS(G, i)
            count += 1;
        }
    }
    return count;
}
//Time complexity: Same as that of DFS/BFS and it depends on implementation. 



int main(int argc, char const *argv[]){
    
    system("pause");
    return 0;
}