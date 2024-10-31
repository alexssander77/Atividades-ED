#include<stdio.h>

struct Node {

    int value;
    Node* next;

    Node() { // O(1)
        value = 0;
        next = NULL;
    }

    Node(int _value) { // O(1)
        value = _value;
        next = NULL;
    }

};

struct List {

    Node* first;
    Node* last;
    int c;
    Node* med;

    List() { // O(1)
        first = NULL;
        last = NULL;
        c = 0;
        med=NULL;
    }


    bool empty() { // O(1)
        return first == NULL;
    }

    void pushFront(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        n->next = first;
        first = n;
    }

    void pushBack(int value) { // O(1)
        Node *n = new Node(value);
        c++;
        if (empty()) {
            first = n;
            last = n;
            med=n;
            return;
        }
        last->next = n;
        last = n;
        if(c%2!=0){
            med=med->next;
        }
    }

    void print() { // complexidade de tempo O(n), complexidade de espaço O(1)
        Node* aux = first;
        while (aux != NULL) {
            printf("%d ", aux->value);
            aux = aux->next;
        }
    }

    /*
    int size() { // O(n)
        int c = 0;
        Node* aux = first;
        while (aux != NULL) {
            c++;
            aux = aux->next;
        }
        return c;
    }
    */

    int size() { // O(1)
        return c;
    }

    void popFront() { // O(1)
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = first;
        first = first->next;
        delete(toDel);
        c--;
    }

    void popBack() { // O(n)
        if (empty()) return;
        if (c == 1) {
            delete(first);
            first = NULL;
            last = NULL;
            c = 0;
            return;
        }
        Node* toDel = last;
        Node* aux = first;
        while (aux->next != last) {
            aux = aux->next;
        }
        last = aux;
        last->next = NULL;
        delete(toDel);
        c--;
    }

    void insert(int value, int pos) { //O(n)
        if (pos <= 0) {
            pushFront(value);
            return;
        }
        if (pos >= c) {
            pushBack(value);
            return;
        }
        Node* aux = first;
        for (int i = 0; i < pos; i++, aux = aux->next);
        Node* n = new Node(value);
        n->next = aux->next;
        aux->next = n;
        c++;
    }

    void remove(int value) { // O(n)
        if (empty()) return;

        Node *aux = first;
        Node *prev = NULL;
        for (int i = 0; i < c; i++) {
            if (aux->value == value) {
                if (prev == NULL) {
                    popFront();
                } else {
                    prev->next = aux->next;
                    delete(aux);
                    c--;
                    aux = prev;
                }
            }
            prev = aux;
            aux = aux->next;
        }
    }

    void removeByPos(int pos) { // O(n)
        if (pos <= 0) {
            popFront();
            return;
        }
        if (pos >= c) {
            popBack();
            return;
        }
        Node* aux = first;
        for (int i = 0; i < pos - 1; i++, aux = aux->next);
        Node* toDel = aux->next;
        aux->next = toDel->next;
        delete(toDel);
        c--;
    }

    void removerNBack(int n){
        if(n>=c){
            int a=c;
            for(int i=0;i<a;i++){
                popBack();
            }

        }else{
            for(int i=0;i<n;i++){
                popBack();
            }
        }
    }
    void remover2(){
        if(c<=1)return;
        Node* aux=first->next;
        first->next=aux->next;
        delete(aux);
        c--;
    }
    void insertCFim(){
        pushBack(c);
    }
    void insertAteN(int n){
        for(int i=1;i<=n;i++){
            pushBack(i);
        }
    }
    void insertPen(int num){
        if(c<=1)return;
        Node* n=new Node(num);
        Node* aux=first;
        while(aux->next!=last){
            aux=aux->next;
        }
        aux->next=n;
        n->next=last;
        c++;

    }
    void printarM(){
        print();
        if(c%2==0){
            double val=(med->value+med->next->value)/2.0;
            printf("%.2lf\n",val);
            return;
        }else{
            printf("%.2lf\n",double(med->value));

        }
    }

};

int main() {

    List l;

    int n;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        l.pushBack(num);
        l.printarM();
    }

    return 0;
}
