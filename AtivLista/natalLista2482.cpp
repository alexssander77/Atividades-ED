#include <stdio.h>
#include <string.h>

struct Node {
    char lingua[100];
    char traducao[100];
    Node* next;

    Node() {
        lingua[0] = '\0';
        traducao[0] = '\0';
        next = NULL;
    }
    Node(const char* lingua1, const char* traducao1) {
        strcpy(lingua, lingua1);
        strcpy(traducao, traducao1);
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

    void pushBack(const char* lingua, const char* traducao) {
        Node* n = new Node(lingua, traducao);
        if (empty()) {
            first = n;
            last = n;
            return;
        }
        last->next = n;
        last = n;
    }

    const char* checar(const char* lig) {
        Node* aux = first;
        while (aux != NULL) {
            if (strcmp(aux->lingua, lig) == 0) {
                return aux->traducao;
            }
            aux = aux->next;
        }
        return "Não encontrado";
    }
};

int main() {
    int N, M;
    List l;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char idioma[100], traducao[100];
        scanf("%s", idioma);
        scanf(" %[^\n]s", traducao);
        l.pushBack(idioma, traducao);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        char nome[100], lingua[100];
        scanf(" %[^\n]s", nome);
        scanf("%s", lingua);
        printf("%s\n", nome);
        printf("%s\n", l.checar(lingua));

        printf("\n");
    }

    return 0;
}
