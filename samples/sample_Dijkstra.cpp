#include "Dijkstra.h"
#include "dheap.h"

int main() {
    DHeap d(2);

    Vector < int> dist;
    dist.push_back(1);
    dist.push_back(2);
    dist.push_back(3);

    Vector < int> up;
    up.push_back(1);
    up.push_back(2);
    up.push_back(3);

    Dijkstra(dist,up,3,2,0);

    return 0;
}

