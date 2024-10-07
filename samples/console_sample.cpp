#include <chrono>
#include "Dijkstra.h"
#include "dheap.h"


int main() {
    int N = 100'000;
    int M = 100'000'000;
    int    s = 0;
    int  q = 1;
    int r = 1'000'000;

    Vector<Vector<Pair<int, int>>> adj = generate_graph(N, M, q, r);

    
    std::cout << "\n2-heap\n";

    Vector<int> dist(N);
    Vector<int> up(N);

    double start = 0.0;
    double end = 0.0;

    start = clock();

    Dijkstra(dist, up, adj, N, 2, s);

    end = clock();

    std::cout << end - start << "\n";
    

    
    std::cout << "\n3-heap\n";


    start = clock();

    Dijkstra(dist, up, adj, N, 3, s);

    end = clock();

    std::cout << end - start << "\n";
    
}