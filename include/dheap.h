#include <vector>
#include <iostream>
#include "Base.h"

class DHeap {
private:
    int d;
    std::vector<Pair<int, int>> v;
private:
    int minChild(int i) {
        int first = firstChild(i);
        if (first == -1) return i;

        int last = lastChild(i);
        int minIdx = first;
        for (int j = first + 1; j <= last; ++j) {
            if (v[j].first < v[minIdx].first) {
                minIdx = j;
            }
        }
        return minIdx;
    }

    int lastChild(int i) {
        int first = firstChild(i);
        return (first == -1) ? -1 :myMin(static_cast<int>(first + d - 1), static_cast<int>(v.size() - 1));
    }

    int firstChild(int i) {
        int k = d * i + 1;
        return (k < v.size()) ? k : -1;
    }

    int father(int i) {
        return (i - 1) / d;
    }

    void siftDown(int i) {
        int key0 = v[i].first;
        int value0 = v[i].second;
        int c = minChild(i);

        while (c != i && key0 > v[c].first) {
            v[i] = v[c];
            i = c;
            c = minChild(i);
        }
        v[i] = { key0, value0 };
    }

    void siftUp(int i) {
        int key0 = v[i].first;
        int value0 = v[i].second;
        int p = father(i);

        while (i != 0 && v[p].first > key0) {
            v[i] = v[p];
            i = p;
            p = father(i);
        }
        v[i] = { key0, value0 };
    }

public:
    DHeap(int d) : d(d) {
        if (d < 2) throw std::runtime_error("Degree of heap must be at least 2.");
    }

    void insert(int key, int value) {
        v.push_back({ key, value });
        siftUp(v.size() - 1);
    }

    Pair<int, int> extractMin() {
        if (v.empty()) throw std::runtime_error("Heap is empty");

        Pair<int, int> minElement (v[0]);
        v[0] = v.back();
        v.pop_back();
        if (!v.empty()) siftDown(0);

        return minElement;
    }

    bool isEmpty() const {
        return v.empty();
    }

    void decreaseKey(int index, int newKey) {
        if (index < 0 || index >= v.size() || newKey >= v[index].first)
            throw std::runtime_error("Invalid operation");

        v[index].first= newKey;
        siftUp(index);
    }


    friend std::ostream& operator<<(std::ostream& os, const DHeap& d) {
        for (const auto& pair : d.v) {
            os << "(" << pair.first << ", " << pair.second << ") ";
        }
        return os;
    }

};
