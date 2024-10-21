#include <gtest.h>
#include "dheap.h"

TEST(DHeap, can_create_dheap_with_d)
{
	ASSERT_NO_THROW(DHeap heap(3));
}

TEST(DHeap, throws_when_creating_with_zero_d) {
	ASSERT_ANY_THROW(DHeap heap(0));
}

TEST(DHeap, throws_when_d_is_negative)
{
	ASSERT_ANY_THROW(DHeap heap(-1));
}

TEST(DHeap, can_create_large_d) {
	DHeap heap(100);
	ASSERT_NO_THROW(heap.Insert(1, 1));
	ASSERT_NO_THROW(heap.Insert(2, 1));
}

TEST(DHeap, can_insert_in_dheap)
{
	DHeap heap(2);
	ASSERT_NO_THROW(heap.Insert(2, 1));
}

TEST(DHeap, can_insert_large_number_of_elements) {
	DHeap heap(2);
	for (int i = 0; i < 1000; ++i) {
		heap.Insert(i, i);
	}
	for (int i = 0; i < 1000; ++i) {
		EXPECT_EQ(heap.ExtractMin().first, i);
	}
}

TEST(DHeap, can_insert_and_check_if_empty) {
	DHeap heap(2);
	EXPECT_TRUE(heap.IsEmpty());

	heap.Insert(1, 1);
	EXPECT_FALSE(heap.IsEmpty());

	heap.ExtractMin();
	EXPECT_TRUE(heap.IsEmpty());
}

TEST(DHeap, test_dheap_is_empty)
{
	DHeap heap(2);
	EXPECT_TRUE(heap.IsEmpty());
}

TEST(DHeap, test_dheap_is_not_empty)
{
	DHeap heap(2);
	heap.Insert(1,2);
	EXPECT_TRUE(!heap.IsEmpty());
}

TEST(DHeap, can_extract_min_from_dheap) {
	DHeap heap(2);
	heap.Insert(1, 2);
	heap.Insert(3, 2);
	heap.Insert(2, 2);
	EXPECT_EQ(heap.ExtractMin().first, 1);
}

TEST(DHeap, throws_when_extracting_from_empty_dheap) {
	DHeap heap(3);
	ASSERT_ANY_THROW(heap.ExtractMin());
}

TEST(DHeap, throws_when_extracting_min_after_emptying_heap) {
	DHeap heap(2);
	heap.Insert(1, 1);
	heap.ExtractMin();

	ASSERT_ANY_THROW(heap.ExtractMin());
}

TEST(DHeap, can_extract_min_from_multiple_elements) {
	DHeap heap(3);
	heap.Insert(1, 100);
	heap.Insert(2, 50);
	heap.Insert(3, 2);
	heap.Insert(4, 1);

	EXPECT_EQ(heap.ExtractMin().first, 4);
	EXPECT_EQ(heap.ExtractMin().first, 3);
	EXPECT_EQ(heap.ExtractMin().first, 2);
	EXPECT_EQ(heap.ExtractMin().first, 1);
}

TEST(DHeap, can_handle_duplicate_elements) {
    DHeap heap(3);
    heap.Insert(1, 2);
    heap.Insert(2, 2);
    heap.Insert(3, 2);

    EXPECT_EQ(heap.ExtractMin().second, 2);
    EXPECT_EQ(heap.ExtractMin().second, 2);
    EXPECT_EQ(heap.ExtractMin().second, 2);
	ASSERT_ANY_THROW(heap.ExtractMin());
}

TEST(DHeap, can_insert_and_extract_negative_numbers) {
	DHeap heap(2);
	heap.Insert(1, -1);
	heap.Insert(2, -3);
	heap.Insert(3, -2);

	EXPECT_EQ(heap.ExtractMin().first, 2);
	EXPECT_EQ(heap.ExtractMin().first, 3);
	EXPECT_EQ(heap.ExtractMin().first, 1);
}
 



TEST(DHeap, throws_when_extracting_more_than_inserted) {
    DHeap heap(2);
    for (int i = 0; i < 10; ++i) {
        heap.Insert(i, i);
    }
    for (int i = 0; i < 10; ++i) {
        heap.ExtractMin();
    }
    ASSERT_ANY_THROW(heap.ExtractMin());
}