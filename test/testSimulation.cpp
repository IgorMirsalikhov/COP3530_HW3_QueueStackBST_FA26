#include "Stack.hpp"
#include "Queue.hpp"


#include <cstdlib>

void init(Queue<int>& q, Stack<int>& s, int quantity);
void print(const Queue<int>& q, const Stack<int>& s);
void feed_students(Queue<int>& q, Stack<int>& s);


int main() {
    std::cout << "Enter seed: ";
    int seed = 0;
    std::cin >> seed;
    srand(seed);
    
    Queue<int> q;
    Stack<int> s;
    init(q, s, 10);
    std::cout << "Students came to caffeteria\n";
    print(q, s);

    feed_students(q, s);

    return 0;
}

void init(Queue<int>& q, Stack<int>& s, int quantity) {
    for (int i = 0; i < quantity; i++) {
        q.enqueue(rand() % 2);
        s.push(rand() % 2);
    }
}
