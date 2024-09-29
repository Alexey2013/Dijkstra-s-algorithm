#include <gtest.h>
#include "dheap.h"

TEST(DHeap, can_create_dheap_with_d)
{
	ASSERT_NO_THROW(DHeap heap(3));
}

TEST(DHeap, throws_when_arity_is_negative)
{
	ASSERT_ANY_THROW(DHeap heap(-1));
}

TEST(DHeap, can_insert_in_dheap)
{
	DHeap heap(2);
	ASSERT_NO_THROW(heap.insert(2,1));
}

TEST(DHeap, can_insert_and_check_if_empty) {
	DHeap heap(2);
	EXPECT_TRUE(heap.isEmpty());

	heap.insert(1, 1);
	EXPECT_FALSE(heap.isEmpty());

	heap.extractMin();
	EXPECT_TRUE(heap.isEmpty());
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

TEST(DHeap, can_extract_min_from_dheap) {
	DHeap heap(2);
	heap.insert(1, 2);
	heap.insert(3, 2);
	heap.insert(2, 2);
	EXPECT_EQ(heap.extractMin().first, 1);
}

TEST(DHeap, throws_when_extracting_from_empty_dheap) {
	DHeap heap(3);
	ASSERT_ANY_THROW(heap.extractMin());
}

TEST(DHeap, throws_when_extracting_min_after_emptying_heap) {
	DHeap heap(2);
	heap.insert(1, 1);
	heap.extractMin();

	ASSERT_ANY_THROW(heap.extractMin());
}


TEST(DHeap, can_extract_min_from_multiple_elements) {
	DHeap heap(3);
	heap.insert(5, 1);
	heap.insert(2, 2);
	heap.insert(8, 3);
	heap.insert(1, 4);

	EXPECT_EQ(heap.extractMin().first, 1);
	EXPECT_EQ(heap.extractMin().first, 2);
	EXPECT_EQ(heap.extractMin().first, 5);
	EXPECT_EQ(heap.extractMin().first, 8);
}


TEST(DHeap, can_insert_multiple_elements_and_check_min) {
    DHeap heap(2);
    heap.insert(10, 1);
    heap.insert(20, 2);
    heap.insert(5, 3);

    EXPECT_EQ(heap.extractMin().first, 5);
    EXPECT_EQ(heap.extractMin().first, 10);
    EXPECT_EQ(heap.extractMin().first, 20);
}

TEST(DHeap, can_handle_duplicate_elements) {
    DHeap heap(3);
    heap.insert(2, 1);
    heap.insert(2, 2);
    heap.insert(2, 3);

    EXPECT_EQ(heap.extractMin().first, 2);
    EXPECT_EQ(heap.extractMin().first, 2);
    EXPECT_EQ(heap.extractMin().first, 2);
	ASSERT_ANY_THROW(heap.extractMin());
}