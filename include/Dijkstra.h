#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "vector.h"
#include "dheap.h"
#include "pair.h"

std::string get_path() {
    std::string path;
    do {
        std::cout << "Enter the file path:";
        std::cin >> path;
        std::ifstream in(path);
        if (!in.is_open()) {
            std::cout << "Ooops.....Something went wrong......" << std::endl;
        }
        else {
            in.close();
            return path;
        }
    } while (true);
}


Vector<Vector<Pair<int, int>>> parseAdjacencyList(const std::string& filename, const int n) {
    std::ifstream file(filename);
    Vector<Vector<Pair<int, int>>> graph(n);

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return graph;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string nodePart, neighborsPart;

        // Разделение строки по ':'
        std::getline(iss, nodePart, ':');
        std::getline(iss, neighborsPart);

        // Преобразование узла в int
        int node = std::stoi(nodePart);

        // Убедитесь, что граф имеет достаточно места для текущего узла
        if (node >= graph.size()) {
            graph.resize(node + 1);  // Увеличьте размер графа при необходимости
        }

        // Вектор для хранения списка смежности
        Vector<Pair<int, int>> adjacencyList;
        std::istringstream neighborsStream(neighborsPart);
        std::string neighbor;

        // Парсинг соседей через запятую
        while (std::getline(neighborsStream, neighbor, ',')) {
            int adjacentNode = std::stoi(neighbor);
            adjacencyList.push_back({ adjacentNode, 1 });  // Значение "1" для веса ребра
        }

        // Присваиваем список смежности текущему узлу
        graph[node] = adjacencyList;
    }

    file.close();
    return graph;
}

//void Dijkstra(Vector<int>& dist, Vector<int>& up, int n, int d, int start) {
//    Vector<int> key(n + 1, INT_MAX);  // Minimum key value (distance)
//    Vector<int> index(n + 1);         // Keeps track of node indices
//    Vector<int> name(n + 1);          // Keeps track of node names (optional)
//
//    Vector<Vector<Pair<int, int>>> graph = parseAdjacencyList("files/input.txt"); 
//
//    // Initialize the arrays
//    for (int i = 1; i <= n; ++i) {
//        up[i] = -1;  // Initial value indicating no predecessor
//        dist[i] = INT_MAX;  // Set all distances to infinity initially
//        index[i] = i;       // Initialize index
//        name[i] = i;        // Initialize name
//    }
//
//    key[start] = 0;
//    dist[start] = 0;  // Initialize the distance for the starting node
//
//    DHeap dHeap(d);   // Initialize the d-ary heap
//    dHeap.insert(start, 0); // Insert the starting node with distance 0
//
//    // Main loop for Dijkstra's algorithm
//    while (!dHeap.isEmpty()) {
//        auto minPair = dHeap.extractMin();  // Extract the node with minimum key
//        int i = minPair.first;              // Node index
//        int currentDist = minPair.second;   // Corresponding distance
//
//        // If the distance in the heap is greater than the current distance, skip it
//        if (currentDist > dist[i]) continue;
//
//        // Iterate over the adjacent nodes (edges)
//        Vector<Pair<int, int>> current = graph[i];
//        for (int k = 0; k < current.size(); k++) {
//            int j = current[k].first;      // Adjacent node
//            int weight = current[k].second; // Weight of the edge
//
//            // Relaxation step: Update if a shorter path is found
//            if (dist[i] + weight < dist[j]) {
//                dist[j] = dist[i] + weight;  // Update distance
//                up[j] = i;                   // Update predecessor
//                key[j] = dist[j];            // Update key
//                dHeap.decreaseKey(j, key[j]); // Decrease the key in the heap
//            }
//        }
//    }
//}

#endif 