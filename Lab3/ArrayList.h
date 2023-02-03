#pragma once
#include "List.h"
#include <stdexcept>
template <typename T>
class ArrayList : public List<T>
{
private:
	int MAX_SIZE;
	T* arr;
    void Append();
public:
    ArrayList();
    T& operator[](int i);
    void Push_back(T data) override;
    void Pop_back() override;
    void Set(T data, int i) override;
    void Clear()override;
    void Print()override;
    T Peek()override;
};

template<typename T>
ArrayList<T>::ArrayList() {
    MAX_SIZE = 1;
    this->size = 0;
    arr = new T[1];
}

template<typename T>
T& ArrayList<T>::operator[](int i) {
    return arr[i];
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
    if (this->size > MAX_SIZE)
        Append();

    arr[this->size - 1] = data;
}


template<typename T>
void ArrayList<T>::Pop_back() {
    this->size--;
}

template <typename T>
void ArrayList<T>::Set(T data, int i)
{
    arr[i] = T;
}

template<typename T>
void ArrayList<T>::Clear() {
    delete[]arr;
    MAX_SIZE = 1;
    arr = new T[MAX_SIZE];
    this->size = 0;
}

template<typename T>
void ArrayList<T>::Print() {
    for (int i = 0; i < this->size; i++)
        std::cout << arr[i] << ' ';
}

template <typename T>
T ArrayList<T>::Peek()
{
    if (!this->size) throw std::invalid_argument("Array list is empty");
    else
        return arr[0];
}