#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include <random>
#include <chrono> 
#include <ctime>        
#include "dheap.h"


vector<vector<pair<int, int>>> generateGraph(int n, int m, int q, int r) {
    m = min(n * (n - 1) / 2, m);
    vector<vector<pair<int, int>>> adj_list(n);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(q, r);

    vector<vector<bool>> was(n, vector<bool>(n, false));

    int edge_count = 0;

    while (edge_count < m) {
        int i = rand() % n;
        int j = rand() % n;
        if (i != j && !was[i][j]) {
            int weight = dist(gen);

            adj_list[i].push_back({ j, weight });
            adj_list[j].push_back({ i, weight });

            was[i][j] = was[j][i] = true;

            ++edge_count;
        }
    }

    return adj_list;
}

double dijkstra(vector<int>& dist, vector<int>& up, vector<vector<pair<int, int>>> graph, int n, int d, int start) {
    vector<bool> processed(n, false);
    vector<int> index(n);
    vector<int> name(n);

    for (int i = 0; i < n; ++i) {
        up[i] = -1;
        dist[i] = INT_MAX;
        index[i] = i;
        name[i] = i;
    }

    dist[start] = 0;
    up[start] = start;
    DHeap dHeap(d);
    dHeap.Insert(start, dist[start]);

    auto begin = std::chrono::high_resolution_clock::now();  

    while (!dHeap.IsEmpty()) {
        pair<int, int> minPair = dHeap.ExtractMin();
        int i = minPair.first;
        int currentDist = minPair.second;

        if (processed[i]) continue; 
        processed[i] = true;

        vector<pair<int, int>> edge = graph[i];
        for (int k = 0; k < edge.size(); k++) {
            int j = edge[k].first;
            int newDist = edge[k].second + currentDist;

            if (newDist < dist[j]) {
                dist[j] = newDist;
                up[j] = i;
                dHeap.Insert(j, dist[j]);
            }
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> executionTime = end - begin;
    std::cout << "Execution time: " << executionTime.count() << " seconds\n";

    return executionTime.count();
}

#endif 