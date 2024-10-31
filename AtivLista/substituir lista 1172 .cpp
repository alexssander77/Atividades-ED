#include <stdio.h>

struct Node{
    int value;
    Node* next;

    Node(){
        value=0;
        next=NULL;
    }
    Node(int _value){
        value=_value;
        next=NULL;
    }

};

struct List{
    Node* first;
    Node* last;

    List(){
        first = NULL;
        last = NULL;
    }

    bool empty(){
        return first==NULL;
    }

    void pushBack(int value){
        Node *n= new Node(value);
        if(empty()){
            first=n;
            last=n;
            return;
        }
        last->next=n;
        last=n;

    }
    void printar(){
        Node* aux=first;
        int cont=0;
        while(aux->next!=NULL){
            printf("X[%d] = %d\n",cont,aux->value);
            cont++;
            aux=aux->next;
        }
        printf("X[%d] = %d\n",cont,aux->value);

    }

};


int main() {
    List l;
    for(int i=0;i<10;i++){
        int num;
        scanf("%d",&num);
        if(num<=0){
            num=1;
        }
        l.pushBack(num);
    }
    l.printar();



    return 0;
}
