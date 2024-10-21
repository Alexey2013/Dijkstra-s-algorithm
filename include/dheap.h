#ifndef _DHEAP_H
#define _DHEAP_H
#include "vector.h"
#include "pair.h"

class DHeap {
private:
	int d_;
	vector<pair<int, int>> v_;

	size_t MinChild(size_t i);
	size_t LastChild(size_t i) const;
	size_t FirstChild(size_t i) const;
	size_t Father(size_t i) const;
	void SiftDown(size_t i);
	void SiftUp(size_t i);
public:
	DHeap(int d);
	void Insert(int key, int value);
	pair<int, int> ExtractMin();
	bool IsEmpty() const;
};
#endif 