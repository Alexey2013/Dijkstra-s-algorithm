#ifndef _DHEAP_H
#define _DHEAP_H
#include "vector.h"
#include "pair.h"

class DHeap {
private:
    int d;
    Vector<Pair<int, int>> v;
private:
    int minChild(int i);
    int lastChild(int i) const;
    int firstChild(int i) const;
    int father(int i) const;
    void siftDown(int i);
    void siftUp(int i);
public:
    DHeap(int d);
    DHeap(const Vector<Pair<int, int>>& elements);
public:
    void make_heap();
    void  insert(int key, int value);
    Pair<int, int>  extractMin();
    bool  isEmpty() const;
    void decreaseKey(int index, int newKey);
};

#endif 