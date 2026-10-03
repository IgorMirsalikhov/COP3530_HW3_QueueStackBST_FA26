#include "Queue.hpp"
#include <iostream>
#include <stdexcept>

template <typename T, int capacity>
Queue<T, capacity>::Queue() {
    front_idx = back_idx = queue_size = 0;
}

template <typename T, int capacity>
bool        Queue<T, capacity>::empty() const {
    return queue_size == 0;
}

template <typename T, int capacity>
bool        Queue<T, capacity>::full() const {
    return queue_size == capacity;
}

template <typename T, int capacity>
void        Queue<T, capacity>::print() const {
    std::cout << "[ ";
    int i = front_idx;
    while (i != back_idx) {
        std::cout << data[i];
        i = (i + 1) % capacity;     // Go to the next element
        if (i != back_idx) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
}

template <typename T, int capacity>
void       Queue<T, capacity>::enqueue(const T& val) {
    if (!full()) {
        data[back_idx] = val;
        back_idx = (back_idx + 1) % capacity;
        queue_size++;
    }
}

template <typename T, int capacity>
const T&    Queue<T, capacity>::dequeue() {
    if (empty()) {
        throw std::out_of_range("dequeue: Empty queue");
    }
    int old_front = front_idx;
    front_idx = (front_idx + 1) % capacity;
    queue_size--;
    return data[old_front];
}
