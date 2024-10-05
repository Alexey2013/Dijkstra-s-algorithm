#include "Dijkstra.h"
#include "dheap.h"


int main() {
    std::string inputfile = get_path();
    int n = 0;
    Vector<Vector<Pair<int, int>>> graph = parseAdjacencyList(inputfile, n);
    int d = 2;
    int start = 0;
    Vector<int> dist(n);
    Vector<int> up(n);

    Dijkstra(dist, up,graph,n, d, start);

    std::string outputfile = get_path();
    writeResultsToFile(dist, up, outputfile);
    return 0;
}
