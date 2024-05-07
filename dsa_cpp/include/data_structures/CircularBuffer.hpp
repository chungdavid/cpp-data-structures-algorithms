#pragma once

#include <iostream>

namespace dsa_cpp {


template<typename T, size_t N>
class CircularBuffer {
public:
    CircularBuffer();
    ~CircularBuffer();
    size_t getSize() const;
    bool isEmpty() const;
    void push(T val);
    T pop();

private:
    size_t size_;
    size_t front_;
    size_t back_;
    T buffer_[N];
};

template<typename T, size_t N>
CircularBuffer<T, N>::CircularBuffer() {
    //TODO
}

template<typename T, size_t N>
CircularBuffer<T, N>::~CircularBuffer() {
    //TODO
}

template<typename T, size_t N>
size_t CircularBuffer<T, N>::getSize() const {
    //TODO
    return 100;
}

template<typename T, size_t N>
bool CircularBuffer<T, N>::isEmpty() const {
    //TODO
    return false;
}

template<typename T, size_t N>
void CircularBuffer<T, N>::push(T val) {
    //TODO
}

template<typename T, size_t N>
T CircularBuffer<T, N>::pop() {
    //TODO
    return T();
}



} //nameaspace dsa_cpp