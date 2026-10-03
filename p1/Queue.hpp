#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T, int capacity = 100>
class Queue {
public:
    Queue();

    bool        empty() const;
    bool        full() const;
    void        print() const;
    void        enqueue(const T& val);

    const T&    dequeue();

    // TODO
    const T&    front(); // Return the first element in the queue
    void        clear(); // Remove all the elements from the queue
    int         size();  // Return the size of the queue

    
private:
    T data[capacity];
    int front_idx, back_idx;
    int queue_size;
};

#include "Queue.tpp"

#endif