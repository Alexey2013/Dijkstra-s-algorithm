#include <iomanip>
#include "dheap.h"


int main() {
    DHeap heap(3); 

    heap.insert(1000, 7);
    heap.insert(5000,4);
    heap.insert(300, 2);
    heap.insert(400, 1);

    std::cout << "Heap after insertion: ";
    std::cout << heap << std::endl;

    std::cout << "Extracted min: " << heap.extractMin().first << std::endl;

    std::cout << "Heap after extracting min: ";

    std::cout << heap<< std::endl;

    return 0;
}

