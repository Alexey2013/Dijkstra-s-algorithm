#include "dheap.h"

size_t DHeap::minChild(size_t i)
{
    size_t first = firstChild(i);
    if (first == -1) return i;

    size_t last = lastChild(i);
    size_t minIdx = first;

    for (size_t j = first + 1; j <= last; ++j) {
        if (v[j].second < v[minIdx].second) {
            minIdx = j;
        }
    }
    return minIdx;
}

size_t DHeap::lastChild(size_t i) const {
    size_t first = firstChild(i);
    return (first == -1) ? -1 : min(static_cast<int>(first + d - 1), static_cast<int>(v.size() - 1));
}

size_t DHeap::firstChild(size_t i) const {
    size_t k = d * i + 1;
    return (k < v.size()) ? k : -1;
}

size_t DHeap::father(size_t i) const {
    return (i - 1) / d;
}

void DHeap::siftDown(size_t i) {
    int key0 = v[i].first;
    int value0 = v[i].second;
    size_t c = minChild(i);

    while (c != i && value0 > v[c].second) {
        v[i] = v[c];
        i = c;
        c = minChild(i);
    }
    v[i] = { key0, value0 };
}

void DHeap::siftUp(size_t i) {
    int key0 = v[i].first;
    int value0 = v[i].second;
    size_t p = father(i);

    while (i != 0 && v[p].second > value0) {
        v[i] = v[p];
        i = p;
        p = father(i);
    }
    v[i] = { key0, value0 };
}

DHeap::DHeap(int d) : d(d) {
    if (d < 2) throw std::runtime_error("Degree of heap must be at least 2.");
}

void  DHeap::insert(int key, int value) {
    v.push_back({ key, value });
    siftUp(v.size() - 1);
}

pair<int, int>  DHeap::extractMin() {
    if (v.isEmpty()) throw std::runtime_error("Heap is empty");

    pair<int, int> minElement(v[0]);
    v[0] = v.back();
    v.pop_back();
    if (!v.isEmpty()) siftDown(0);

    return minElement;
}

bool   DHeap::isEmpty() const {
    return v.isEmpty();
}
