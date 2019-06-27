#pragma once

template<typename T>
struct Node {
    T key;
    Node* next;

    Node() {
        this->next = nullptr;
    }

    Node(T key) {
        this->key = key;
        this->next = nullptr;
    }
};