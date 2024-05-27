#include "stack.h"
#include <iostream>
#include <algorithm>

Stack::Stack() : data_(new int[1]), capacity_(1), top_(-1) {}

Stack::Stack(const Stack& other) : data_(new int[other.capacity_]), capacity_(other.capacity_), top_(other.top_) {
    std::copy(other.data_, other.data_ + other.capacity_, data_);
}

Stack::~Stack() {
    delete[] data_;
    data_ = nullptr;
}

Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        delete[] data_;
        data_ = new int[other.capacity_];
        capacity_ = other.capacity_;
        top_ = other.top_;
        std::copy(other.data_, other.data_ + other.capacity_, data_);
    }
    return *this;
}

void Stack::push(int elem) {
    if (top_ + 1 == capacity_) resize();
    data_[++top_] = elem;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }
    return data_[top_--];
}

bool Stack::isEmpty() const {
    return top_ == -1;
}

void Stack::multiPop(int N) {
    while (N-- > 0 && !isEmpty()) pop();
}

void Stack::show() const {
    for (int i = 0; i <= top_; i++) i==top_ ? std::cout << data_[i] : std::cout << data_[i] << " ";
    std::cout << std::endl;
}

void Stack::resize(){
    int newCapacity = capacity_ * 2;
    int* newData = new int[newCapacity];
    std::copy(data_, data_ + capacity_, newData);
    delete[] data_;
    data_ = newData;
    capacity_ = newCapacity;
}
