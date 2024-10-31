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
    int menor;
    int c;
    int menorP;
    List(){
        first=NULL;
        last=NULL;
        c=0;

    }

    bool empty(){
        return first==NULL;
    }

    void pushBack(int value){
        Node *n= new Node(value);
        if(empty()){
            first=n;
            last=n;
            menor=value;
            menorP=0;
            return;
        }

        last->next=n;
        last=n;
        c++;
        if(value<menor){
            menor=value;
            menorP=c;
        }

    }
    void printar(){
        printf("Menor valor: %d\n",menor);
        printf("Posicao: %d\n",menorP);
    }

};


int main() {
    int n;
    scanf("%d",&n);
    List l;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        l.pushBack(num);
    }
    l.printar();

    return 0;
}
