#ifndef _GRAPH_H
#define _GRAPH_H

struct Edge {
    int name; 
    int w;   
    Edge* next; 
};

struct Graph {
    std::vector<Edge*> adj;
    Graph(int n) : adj(n + 1, nullptr) {}
};

#endif 