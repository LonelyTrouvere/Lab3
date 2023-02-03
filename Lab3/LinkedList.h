#pragma once
#include "List.h"
#include <limits>
#include <stdexcept>

template <typename T>
class LinkedList : public List<T>
{
private:
    class Node {
    public:
        T data;
        Node* next;
        Node()
        {
            this->next = nullptr;
        }
        Node(T data, Node* ptr = nullptr) {
            this->data = data;
            this->next = ptr;
        }
    };
    Node* head;
public:
    LinkedList();
    void Push_back(T data) override;
    void Pop_back() override;
    void Set(T data, int i) override;
    void Clear()override;
    void Print()override;
    T Peek()override;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    this->size = 0;
}

template <typename T>
void LinkedList<T>::Push_back(T data) {

    Node* newNode = new Node(data);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node* cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    this->size++;
};

template <typename T>
void LinkedList<T>::Pop_back()
{
    if (!head)
        return;
    if (this->size == 1)
    {
        delete head;
        head = nullptr;
    }
    else {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;
        delete curr;
    }
    this->size--;
}

template<typename T>
void LinkedList<T>::Clear() {
    while (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    this->size = 0;
}

template<typename T>
void LinkedList<T>::Set(T data, int i) {
    if (!head || i > this->size)
        return;
    i--;
    Node* cur = head;
    while (i--)
        cur = cur->next;
    cur->data = data;
}

template<typename T>
void LinkedList<T>::Print() {

    if (!head)
        return;

    Node* cur = head;
    while (cur)
    {
        std::cout << cur->data << '\n';
        cur = cur->next;
    }
}

template <typename T>
T LinkedList<T>::Peek()
{
    if (head == nullptr) return NULL;
    return head->data;
}





