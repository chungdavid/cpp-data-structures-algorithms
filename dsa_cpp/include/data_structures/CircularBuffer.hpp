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
CircularBuffer<T, N>::CircularBuffer() : size_(0), front_(0), back_(-1) { }

template<typename T, size_t N>
CircularBuffer<T, N>::~CircularBuffer() { }

template<typename T, size_t N>
size_t CircularBuffer<T, N>::getSize() const {
    return size_;
}

template<typename T, size_t N>
bool CircularBuffer<T, N>::isEmpty() const {
    return size_ == 0;
}

template<typename T, size_t N>
void CircularBuffer<T, N>::push(T val) {
    back_ = (back_ + 1) % N;
    buffer_[back_] = val;
    if(size_ < N) {
        ++size_;
    } else {
        front_ = (front_ + 1) % N;
    }
}

template<typename T, size_t N>
T CircularBuffer<T, N>::pop() {
    if(size_ == 0) {
        throw std::out_of_range("Buffer is empty, cannot pop from buffer.");
    } else {
        T front_val = buffer_[front_];
        front_ = (front_ + 1) % N;
        --size_;
        return front_val;
    }
}


} //namespace dsa_cpp