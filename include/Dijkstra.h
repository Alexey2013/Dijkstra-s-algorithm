#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "vector.h"
#include "dheap.h"

void Dijkstra(Vector<int>& dist, Vector<int>& up, Vector<Vector<Pair<int, int>>> graph, int n, int d, int start) {
    Vector<int> key(n + 1, INT_MAX);
    Vector<int> index(n + 1);
    Vector<int> name(n + 1);

    for (int i = 0; i < n; ++i) {
        up[i] = -1;
        dist[i] = INT_MAX;
        index[i] = i;
        name[i] = i;
    }

    key[start] = 0;
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