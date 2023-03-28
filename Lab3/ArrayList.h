#pragma once
#include "List.h"
#include <stdexcept>
#include <cstring>
/**
 * @brief Represents an Array list container.
 */
template <typename T>
class ArrayList : public List<T>
{
private:
	int MAX_SIZE;
	T* arr;
    void Append();
    void ActualMergeSort(int l, int r);
    void Merger(int l, int mid, int r);
    void ActualQuickSort(int begin, int end);
    int Partition(int begin, int end);
public:
    ArrayList();
    /**
 * \brief Overloads the [] operator to access elements of the list.
 *
 * \param i Index of the element to be accessed.
 *
 * \return Reference to the element at the specified index.
 */
    T& operator[](int i) override;
    /**
 * \brief Adds a new element to the end of the container.
 *
 * \tparam T The type of the elements in the container.
 * \param data The element to be added to the container.
 */
 void Push_back(T data) override;

 /**
 * @brief Removes the last element from the container.
 *
 */
 void Pop_back() override;

 /**
 * @brief Removes all elements from the container.
 *
 */
 void Clear()override;

 /**
  * @brief Returns the last element of the container.
  *
  * @tparam T The type of the elements in the container.
  * @return The last element of the container.
  */
 T Peek()override;

 /**
  * @brief Sorts the elements of the container using the insertion sort algorithm.
  *
  */
 void InsertionSort() override;

    /**
     * @brief Sorts the elements of the container using the bubble sort algorithm.
     *
     */
    void BubbleSort() override;

    /**
     * @brief Sorts the elements of the container using the selection sort algorithm.
     *
     */
    void SelectionSort() override;

    /**
     * @brief Sorts the elements of the container using the merge sort algorithm.
     *
     */
    void MergeSort() override;

    /**
     * @brief Sorts the elements of the container using the quick sort algorithm.
     *
     */
    void QuickSort() override;
};

template<typename T>
ArrayList<T>::ArrayList() {
    MAX_SIZE = 1;
    this->size = 0;
    arr = nullptr;
}

template<typename T>
T& ArrayList<T>::operator[](int i) {
    try
    {
        if (i < 0 || i >= this->size) {
            std::string error = "Index out of range";
            throw std::out_of_range(error);
        }
        return arr[i];
    }
    catch (std::out_of_range& err)
    {
        std::cout << "Out of range exeption: " << err.what() << '\n';
    }
    catch (...)
    {
        std::cout << "An error occured\n";
    }

}

template<typename T>
void ArrayList<T>::Append() {
    MAX_SIZE *= 2;
    T* newArr = new T[MAX_SIZE];

    for (int i = 0; i < this->size - 1; i++)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

template<typename T>
void ArrayList<T>::Push_back(T data) {
    this->size++;
    if (arr == nullptr || this->size > MAX_SIZE)
        Append();

    arr[this->size - 1] = data;
}


template<typename T>
void ArrayList<T>::Pop_back() {
    if (arr == nullptr) return;
    this->size--;
}

template<typename T>
void ArrayList<T>::Clear() {
    delete[]arr;
    arr = nullptr;
    MAX_SIZE = 1;
    this->size = 0;
}

template <typename T>
T ArrayList<T>::Peek()
{
    try {
        if (arr == nullptr) {
            std::string error = "Array is empty";
            throw (error);
        }
        else {
            return arr[0];
        }
    }
    catch (std::string message)
    {
        std::cout<<message<<'\n';
    }
}

template <typename T>
void ArrayList<T>::InsertionSort()
{
    for (int i = 0; i < this->size; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}

template <typename T>
void ArrayList<T>::BubbleSort()
{
    for (int i = 0; i < this->size - 1; i++)
        for (int j = 0; j < this->size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

template <typename T>
void ArrayList<T>::SelectionSort()
{
    for (int i = 0; i < this->size - 1; i++)
    {
        T cmpData = arr[i];
        int x = i;
        for (int j = i + 1; j < this->size; j++)
            if (cmpData > arr[j]) {
                cmpData = arr[j];
                x = j;
            }
        std::swap(arr[i], arr[x]);
    }
}

template <typename T>
void ArrayList<T>::MergeSort()
{
    this->ActualMergeSort(0, this->size - 1);
}

template <typename T>
void ArrayList<T>::ActualMergeSort(int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    ActualMergeSort(l, mid);
    ActualMergeSort(mid + 1, r);
    Merger(l, mid, r);
}

template <typename T>
void ArrayList<T>::Merger(int l, int mid, int r)
{
    int _leftS = mid - l + 1;
    int _rightS = r - mid;

    T* leftSub = new T[_leftS];
    T* rightSub = new T[_rightS];

    for (int i = 0; i < _leftS; i++)
        leftSub[i] = arr[l + i];
    for (int j = 0; j < _rightS; j++)
        rightSub[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = l;

    while (i < _leftS && j < _rightS) {
        if (leftSub[i] <= rightSub[j]) {
            arr[k] = leftSub[i];
            i++;
        }
        else {
            arr[k] = rightSub[j];
            j++;
        }
        k++;
    }

    while (i < _leftS) {
        arr[k] = leftSub[i];
        i++;
        k++;
    }

    while (j < _rightS) {
        arr[k] = rightSub[j];
        j++;
        k++;
    }
}

template <typename T>
void ArrayList<T>::QuickSort()
{
    this->ActualQuickSort(0, this->size - 1);
}

template <typename T>
void ArrayList<T>::ActualQuickSort(int begin, int end)
{
    if (begin >= end) return;

    int pivot = Partition( begin, end);
    ActualQuickSort(begin, pivot - 1);
    ActualQuickSort(pivot + 1, end);
}

template <typename T>
int ArrayList<T>::Partition(int begin, int end)
{
    T pivot = arr[end];
    int i = begin - 1;

    for (int j = begin; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[++i], arr[end]);
    return i;
}