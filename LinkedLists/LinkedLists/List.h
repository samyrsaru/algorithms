#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class List {
private:
    Node<T>* head;
    int size;

public:
    List() {
        head = new Node<T>(-1);
        size = 0;
    }

    ~List() {
        Node<T>* current = head->next;
        while (current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }

        delete head;
    }

    void push(T value) {
        Node<T>* current = head;
        while (current->next != nullptr)
            current = current->next;

        Node<T>* newNode = new Node<T>(value);

        current->next = newNode;
        ++size;
    }

    void add(T value, int position)
    {
        if (position < 0 || position > size)
            return;

        Node<T>* current = head;
        int currentPosition = -1;
        while (currentPosition < position-1)
        {
            current = current->next;
            currentPosition++;
        }

        Node<T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;
        ++size;
    }

    Node<T>* getNode(int position)
    {
        if (position < 0 || position >= size)
            return nullptr;

        Node<T>* current = head;
        int currentPosition = -1;
        while (currentPosition < position)
        {
            current = current->next;
            currentPosition++;
        }

        return current;
    }

    T getValue(int position)
    {
        if (position < 0 || position >= size)
            return -1;

        Node<T>* current = head;
        int currentPosition = -1;
        while (currentPosition < position)
        {
            current = current->next;
            currentPosition++;
        }

        return current->key;
    }

    void reverse()
    {
        if (!size)
            return;

        Node<T>* current = head->next;
        Node<T>* next = current->next;

        current->next = nullptr;
        Node<T>* pre = nullptr;
        while (next)
        {
            pre = current;
            current = next;
            next = next->next;
            current->next = pre;
        }

        head->next = current;
    }

    void print()
    {
        Node<T>* current = head->next;
        while (current != nullptr)
        {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
};