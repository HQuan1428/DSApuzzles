#pragma once

/*
    Graph Representation
*/

#include <bits/stdc++.h>

// Adjacency Matrix 
struct Graph {
    int V;
    int E;
    int **Adj;
};

Graph* adjMatrixOfGraph() {
    Graph *G = new Graph;
    if(!G) {
        std::cout << "Memory Error\n";
        return;
    }
    std::cin >> G->V;
    std::cin >> G->E;
    G->Adj = new int*[G->V];
    for (int u = 0; u < G->V; u++) {
        G->Adj[u] = new int[G->E];
        for (int v = 0; v < G->E; v++) {
            G->Adj[u][v] = 0;
        }
    }
    for (int i = 0; i < G->E; i++) {
        //Read an Egde
        int u, v;
        std::cin >> u >> v; 
        //For undirected graphs set both the bits
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1; 
    }
}

//Adjacency List
struct ListNode {
    int vertexNumber;
    ListNode *next;
};
struct Graph2 {
    int V;
    int E;
    ListNode **Adj;
};
Graph* adjListOfGraph() {
    ListNode *temp;
    Graph2 *G = new Graph2;
    if(!G) {
        std::cout << "Memory Error\n";
        return;
    }
    std::cin >> G->V >> G->E;
    G->Adj = new ListNode*[G->V];
    for (int i = 0; i < G->V; i++) {
        G->Adj[i] = new ListNode;
        G->Adj[i]->vertexNumber = i;
        G->Adj[i]->next = G->Adj[i];
    }
    for (int i = 0; i < G->E; i++) {
        //Read an edge
        int x, y;
        std::cin >> x >> y;
        
        ListNode *temp = new ListNode;
        temp->vertexNumber = y;
        temp->next = G->Adj[x];
        G->Adj[x]->next = temp;

        temp->vertexNumber = y;
        temp->next = G->Adj[y];
        G->Adj[y]->next = temp;
    }
}
