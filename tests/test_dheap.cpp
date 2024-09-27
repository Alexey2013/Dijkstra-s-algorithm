#include <gtest.h>
#include "dheap.h"

TEST(DHeap, can_create_dheap_with_d)
{
	ASSERT_NO_THROW(DHeap heap(3));
}

TEST(DHeap, throw_when_d_is_small)
{
	ASSERT_ANY_THROW(DHeap heap(0));
}

TEST(DHeap, can_insert_in_dheap)
{
	DHeap heap(2);
	ASSERT_NO_THROW(heap.insert(2,1));
}

TEST(DHeap, test_dheap_is_empty)
{
	DHeap heap(2);
	EXPECT_TRUE(heap.isEmpty());
}

TEST(DHeap, test_dheap_is_not_empty)
{
	DHeap heap(2);
	heap.insert(1,2);
	EXPECT_TRUE(!heap.isEmpty());
}

TEST(DHeap, can_extract_min)
{
	DHeap heap(2);
	heap.insert(1, 2);
	pair<int, int> p(1, 2);
	EXPECT_EQ(p,heap.extractMin());
}

TEST(DHeap, can_decrease_key)
{
	DHeap heap(2);
	heap.insert(1, 2);
	heap.decreaseKey(0,5);
	pair<int, int> p(1, 5);
	EXPECT_EQ(p, heap.extractMin());
}



