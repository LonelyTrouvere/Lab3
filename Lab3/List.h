#pragma once
#include <iostream>
/**

@brief A template class for creating a List data structure.
This class provides the basic functionality of a List data structure.
@tparam T The type of data stored in the List.
*/
template <typename T>
class List
{
protected:
	int size = 0; 
public:
	/**
	* @brief Gets the current size of the List.
	* @return The size of the List.
	*/
	virtual int Size()
	{
		return size;
	}
	/**
 * @brief Gets a reference to an element at a specific index.
 * @param i The index of the element to retrieve.
 * @return A reference to the element at the specified index.
 */
	virtual T& operator[](int i) = 0;

	/**
	 * @brief Adds an element to the end of the List.
	 * @param data The element to add to the List.
	 */
	virtual void Push_back(T data) = 0;

	/**
	 * @brief Removes the last element from the List.
	 */
	virtual void Pop_back() = 0;

	/**
	 * @brief Removes all elements from the List.
	 */
	virtual void Clear() = 0;

	/**
	 * @brief Gets the value of the first element in the List.
	 * @return The value of the first element in the List.
	 */
	virtual T Peek() = 0;

	/**
	 * @brief Determines if the List is empty.
	 * @return True if the List is empty, false otherwise.
	 */
	virtual bool Empty()
	{
		if (!size) return true;
		return false;
	}

	/**
	 * @brief Sorts the List in ascending order using the insertion sort algorithm.
	 */
	virtual void InsertionSort() = 0;

	/**
	 * @brief Sorts the List in ascending order using the bubble sort algorithm.
	 */
	virtual void BubbleSort() = 0;

	/**
	 * @brief Sorts the List in ascending order using the selection sort algorithm.
	 */
	virtual void SelectionSort() = 0;

	/**
	 * @brief Sorts the List in ascending order using the merge sort algorithm.
	 */
	virtual void MergeSort() = 0;

	/**
	 * @brief Sorts the List in ascending order using the quick sort algorithm.
	 */
	virtual void QuickSort() = 0;
};