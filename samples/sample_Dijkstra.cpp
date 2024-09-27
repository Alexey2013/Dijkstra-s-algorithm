#include <iomanip>
#include "dheap.h"


int main() {
    DHeap heap(3); 

    heap.insert(5, 100);
    heap.insert(3, 200);
    heap.insert(8, 300);
    heap.insert(2, 400);

    cout << "Heap after insertion: ";
    heap.print();

    cout << "Extracted min: " << heap.extractMin().get_first() << endl;

    cout << "Heap after extracting min: ";

    heap.print();

    return 0;
}

