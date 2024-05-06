#pragma once

#include <iostream>

namespace dsa_cpp {

template<typename T>
class Node {
public:
    int val;
    Node<T>* next;
    Node(const int& d) : val(d), next(nullptr) {}
};

template<typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    int getSize();
    void insertStart(T val);
    void insertEnd(T val);
    T getVal(int index);
    void remove(int index);
    void print();
    
private:
    Node<T>* head_;
    int size_;
};


template<typename T>
LinkedList<T>::LinkedList() : head_(new Node<T>(T())), size_(0) { }

template<typename T>
LinkedList<T>::~LinkedList() {
    while(head_) {
        Node<T>* next_node = head_->next;
        delete head_;
        head_ = next_node;
    }
}

template<typename T>
T LinkedList<T>::getVal(int index) {
    if(index < 0 || index >= size_) {
        throw std::out_of_range("Index out of range");
    } else {
        Node<T>* curr = head_->next;
        for(int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
}

template<typename T>
int LinkedList<T>::getSize() {
    return size_;
}

template<typename T>
void LinkedList<T>::insertStart(T val) {
    Node<T>* new_node = new Node<T>(val);
    new_node->next = head_->next;
    head_->next = new_node;
    ++size_;
}

template<typename T>
void LinkedList<T>::insertEnd(T val) {
    Node<T>* new_node = new Node<T>(val);
    Node<T>* curr = head_;
    while(curr->next) {
        curr = curr->next;
    }
    curr->next = new_node;
    ++size_;
}

template<typename T>
void LinkedList<T>::remove(int index) {
    if(index >= size_ || index < 0) {
        throw std::out_of_range("Index out of range.");
    } else {
        Node<T>* curr = head_;
        for(int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        Node<T>* to_delete = curr->next;
        curr->next = to_delete->next;
        delete(to_delete);
    }
    --size_;
}

template<typename T>
void LinkedList<T>::print() {
    Node<T>* curr = head_;
    while(curr->next) {
        std::cout << curr->next->val << "  ";
        curr=curr->next;
    }
    std::cout<<"\n";
}

} //namespace dsa_cpp