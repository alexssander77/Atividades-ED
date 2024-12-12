#include<stdio.h>

struct Node {
    int value;
    Node* next;
    Node* prev;

    Node() {
        next = NULL;
        prev = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
        prev = NULL;
    }

};

struct DList {

    Node *first;
    Node *last;
    int c;

    DList() {
        first = NULL;
        last = NULL;
        c = 0;
    }

    bool empty() { //O(1)
        return first == NULL;
    }

    void pushBack(int v) { //O(1)
        Node *n = new Node(v);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->prev = last;
        last->next = n;
        last = n;
    }

    void pushFront(int v) { //O(1)
        Node *n = new Node(v);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        first->prev = n;
        n->next = first;
        first = n;
    }

    void print() { //O(n)
        Node* aux = first;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->next;
        }
        printf("\n");
    }

    void printBackward() { //O(n)
        Node* aux = last;
        while (aux != NULL) {
            printf("%d -> ", aux->value);
            aux = aux->prev;
        }
        printf("\n");
    }

    void popFront() { //O(1)
        if (empty()) return;
        if (c == 1) {
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = first;
        first = first->next;
        first->prev = NULL;
        delete(toDel);
        c--;
    }

    void popBack() { // O(1)
        if (empty()) return;
        if (c == 1) {
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = last;
        last = last->prev;
        last->next = NULL;
        delete(toDel);
        c--;
    }

    void insert(int v, int p) { //O(n)
        if (p <= 0) {
            pushFront(v);
            return;
        }
        if (p >= c) {
            pushBack(v);
            return;
        }
        Node* n = new Node(v);
        c++;
        Node* aux1 = first;
        for (int i = 0; i < p - 1; i++) {
            aux1 = aux1->next;
        }
        Node* aux2 = aux1->next;
        n->prev = aux1;
        n->next = aux2;
        aux1->next = n;
        aux2->prev = n;
    }

};

int main() {

    DList l;



    return 0;
}
