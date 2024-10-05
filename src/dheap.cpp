#include "dheap.h"

int DHeap::minChild(int i)
{
    int first = firstChild(i);
    if (first == -1) return i;

    int last = lastChild(i);
    int minIdx = first;

    for (int j = first + 1; j <= last; ++j) {
        if (v[j].second < v[minIdx].second) {
            minIdx = j;
        }
    }
    return minIdx;
}

int DHeap::lastChild(int i) const {
    int first = firstChild(i);
    return (first == -1) ? -1 : min(static_cast<int>(first + d - 1), static_cast<int>(v.size() - 1));
}

int DHeap::firstChild(int i) const {
    int k = d * i + 1;
    return (k < v.size()) ? k : -1;
}

int DHeap::father(int i) const {
    return (i - 1) / d;
}

void DHeap::siftDown(int i) {
    int key0 = v[i].first;
    int value0 = v[i].second;
    int c = minChild(i);

    while (c != i && value0 > v[c].second) {
        v[i] = v[c];
        i = c;
        c = minChild(i);
    }
    v[i] = { key0, value0 };
}

void DHeap::siftUp(int i) {
    int key0 = v[i].first;
    int value0 = v[i].second;
    int p = father(i);

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

DHeap::DHeap(const Vector<Pair<int, int>>& elements) : v(elements) {
    make_heap();
}

void  DHeap::make_heap() {
    for (int i = (v.size() / 2) - 1; i >= 0; --i) {
        siftDown(i);
    }
}

void  DHeap::insert(int key, int value) {
    v.push_back({ key, value });
    siftUp(v.size() - 1);
}

Pair<int, int>  DHeap::extractMin() {
    if (v.empty()) throw std::runtime_error("Heap is empty");

    Pair<int, int> minElement(v[0]);
    v[0] = v.back();
    v.pop_back();
    if (!v.empty()) siftDown(0);

    return minElement;
}

bool   DHeap::isEmpty() const {
    return v.empty();
}

static DHeap makeHeap(Vector<Pair<int,int>>& v, Vector<int>& index, int d) {
    DHeap dh(d);
    index.resize(v.size());
    for (int i = 0; i < v.size(); ++i) {
        dh.insert(v[i].first, v[i].second); 
    }
    return dh;
}