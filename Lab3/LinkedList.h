#pragma once
#include "List.h"
#include <limits>
#include <stdexcept>


/**
 * @brief Represents a Linked list container.
 */
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

    Node* ActualMergeSort(Node* first)
    {
        if (first == nullptr || first->next == nullptr)
            return first;
        Node* mid = Middle(first);
        Node*r = mid->next;
        mid->next = nullptr;

        first = ActualMergeSort(first);
        r = ActualMergeSort(r);
        return Merger(first, r);
    }
    Node* Middle(Node* nd)
    {
        Node* fast = nd->next;
        Node* slow = nd;
        while (fast!=nullptr && fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    Node* Merger(Node* l, Node* r)
    {
        Node* sorted = nullptr;
        Node* tail = nullptr;

        if (l->data < r->data)
        {
            sorted = l;
            l = l->next;
        }
        else
        {
            sorted = r;
            r = r->next;
        }
        tail = sorted;

        while (l != nullptr && r != nullptr)
        {
            if (l->data <= r->data) {
                tail->next = l;
                l = l->next;
            }
            else {
                tail->next = r;
                r = r->next;
            }

            tail = tail->next;
        }

        if (l != nullptr)
            tail->next = l;
        if (r != nullptr)
            tail->next = r;

        return sorted;
    }

    Node* getTail(Node* cur)
    {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }

     Node* partition( Node* head,  Node* end, Node** newHead, Node** newEnd)
    {
        Node* pivot = end;
        Node* prev = NULL, * cur = head, * tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if ((*newHead) == NULL)
                    (*newHead) = cur;

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;

                Node* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if ((*newHead) == NULL)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }

     Node* quickSortRecur( Node* head, Node* end)
    {
        if (!head || head == end)
            return head;

        Node* newHead = NULL, * newEnd = NULL;
        Node* pivot = partition(head, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSortRecur(newHead, tmp);

            tmp = getTail(newHead);
            tmp->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }
public:
    LinkedList();
    /**
  * @brief Returns a reference to the element at the specified position in the container.
  *
  * @tparam T The type of the elements in the container.
  * @param i The position of the element to return.
  * @return A reference to the element at the specified position in the container.
  */
    T& operator[](int i) override;

    /**
     * @brief Adds a new element to the end of the container.
     *
     * @tparam T The type of the elements in the container.
     * @param data The element to be added to the container.
     */
    void Push_back(T data) override;

    /**
     * @brief Removes the last element from the container.
     *
     */
    void Pop_back() override;

    /**
     * @brief Sets the value of the element at the specified position in the container.
     *
     * @tparam T The type of the elements in the container.
     * @param data The new value of the element.
     * @param i The position of the element to set.
     */
    void Set(T data, int i);

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
    head = this->ActualMergeSort(head);
}

template <typename T>
void LinkedList<T>::QuickSort()
{
    head = this->quickSortRecur(head, getTail(head));
}