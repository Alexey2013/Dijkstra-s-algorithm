#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "vector.h"
#include "dheap.h"
#include "pair.h"


Vector<Vector<Pair<int, int>>> parseAdjacencyList(const std::string& filename) {
    std::ifstream file(filename);
    Vector<Vector<Pair<int, int>>> graph;

    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filename << std::endl;
        return graph;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nodePart, neighborsPart;

        std::getline(iss, nodePart, ':');
        std::getline(iss, neighborsPart);

        int node = std::stoi(nodePart);  

        Vector<Pair<int, int>> adjacencyList;
        std::istringstream neighborsStream(neighborsPart);
        std::string neighbor;

        while (std::getline(neighborsStream, neighbor, ',')) {
            int adjacentNode = std::stoi(neighbor);
            adjacencyList.push_back({ adjacentNode, 1 });  
        }

        graph[node] = adjacencyList;
    }

    file.close();
    return graph;
}


void Dijkstra(Vector<int>& dist, Vector<int>& up, int n, int d, int start) {
    Vector<int> key(n + 1, INT_MAX);  // Minimum key value (distance)
    Vector<int> index(n + 1);         // Keeps track of node indices
    Vector<int> name(n + 1);          // Keeps track of node names (optional)

    Vector<Vector<Pair<int, int>>> graph = parseAdjacencyList("adjacency list.txt"); // Random graph generation

    // Initialize the arrays
    for (int i = 1; i <= n; ++i) {
        up[i] = -1;  // Initial value indicating no predecessor
        dist[i] = INT_MAX;  // Set all distances to infinity initially
        index[i] = i;       // Initialize index
        name[i] = i;        // Initialize name
    }

    key[start] = 0;
    dist[start] = 0;  // Initialize the distance for the starting node

    DHeap dHeap(d);   // Initialize the d-ary heap
    dHeap.insert(start, 0); // Insert the starting node with distance 0

    // Main loop for Dijkstra's algorithm
    while (!dHeap.isEmpty()) {
        auto minPair = dHeap.extractMin();  // Extract the node with minimum key
        int i = minPair.first;              // Node index
        int currentDist = minPair.second;   // Corresponding distance

        // If the distance in the heap is greater than the current distance, skip it
        if (currentDist > dist[i]) continue;

        // Iterate over the adjacent nodes (edges)
        Vector<Pair<int, int>> current = graph[i];
        for (int k = 0; k < current.size(); k++) {
            int j = current[k].first;      // Adjacent node
            int weight = current[k].second; // Weight of the edge

            // Relaxation step: Update if a shorter path is found
            if (dist[i] + weight < dist[j]) {
                dist[j] = dist[i] + weight;  // Update distance
                up[j] = i;                   // Update predecessor
                key[j] = dist[j];            // Update key
                dHeap.decreaseKey(j, key[j]); // Decrease the key in the heap
            }
        }
    }
}

#endif 