#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"
#include "Figure.h"
#include <cstdlib>
#include<gtest/gtest.h>

ArrayList<int> a;
void IniciateA()
{
	for (int i = 0; i < 1000; i++)
		a.Push_back((rand() % 1000) * pow(-1, i));
}

struct ArrayListTest : testing::Test
{
	ArrayList<int> list;
	ArrayListTest() {
		list = a;
	}
	~ArrayListTest() {}
};

LinkedList<int> l;
void IniciateL()
{
	for (int i = 0; i < 1000; i++)
		l.Push_back((rand() % 1000) * pow(-1, i));
}

struct LinkedListTest : testing::Test
{
	LinkedList<int> list;
	LinkedListTest() {
		list = l;
	}
	~LinkedListTest() {}
};

TEST_F(ArrayListTest, ArrayListInsertionSortTest)
{
	list.InsertionSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i]<=list[i+1]);
	}
}

TEST_F(ArrayListTest, ArrayListBublleSortTest)
{
	list.BubbleSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(ArrayListTest, ArrayListSelectionSortTest)
{
	list.SelectionSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(ArrayListTest, ArrayListMergeSortTest)
{
	list.MergeSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(ArrayListTest, ArrayListQuickSortTest)
{
	list.QuickSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(LinkedListTest, LinkedListInsertionSortTest)
{
	list.InsertionSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(LinkedListTest, LinkedListBublleSortTest)
{
	list.BubbleSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(LinkedListTest, LinkedListSelectionSortTest)
{
	list.SelectionSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(LinkedListTest, LinkedListMergeSortTest)
{
	list.MergeSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

TEST_F(LinkedListTest, LinkedListQuickSortTest)
{
	list.QuickSort();

	for (int i = 0; i < list.Size() - 1; i++)
	{
		EXPECT_TRUE(list[i] <= list[i + 1]);
	}
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	srand((int)time(0));
	IniciateA();
	IniciateL();
	return RUN_ALL_TESTS();
}