#include <cstdio>
#include <cstring>

// Definição da estrutura Node e Stack
struct Node {
    char value;
    Node* next;
    Node(char _value) : value(_value), next(nullptr) {}
};

struct Stack {
    Node* top;
    int brindes; // Contador de brindes

    Stack() : top(nullptr), brindes(0) {}

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

    bool comparar(char v[4]) {
        Node* temp = top;
        int b=0;
        for (int i = 0; i < 4 && temp != nullptr; ++i) {
            if(v[i]!=temp->value){
                b=1;
            }
            temp = temp->next;
        }
        return b==0;

    }



    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
};



int main() {

    int N;
    int cont=0;
    Stack panel;
    panel.push('F');
    panel.push('A');
    panel.push('C');
    panel.push('E');


    scanf("%d%*c", &N);
    char nova[4];
    for (int i = 0; i < N; ++i) {
       scanf("%c %c %c %c%*c",&nova[0],&nova[1],&nova[2],&nova[3]);
       if(panel.comparar(nova)){

          cont++;
          panel.pop();
          panel.pop();
          panel.pop();
          panel.pop();
          if(panel.empty()){
            panel.push('F');
            panel.push('A');
            panel.push('C');
            panel.push('E');
          }
       }else{

           panel.push(nova[0]);
           panel.push(nova[1]);
           panel.push(nova[2]);
           panel.push(nova[3]);
       }

    }



    // Imprime o número de brindes
    printf("%d\n", cont);

    return 0;
}



