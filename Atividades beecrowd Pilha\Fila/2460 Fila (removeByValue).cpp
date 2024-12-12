#include <stdio.h>

struct Node {
    int value;
    Node* next;

    Node(int _value){
        value=_value;
        next=NULL;
    }
};

struct Queue {
    Node* first;
    Node* last;

    Queue() : first(nullptr), last(nullptr) {}

    bool empty() {
        return first == nullptr;
    }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = last = n;
            return;
        }
            last->next = n;
            last = n;

    }

    void dequeue() {
        if (empty()) return;
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    void remove(int value) {
        if (empty()) return;
        if (first->value == value) {
            Node* toDel = first;
            first = first->next;
            delete(toDel);
            if (first == NULL) last = NULL;
            return;
        }



        Node* current = first;
        while (current->next && current->next->value != value) {

            current = current->next;
        }

        Node* toDel = current->next;
        current->next = toDel->next;
        if (toDel == last) last = current;
        delete(toDel);
    }

    void front() {
        if (empty()) return;
        printf("%d", first->value);
        if (first != last){
            printf(" ");
            return;
        }

        printf("\n");

    }


};

int main() {
    int N, M, x;
    Queue fila;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {

        scanf("%d", &x);
        fila.enqueue(x);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {

        scanf("%d", &x);
        fila.remove(x);
    }

    while (!fila.empty()) {
        fila.front();
        fila.dequeue();
    }

    return 0;
}
