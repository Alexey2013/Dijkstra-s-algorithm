#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "dheap.h"


vector<vector<pair<int, int>>> generate_graph(int n, int m, int q = 1, int r = 11) {
    int max_edges = n * (n - 1) / 2;

    m = min(max_edges, m);

    vector<vector<pair<int, int>>> adj_list(n);

    int edge_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && edge_count < m; ++j, ++edge_count) {
            int weight = rand() % (r - q) + q;

            adj_list[i].push_back(pair<int, int>(j, weight));
        }
    }

    return adj_list;
}

void Dijkstra(vector<int>& dist, vector<int>& up, vector<vector<pair<int, int>>> graph, int n, int d, int start) {
    vector<int> index(n+1);
    vector<int> name(n+1);

    for (int i = 0; i < n; ++i) {
        up[i] = -1;
        dist[i] = INT_MAX;
        index[i] = i;
        name[i] = i;
    }

    dist[start] = 0;
    up[start] = start;

    DHeap dHeap(d);
    dHeap.insert(start, 0);

    while (!dHeap.isEmpty()) {
        pair<int, int> minpair = dHeap.extractMin();
        int i = minpair.first;
        int currentDist = minpair.second;

        if (currentDist > dist[i]) continue;

        vector<pair<int, int>> current = graph[i];
        for (int k = 0; k < current.size(); k++) {
            int j = current[k].first;
            int weight = current[k].second;

            if (dist[i] + weight < dist[j]) {
                dist[j] = dist[i] + weight;
                up[j] = i;
                dHeap.insert(j, dist[j]);
            }
        }
    }

}



#endif 