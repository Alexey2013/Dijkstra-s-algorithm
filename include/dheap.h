#ifndef _DHEAP_H
#define _DHEAP_H
#include "vector.h"
#include "pair.h"

class DHeap {
private:
    int d;
    vector<pair<int, int>> v;

private:
    size_t minChild(size_t i);        
    size_t lastChild(size_t i) const;  
    size_t firstChild(size_t i) const; 
    size_t father(size_t i) const;   
    void siftDown(size_t i);
    void siftUp(size_t i);

public:
    DHeap(int d);

    void insert(int key, int value);
    pair<int, int> extractMin();
    bool isEmpty() const;
};
#endif 