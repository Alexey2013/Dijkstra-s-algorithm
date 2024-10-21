#include "dheap.h"

size_t DHeap::MinChild(size_t i) {
    size_t first = FirstChild(i);
    if (first == -1) return i;

    size_t last = LastChild(i);
    size_t min_idx = first;

    for (size_t j = first + 1; j <= last; ++j) {
        if (v_[j].second < v_[min_idx].second) {
            min_idx = j;
        }
    }
    return min_idx;
}

size_t DHeap::LastChild(size_t i) const {
    size_t first = FirstChild(i);
    return (first == -1) ? -1 : std::min(first + d_ - 1, v_.size() - 1);
}

size_t DHeap::FirstChild(size_t i) const {
    size_t k = d_ * i + 1;
    return (k < v_.size()) ? k : -1;
}

size_t DHeap::Father(size_t i) const {
    return (i - 1) / d_;
}

void DHeap::SiftDown(size_t i) {
    int key0 = v_[i].first;
    int value0 = v_[i].second;
    size_t c = MinChild(i);

    while (c != i && value0 > v_[c].second) {
        v_[i] = v_[c];
        i = c;
        c = MinChild(i);
    }
    v_[i] = { key0, value0 };
}

void DHeap::SiftUp(size_t i) {
    int key0 = v_[i].first;
    int value0 = v_[i].second;
    size_t p = Father(i);

    while (i != 0 && v_[p].second > value0) {
        v_[i] = v_[p];
        i = p;
        p = Father(i);
    }
    v_[i] = { key0, value0 };
}

DHeap::DHeap(int d) : d_(d) {
    if (d_ < 2) throw std::runtime_error("Degree of heap must be at least 2.");
}

void DHeap::Insert(int key, int value) {
    v_.push_back({ key, value });
    SiftUp(v_.size() - 1);
}

pair<int, int> DHeap::ExtractMin() {
    if (v_.IsEmpty()) throw std::runtime_error("Heap is empty");

    pair<int, int> min_element(v_[0]);
    v_[0] = v_.back();
    v_.pop_back();
    if (!v_.IsEmpty()) SiftDown(0);

    return min_element;
}

bool DHeap::IsEmpty() const {
    return v_.IsEmpty();
}