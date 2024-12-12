#include <stdio.h>
#include <string.h>

#define MAX 1000


struct Node {
    char value;
    Node* next;
    Node(char _value) : value(_value), next(nullptr) {}
};


struct Stack {
    Node* top;

    Stack() : top(nullptr) {}

    bool empty() {
        return top == nullptr;
    }

    void push(char value) {
        Node* n = new Node(value);
        n->next = top;
        top = n;
    }

    void pop() {
        if (!empty()) {
            Node* toDelete = top;
            top = top->next;
            delete toDelete;
        }
    }

    char peek() {
        return empty() ? '\0' : top->value;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }


    int contarDiamantes() {
        int diamantes = 0;
        int contadorAberturas = 0;

        Node* current = top;

        while (current != nullptr) {
            if (current->value == '>') {
                contadorAberturas++;
            } else if (current->value == '<') {
                if (contadorAberturas > 0) {
                    contadorAberturas--;
                    diamantes++;
                }
            }
            current = current->next;
        }

        return diamantes;
    }
};

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char str[MAX];
        scanf("%s", str);

        Stack pilha;


        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '<' || str[i] == '>') {
                pilha.push(str[i]);
            }
        }


        printf("%d\n", pilha.contarDiamantes());
    }

    return 0;
}








