#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include "dheap.h"
#include "Graph.h"


namespace algorithm {
    void Dijkstra(std::vector<int>& dist, std::vector<int>& up, Graph& graph, int n, int d, int s) {
        std::vector<int> key(n + 1, INT_MAX);
        std::vector<int> index(n + 1);
        std::vector<int> name(n + 1);

        for (int i = 1; i <= n; ++i) {
            up[i] = 0;
            dist[i] = INT_MAX;
            index[i] = i;
            name[i] = i;
        }

        key[s] = 0;
        dist[s] = 0;

        DHeap dHeap(d);

        while (!dHeap.isEmpty()) {
            int name1, key1;

            key1 = dHeap.extractMin().first;
            name1 = dHeap.extractMin().second;
            int i = name1;
            dist[i] = key1;

            Edge* p = graph.adj[i];
            while (p != nullptr) {
                int j = p->name;
                int jq = index[j];

                if (dist[jq] == INT_MAX) {
                    if (key[jq] > dist[i] + p->w) {
                        key[jq] = dist[i] + p->w;
                        dHeap.decreaseKey(jq, key[jq]);
                        up[j] = i;
                    }
                }
                p = p->next;
            }
        }
    }
};

#endif 