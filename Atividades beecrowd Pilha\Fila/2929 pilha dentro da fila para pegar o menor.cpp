#include <stdio.h>
#include <string.h>

struct Node {
    long long value;
    Node* next;

    Node(long long _value) : value(_value), next(nullptr) {}
};

struct Stack {
    Node* t;
    Node* minStack;

    Stack() : t(nullptr), minStack(nullptr) {}

    bool empty() {
        return t == nullptr;
    }

    void push(long long value) {
        Node* n = new Node(value);
        n->next = t;
        t = n;


        if (minStack == nullptr || value <= minStack->value) {
            Node* minNode = new Node(value);
            minNode->next = minStack;
            minStack = minNode;
        }
    }

    void pop() {
        if (empty()){
           printf("EMPTY\n");
           return;
        }

        Node* toDel = t;
        t = t->next;


        if (minStack != nullptr && minStack->value == toDel->value) {
            Node* minToDel = minStack;
            minStack = minStack->next;
            delete minToDel;
        }

        delete toDel;
    }

    long long top() {
        return empty() ? -1 : t->value;
    }

    void min() {
        if (empty()) {
            printf("EMPTY\n");
        } else {
            printf("%lld\n", minStack->value);
        }
    }
};

int main() {
    Stack s;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char comando[100];
        scanf("%s", comando);

        if (strcmp(comando, "PUSH") == 0) {
            long long m;
            scanf("%lld", &m);
            s.push(m);
        } else if (strcmp(comando, "MIN") == 0) {
            s.min();
        } else if (strcmp(comando, "POP") == 0) {
            s.pop();
        }
    }

    return 0;
}
