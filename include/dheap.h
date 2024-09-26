#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class DHeap {
private:
    int d;
    vector<pair<int, int>> v;

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
        return (first == -1) ? -1 : min(first + d - 1, (int)v.size() - 1);
    }

    int firstChild(int i) {
        int k = d * (i - 1) + 1;
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
    DHeap(int d) : d(d) {}

    void insert(int key, int value) {
        v.push_back({ key, value });
        siftUp(v.size() - 1);
    }

    pair<int, int> extractMin() {
        if (v.empty()) throw runtime_error("Heap is empty");

        pair<int, int> minElement = v[0];
        v[0] = v.back();
        v.pop_back();
        if (!v.empty()) siftDown(0);

        return minElement;
    }

    bool isEmpty() const {
        return v.empty();
    }

    void print() const {
        for (const auto& p : v) {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }

    void decreaseKey(int index, int newKey) {
        if (index < 0 || index >= v.size() || newKey >= v[index].first)
            throw runtime_error("Invalid operation");

        v[index].first = newKey;
        siftUp(index);
    }

};
