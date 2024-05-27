#ifndef STACK_H
#define STACK_H

class Stack {
    
private:
    int* data_;
    int capacity_;
    int top_;

    void resize();

public:
    Stack();
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& other);
    void push(int elem);
    int pop();
    bool isEmpty() const;
    void multiPop(int N);
    void show() const;
    
};

#endif