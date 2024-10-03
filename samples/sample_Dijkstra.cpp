#include "Dijkstra.h"
#include "dheap.h"


int main() {
    std::string filename = "C:\\Users\\alexe\\Desktop\\Dijkstra-s-algorithm\\files\\input.txt";

    int n = 0;
    Vector<Vector<Pair<int, int>>> graph = parseAdjacencyList(filename, n);
    int d = 2;
    int start = 0;
    Vector<int> dist(n);
    Vector<int> up(n);

    Dijkstra(dist, up,graph,d, n, start);

    for (int i = 0; i < n; ++i) {
        std::cout << "Vertex " << i << ": Distance = " << dist[i] << ", Predecessor = " << up[i] << std::endl;
    }
    return 0;
}
