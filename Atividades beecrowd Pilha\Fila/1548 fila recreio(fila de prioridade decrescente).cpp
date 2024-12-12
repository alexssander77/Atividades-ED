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

struct Queue {

    Node* first;
    Node* last;

    Queue() {
        first = NULL;
        last = NULL;
    }

    bool empty() {
        return first == NULL;
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
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
    }
    int sortCompare(int tamanho){
        int cont=0;

        int v[tamanho];
        Node* aux=first;
        for(int i=0;i<tamanho;i++){
            v[i]=aux->value;
            aux=aux->next;
        }

        bool swapped;
        do {
            swapped = false;
            Node* current = first;
            while (current != NULL && current->next != NULL) {
                if (current->value < current->next->value) {
                    // Troca os valores entre os nós
                    int temp = current->value;
                    current->value = current->next->value;
                    current->next->value = temp;

                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped); // Continua até não houver mais trocas

        aux=first;
        for(int i=0;i<tamanho;i++){
            if(v[i]==aux->value){
                cont++;
            }
            aux=aux->next;
        }

        return cont;
    }



};

int main() {

    Queue q;

    int m;
    scanf("%d",&m);
    while(m--){

        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            q.enqueue(num);
        }
        printf("%d\n",q.sortCompare(n));



        while (!q.empty()) {
        q.dequeue();
        }
    }




    return 0;
}
