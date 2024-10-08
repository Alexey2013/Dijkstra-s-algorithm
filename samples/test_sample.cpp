#include <chrono>
#include "Dijkstra.h"
#include "dheap.h"


int main() {
    const int N = 100'000;      
    const int M = 100'000'000;   
    const int s = 0;  
    const int q = 1;           
    const int r = 1'000'000;     

    vector<vector<pair<int, int>>> adj = generate_graph(N, M, q, r);

    vector<int> dist(N);
    vector<int> up(N);

    double start = 0.0;
    double end = 0.0;

    std::cout << "\n3-Heap Dijkstra\n";
    start = clock();
    Dijkstra(dist, up, adj, N, 3, s);  
    end = clock();
    std::cout << "Execution time: " << (end - start) / CLOCKS_PER_SEC << " seconds\n";

    std::cout << "\n15-Heap Dijkstra\n";
    start = clock();
    Dijkstra(dist, up, adj, N, 15, s);  
    end = clock();
    std::cout << "Execution time: " << (end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}