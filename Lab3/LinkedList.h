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
    void ActualMergeSort(Node* first);
    Node *Middle(Node* nd);
    Node *Merger(Node* l, Node* r);
public:
    LinkedList();
    T& operator[](int i) override;
    void Push_back(T data) override;
    void Pop_back() override;
    void Set(T data, int i);
    void Clear()override;
    T Peek()override;
//sorts
    void InsertionSort() override;
    void BubbleSort() override;
    void SelectionSort() override;
    void MergeSort() override;
};

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    this->size = 0;
}

template<typename T>
T& LinkedList<T>::operator[](int i) {
    Node* temp = head;
    int j = 0;
    while (temp!=nullptr && j != i)
    {
        j++;
        temp = temp->next;
    }

    if (temp)
        return temp->data;
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

template <typename T>
T LinkedList<T>::Peek()
{
    try {
        if (head == nullptr)
        {
            std::string error = "List is empty";
            throw (error);
        }
        return head->data;
    }
    catch (std::string message)
    {
        std::cout << message << '\n';
    }
}

template <typename T>
void LinkedList<T>::InsertionSort()
{
    Node* sorted = nullptr;
    Node* temp = head;
    while (temp)
    {
        Node* curr = new Node();
        curr->data = temp->data;
        curr->next = nullptr;
        if (sorted == nullptr || sorted->data >= curr->data) {
            curr->next = sorted;
            sorted = curr;
        }
        else {
            Node* current = sorted;
            while (current->next != nullptr
                && current->next->data < curr->data) {
                current = current->next;
            }
            curr->next = current->next;
            current->next = curr;
        }
        temp = temp->next;
    }
    head = sorted;
}

template <typename T>
void LinkedList<T>::BubbleSort()
{
    Node* curr = head;
    Node* end = nullptr;
    int i = 1;

    while (end != head)
    {
        while (curr->next != end)
        {
            if (curr->data > curr->next->data)
                std::swap(curr->data, curr->next->data);
            curr = curr->next;
            i++;
        }
        end = curr;
        curr = head;
        i = 1;
    }
    head = end;
}

template <typename T>
void LinkedList<T>::SelectionSort()
{
    Node* temp = head;
    while (temp)
    {
        Node* minimal = temp;
        Node* curr = temp->next;
        while (curr)
        {
            if (minimal->data > curr->data)
                minimal = curr;
            curr = curr->next;
        }
        std::swap(temp->data, minimal->data);
        temp = temp->next;
    }

}

template <typename T>
void LinkedList<T>::MergeSort()
{
    this->ActualMergeSort(head);
}

template <typename T>
void LinkedList<T>::ActualMergeSort(Node* first)
{
    if (!first || !first->next)
        return first;
    Node* mid = Middle(first);
    Node* l = first, *r = mid->next;

    l = ActualMergeSort(l);
    r = ActualMergeSort(r);
    return Merger(l, r);
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>:: Middle(Node* nd)
{
    Node* fast = nd;
    Node* slow = nd;
    while (!fast && !fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
LinkedList<T>::Node* LinkedList<T>::Merger(Node* l, Node* r)
{
    Node* sorted = nullptr;
    Node* tail = nullptr;

    while (l && r)
    {
        Node* nxt = nullptr;
        if (l->data < r->data)
        {
            nxt = l;
            l = l->next;
        }
        else
        {
            nxt = r;
            r = r->next;
        }

        if (tail)
        {
            tail->next = nxt;
        }
        else
        {
            sorted = next;
            tail = nxt;
        }
        tail = tail->next;
    }

    if (l)
        tail->next = l;
    if (r)
        tail->next = r;

    return sorted;
}