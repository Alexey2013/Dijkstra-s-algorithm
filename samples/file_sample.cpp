#include "dijkstra.h"
#include "file.h"
#include "dheap.h"


int main() {
    std::string inputfile = getPath();
    int n = 0;
    vector<vector<pair<int, int>>> graph = parseAdjacencyList(inputfile, n);
    int d = 2;
    int start = 0;
    vector<int> dist(n);
    vector<int> up(n);

    dijkstra(dist, up,graph,n, d, start);

    std::string outputfile = getPath();
    writeResultsToFile(dist, up, outputfile);
    return 0;
}
