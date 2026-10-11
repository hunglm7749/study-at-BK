#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "IList.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

template<class T>
class CircularLinkedList : public IList<T> {
public:

    class Node;

protected:

    Node* head;
    Node* tail;
    int count;
    bool (*itemEqual)(T& lhs, T& rhs);
    void (*deleteUserData)(CircularLinkedList<T>*);

public:

    CircularLinkedList(void (*deleteUserData)(CircularLinkedList<T>*) = 0, bool (*itemEqual)(T&, T&) = 0)
    : head(nullptr), tail(nullptr), count(0), itemEqual(itemEqual), deleteUserData(deleteUserData) {}

    CircularLinkedList(const CircularLinkedList<T>& list)
    : head(nullptr), tail(nullptr), count(0), itemEqual(list.itemEqual), deleteUserData(list.deleteUserData) 
    {
        copyFrom(list);
    }

    CircularLinkedList<T>& operator=(const CircularLinkedList<T>& list) 
    {
        if (this == &list) return *this;
        removeInternalData();
        itemEqual = list.itemEqual;
        deleteUserData = list.deleteUserData;
        copyFrom(list);
        return *this;
    }

    ~CircularLinkedList() {
        removeInternalData();
    }

    void add(T e) override 
    {
        // TODO Q2

        Node* new_node = new Node(e);

        if (count == 0)
        {
            head = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
            new_node->next = head;
        }
        count++;
    }

    void add(int index, T e) override
    {
        // TODO Q2

        if (index < 0 || index > count)
            throw std::out_of_range("Index out of range!");

        Node* new_node = new Node(e);

        if (count == 0)
        {
            head = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else if (index == 0)
        {
            tail->next = new_node;
            new_node->next = head;
            head = new_node;
        }
        else if (index == count)
        {
            tail->next = new_node;
            tail = new_node;
            new_node->next = head;
        }
        else
        {
            Node* curr = tail;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }

            Node* next = curr->next;
            curr->next = new_node;
            new_node->next = next;
        }
        count++;
    }

    T removeAt(int index) override
    {
        // TODO Q2

        if (index < 0 || index >= count)
            throw std::out_of_range("Index out of range!");

        T data;
        if (count == 1)
        {
            data = head->data;
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else if (index == 0)
        {
            Node* next = head->next;
            data = head->data;
            delete head;
            head = next;
            tail->next = head;
        }
        else
        {
            Node* curr = tail;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }

            Node* next = curr->next->next;
            data = curr->next->data;
            delete curr->next;
            curr->next = next;

            if (index == count - 1)
            {
                tail = curr;
            }
        }

        count--;
        return data;
    }

    bool removeItem(T item, void (*removeItemData)(T) = 0) override 
    {
        // TODO Q2

        if (count == 0)
            return false;

        bool (*equal)(T&, T&) = (
            itemEqual != nullptr   ? 
            itemEqual              :
            [](T& a, T& b) { return a == b; }
        );

        Node* curr = tail;
        int i = 0;

        while (i < count)
        {
            if (equal(curr->next->data, item))
                break;

            curr = curr->next;
            i++;
        }

        if (i == count)
            return false;

        if (removeItemData != nullptr)
            removeItemData(curr->next->data);

        if (count == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else if (i == 0)
        {
            Node* next = head->next;
            delete head;
            head = next;
            tail->next = head;
        }
        else
        {
            Node* next = curr->next->next;
            delete curr->next;
            curr->next = next;

            if (i == count - 1)
            {
                tail = curr;
            }
        }

        count--;
        return true;
    }

    void clear() override
    {
        // TODO Q2
        
        if (deleteUserData != nullptr)
            deleteUserData(this);

        Node* curr = head;
        for (int i = 0; i < count; i++)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }

        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    T& get(int index) override
    {
        // TODO Q2

        if (index < 0 || index >= count)
            throw std::out_of_range("Index out of range!");

        if (index == 0)
            return head->data;
        if (index == count - 1)
            return tail->data;

        Node* curr = head;
        int i = 0;

        while (i < index)
        {
            i++;
            curr = curr->next;
        }

        return curr->data;
    }

    int indexOf(T item) override
    {
        // TODO Q2

        bool (*equal)(T&, T&) = (
            itemEqual != nullptr   ? 
            itemEqual              :
            [](T& a, T& b) { return a == b; }
        );

        Node* curr = head;
        for (int i = 0; i < count; (i++, curr = curr->next))
        {
            if (equal(curr->data, item))
                return i;
        }

        return -1;
    }

    bool empty() override { return count == 0; }
    int size() override { return count; }
    bool contains(T item) override { return indexOf(item) >= 0; }

    string toString(string (*item2str)(T&) = 0) override 
    {
        stringstream ss;
        ss << "[";
        Node* cur = head;
        for (int i = 0; i < count; ++i) 
        {
            if (i > 0) ss << ", ";
            if (item2str) ss << item2str(cur->data);
            else ss << cur->data;
            cur = cur->next;
        }
        ss << "]";
        return ss.str();
    }

    string debugString(int (*scale)(int) = nullptr)
    {
        int (*f)(int) = (
            scale != nullptr   ?
            scale              :
            [](int x) { return x; }
        );

        if (count > 0)
        {
            stringstream ss;
            ss << "[";
            Node* curr = head;
            for (int i = 0; i < f(size()); i++)
            {
                if (curr == head)
                    ss << "\e[38;2;215;119;87m" << curr->data << "\e[0m, ";
                else if (curr == tail)
                    ss << "\e[38;2;1;114;186m" << curr->data << "\e[0m, ";
                else
                    ss << curr->data << ", ";
                curr = curr->next;
            }
            ss << "...]";
            return ss.str();
        }
        else
        {
            return "[]";
        }
    }

    void println(string (*item2str)(T&) = 0) {
        cout << toString(item2str) << endl;
    }

protected:

    static bool equals(T& lhs, T& rhs, bool (*itemEqual)(T&, T&)) {
        return itemEqual ? itemEqual(lhs, rhs) : (lhs == rhs);
    }

    void copyFrom(const CircularLinkedList<T>& list) {
        Node* cur = list.head;
        for (int i = 0; i < list.count; ++i) {
            add(cur->data);
            cur = cur->next;
        }
    }

    void removeInternalData() {
        if (deleteUserData != 0) deleteUserData(this);
        Node* cur = head;
        for (int i = 0; i < count; ++i) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        head = tail = nullptr;
        count = 0;
    }

public:
    class Node {
    public:
        T data;
        Node* next;
        Node(T data, Node* next = nullptr) : data(data), next(next) {}
    };
};

template class CircularLinkedList<int>;

#endif
