#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() {
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct PriorityQueue {

    Node* first;
    Node* last;

    PriorityQueue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
    }

    void enqueue(int value) {
        Node* n = new Node(value);


        if (empty() || value < first->value) {
            n->next = first;
            first = n;
            if (last == NULL || n->next == NULL) {
                last = n;
            }
            return;
        }


        Node* current = first;
        while (current->next != NULL && current->next->value <= value) {
            current = current->next;
        }
        if (current->next == NULL) {
            last = n;
        }
        n->next = current->next;
        current->next = n;



    }

    void dequeue() {
        if (empty()) return;
        Node* toDel = first;
        first = first->next;
        if (first == NULL) {
            last = NULL;
        }
        delete(toDel);
    }

    int front() {
        if (empty()) {
            printf("Empty queue\n");
            return -1;
        }
        return first->value;
    }

    void printLast() {
        if (last == NULL) {
            printf("Last is NULL\n");
        } else {
            printf("Last value: %d\n", last->value);
        }
    }

};

int main() {

    PriorityQueue pq;

    pq.enqueue(15);
    pq.enqueue(5);
    pq.enqueue(9);
    pq.enqueue(1);
    pq.enqueue(20);
    pq.enqueue(19);

    pq.printLast();

    while (!pq.empty()) {
        printf("%d\n", pq.front());
        pq.dequeue();
    }

    pq.printLast();

    return 0;
}


