#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "dheap.h"

Vector<Vector<Pair<int, int>>> generate_graph(int n, int m, int q = 1, int r = 11) {
    int maxEdges = n * (n - 1) / 2;
    m = min(maxEdges, m);
    Vector<Vector<Pair<int, int>>> graph(n);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && graph[i].size() < m; ++j) {
            int weight = rand() % (r - q) + q;
            graph[i].push_back(Pair<int, int>(j, weight));
        }
    }
    return graph;
}


void Dijkstra(Vector<int>& dist, Vector<int>& up, Vector<Vector<Pair<int, int>>> graph, int n, int d, int start) {
    Vector<int> index(n);
    Vector<int> name(n);

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
        Pair<int, int> minPair = dHeap.extractMin();
        int i = minPair.first;
        int currentDist = minPair.second;

        if (currentDist > dist[i]) continue;

        Vector<Pair<int, int>> current = graph[i];
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