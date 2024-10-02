#include "Dijkstra.h"
#include "dheap.h"


int main() {
    std::string filename = "C:\\Users\\alexe\\Desktop\\Dijkstra-s-algorithm\\files";
    int n = 5;
    Vector<Vector<Pair<int, int>>> graph = parseAdjacencyList(filename, n);

    for (int i = 0; i < graph.size(); ++i) {
        std::cout << "Node " << i << ": ";
        int n = graph[i].size();
        for (int j = 0; j < n;j++) {
            std::cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") ";
        }
        std::cout << std::endl;
    }

    return 0;
}
