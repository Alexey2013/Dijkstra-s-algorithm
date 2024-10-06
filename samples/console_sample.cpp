#include <chrono>
#include "Dijkstra.h"
#include "dheap.h"


int main() {
    int N, M, s, q, r;

    std::cout << "N:";
    std::cin >> N;

    std::cout << "M:";
    std::cin >> M;

    std::cout << "s:";
    std::cin >> s;

    std::cout << "q:";
    std::cin >> q;

    std::cout << "r:";
    std::cin >> r;


    Vector<Vector<Pair<int, int>>> adj = generate_graph(N, M, q, r);

    {
        std::cout << "\n2-heap\n";

        Vector<int> dist;
        Vector<int> up;



        auto start_time = std::chrono::high_resolution_clock::now();

        Dijkstra(dist, up, adj, N, 2, s);

        auto end_time = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;

        std::cout << "Spent time: " << elapsed_time.count() << " ms " << std::endl;
    }

    {
        std::cout << "\n3-heap\n";

        Vector<int> dist;
        Vector<int> up;


        auto start_time = std::chrono::high_resolution_clock::now();

        Dijkstra(dist, up, adj, N, 3, s);

        auto end_time = std::chrono::high_resolution_clock::now();


        std::chrono::duration<double, std::milli> elapsed_time = end_time - start_time;

        std::cout << "Spent time: " << elapsed_time.count() << " ms " << std::endl;
    }

}