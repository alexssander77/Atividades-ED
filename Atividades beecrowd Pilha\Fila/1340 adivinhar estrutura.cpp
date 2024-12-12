#include <stdio.h>

struct Node {
    int value;
    Node* next;

    Node() : value(0), next(nullptr) {}
    Node(int _value) : value(_value), next(nullptr) {}
};

struct PriorityQueue {
    Node* first;
    bool is;

    PriorityQueue() : first(nullptr), is(true) {}

    bool empty() {
        return first == nullptr;
    }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = n;
            return;
        }
        if (value > first->value) {
            n->next = first;
            first = n;
            return;
        }
        Node* current = first;
        while (current->next != nullptr && current->next->value >= value) {
            current = current->next;
        }
        n->next = current->next;
        current->next = n;
    }

    void dequeue() {
        if (empty()) return;
        Node* toDel = first;
        first = first->next;
        delete toDel;
    }

    int front() {
        return empty() ? -1 : first->value;
    }
};

struct Queue {
    Node* first;
    Node* last;
    bool is;

    Queue() : first(nullptr), last(nullptr), is(true) {}

    bool empty() {
        return first == nullptr;
    }

    void enqueue(int value) {
        Node* n = new Node(value);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    void dequeue() {
        if (empty()) return;
        Node* toDel = first;
        first = first->next;
        if (!first) last = nullptr;
        delete toDel;
    }

    int front() {
        return empty() ? -1 : first->value;
    }
};

struct Stack {
    Node* t;
    bool is;

    Stack() : t(nullptr), is(true) {}

    bool empty() {
        return t == nullptr;
    }

    void push(int value) {
        Node* n = new Node(value);
        n->next = t;
        t = n;
    }

    void pop() {
        if (empty()) return;
        Node* toDel = t;
        t = t->next;
        delete toDel;
    }

    int top() {
        return empty() ? -1 : t->value;
    }
};

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        Stack s;
        Queue q;
        PriorityQueue pq;

        for (int i = 0; i < n; ++i) {
            int op, val;
            scanf("%d %d", &op, &val);
            if (op == 1) {
                s.push(val);
                q.enqueue(val);
                pq.enqueue(val);
            } else {
                if (s.empty() || s.top() != val) s.is = false;
                else s.pop();

                if (q.empty() || q.front() != val) q.is = false;
                else q.dequeue();

                if (pq.empty() || pq.front() != val) pq.is = false;
                else pq.dequeue();
            }
        }

        bool isStack = s.is, isQueue = q.is, isPriorityQueue = pq.is;

        if ((isStack && isQueue) || (isQueue && isPriorityQueue) || (isStack && isPriorityQueue)) {
            printf("not sure\n");
        } else if (!isStack && !isQueue && !isPriorityQueue) {
            printf("impossible\n");
        } else if (isStack) {
            printf("stack\n");
        } else if (isQueue) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }
    return 0;
}

