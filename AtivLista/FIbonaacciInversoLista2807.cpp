#include <stdio.h>

struct Node {

    int value;
    Node* next;

    Node() {
        value = 0;
        next = NULL;
    }

    Node(int _value) {
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* first;
    Node* last;


    List() {
        first = NULL;
        last = NULL;

    }


    bool empty() {
        return first == NULL;
    }



    void pushFront(int value) { // O(1)
        Node *n = new Node(value);

        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void print() {
        Node* aux = first;
        while (aux->next!= NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
        printf("%d\n", aux->value);

    }

};


int main() {
    int n;
    scanf("%d",&n);
    List l;
    int a=0,aux=0,b=1;
    for(int i=0;i<n;i++){
        l.pushFront(b);
        aux=a+b;
        a=b;
        b=aux;


    }
    l.print();
    return 0;
}
