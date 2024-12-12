#include <stdio.h>
#include <string.h>


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
    void conferir(){
        int confirm=0;
        Node* aux=top;
        while(aux!=NULL){
            if(aux->value==')'){
                confirm++;
            }else{
                confirm--;
            }
            if(confirm<0){
              printf("incorrect\n") ;
              return;
            }
            aux=aux->next;
        }
        if(confirm!=0){
            printf("incorrect\n");
        }else{
            printf("correct\n");
        }

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
};

int main() {

    char st[1000];
    while (scanf("%s",st)!=EOF) {
        char c;
        Stack s;
        for(int i=0;i<strlen(st);i++){
            if(st[i]=='('||st[i]==')'){
                s.push(st[i]);
            }
        }

        s.conferir();

    }

    return 0;
}

