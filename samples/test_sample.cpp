#include "dheap.h"
#include "Dijkstra.h"
#include "file.h"


int main() {
    std::string file_time = get_path();
    std::ofstream output_file(file_time);

    const int fixed_n = 10'000; 
    const int step = 1;          
    const int max_r = 200;       
    const int q = 1;

    const int m = 1000 * fixed_n; 

    for (int r = 1; r <= max_r; ++r) {
        vector<vector<pair<int, int>>> adj = generate_graph(fixed_n, m, q, r);

        vector<int> dist(fixed_n);
        vector<int> up(fixed_n);

        double start = 0.0;
        double end = 0.0;

        std::cout << "\n3-Heap Dijkstra\n";
        output_file << r << ":" << Dijkstra(dist, up, adj, fixed_n, 3, 0) << " ";

        std::cout << "\n15-Heap Dijkstra\n";
        output_file << Dijkstra(dist, up, adj, fixed_n, 15, 0) << " \n";
    }
    return 0;
}