#pragma once
#include "List.h"
#include <stdexcept>
#include <cstring>
template <typename T>
class ArrayList : public List<T>
{
private:
	int MAX_SIZE;
	T* arr;
    void Append();
public:
    ArrayList();
    T& operator[](int i) override;
    void Push_back(T data) override;
    void Pop_back() override;
    void Clear()override;
    T Peek()override;

//sorts
    void InsertionSort() override;
    void BubbleSort() override;
    void SelectionSort() override;
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