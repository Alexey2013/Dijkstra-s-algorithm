#ifndef  _DIJKSTRA_H
#define  _DIJKSTRA_H
#include <sstream>
#include <fstream>
#include "vector.h"
#include "dheap.h"

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


Vector<Vector<Pair<int, int>>> parseAdjacencyList(const std::string& filename, int &n) {
    std::ifstream file(filename);
    Vector<Vector<Pair<int, int>>> graph;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string index;
        std::getline(iss, index, ':');

        Vector<Pair<int, int>> current;
        std::string pairStr;

        while (std::getline(iss, pairStr, ')')) {
            if (pairStr.empty()) continue; 

            size_t pos = pairStr.find('(');
            if (pos != std::string::npos) {
                std::string numbers = pairStr.substr(pos + 1);
                std::istringstream numStream(numbers);
                int first, second;


                if (numStream >> first) {
                    numStream.ignore(); 
                    if (numStream >> second) {
                        current.push_back({ first ,second });
                    }
                }
            }
        }
        n++;
        graph.push_back(current);
    }


    for (int i = 0; i < n; i++) {
        std::cout << i << ":" << std::endl;
        int m = graph[i].size();
        for (int j = 0; j < m; j++) {
            std::cout << graph[i][j].first << graph[i][j].second << std::endl;
        }
        std::cout << std::endl;
    }

    file.close();
    return graph;
}


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
                dHeap.insert(j,dist[j]);
            }
        }
    }

}
#endif 