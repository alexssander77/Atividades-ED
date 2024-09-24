#include <stdio.h>
#include <stdbool.h>

struct Conjunto {
    int numeros[20];
    int tamanho;

    void lerConjunto() {
        printf("Digite quantos numeros tem o conjunto (maximo 20):\n");
        scanf("%d", &tamanho);
        if (tamanho > 20) {
            printf("Número de elementos excede a capacidade máxima. Ajustando para 20.\n");
            tamanho = 20;
        }
        printf("Digite os elementos do conjunto:\n");
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &numeros[i]);
        }
    }

    void mostrarConjunto(int a) {
        if (a > 0) {
            printf("Conjunto %d:\n", a);
        }
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", numeros[i]);
        }
        printf("\n");
    }

    void uniao(const struct Conjunto* outro) {
        int resultado[40];
        int tamanhoResultado = 0;

        for (int i = 0; i < tamanho; i++) {
            resultado[tamanhoResultado++] = numeros[i];
        }

        for (int i = 0; i < outro->tamanho; i++) {
            bool existe = false;
            for (int j = 0; j < tamanhoResultado; j++) {
                if (outro->numeros[i] == resultado[j]) {
                    existe = true;
                    break;
                }
            }
            if (!existe && tamanhoResultado < 40) {
                resultado[tamanhoResultado++] = outro->numeros[i];
            }
        }

        printf("União dos conjuntos:\n");
        for (int i = 0; i < tamanhoResultado; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }

    void intersecao(const struct Conjunto* outro) {
        int resultado[20]; 
        int tamanhoResultado = 0;

        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < outro->tamanho; j++) {
                if (numeros[i] == outro->numeros[j]) {
                    bool existe = false;
                    for (int k = 0; k < tamanhoResultado; k++) {
                        if (resultado[k] == numeros[i]) {
                            existe = true;
                            break;
                        }
                    }
                    if (!existe) {
                        resultado[tamanhoResultado++] = numeros[i];
                    }
                }
            }
        }

        printf("Interseção dos conjuntos:\n");
        for (int i = 0; i < tamanhoResultado; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }
};

int main() {
    int conjs = 0;
    int conjsL = 0;
    struct Conjunto c[100];

    while (1) {
        int n;
        printf("Escolha a acao a ser realizada:\n1-Criar novo conjunto vazio\n2-Ler novo conjunto\n3-Fazer uniao de dois conjuntos\n4-Fazer a interseccao de dois conjuntos\n5-Mostrar um conjunto\n6-Fechar o programa\n");
        scanf("%d", &n);

        if (n == 1) {
            conjs++;
        } else if (n == 2) {
            if (conjs > conjsL) {
                c[conjsL].lerConjunto();
                conjsL++;
            } else {
                printf("Não existem conjuntos vazios, crie um para lê-lo\n");
            }
        } else if (n == 3) {
            int op1, op2;
            if (conjsL >= 2) {
                printf("Escolha os conjuntos para união (1 a %d):\n", conjsL);
                scanf("%d %d", &op1, &op2);
                if (op1 > 0 && op1 <= conjsL && op2 > 0 && op2 <= conjsL) {
                    c[op1 - 1].uniao(&c[op2 - 1]);
                } else {
                    printf("Conjuntos inválidos.\n");
                }
            } else {
                printf("É necessário ter pelo menos dois conjuntos para realizar a união.\n");
            }
        } else if (n == 4) {
            int op1, op2;
            if (conjsL >= 2) {
                printf("Escolha os conjuntos para interseção (1 a %d):\n", conjsL);
                scanf("%d %d", &op1, &op2);
                if (op1 > 0 && op1 <= conjsL && op2 > 0 && op2 <= conjsL) {
                    c[op1 - 1].intersecao(&c[op2 - 1]);
                } else {
                    printf("Conjuntos inválidos.\n");
                }
            } else {
                printf("É necessário ter pelo menos dois conjuntos para realizar a interseção.\n");
            }
        } else if (n == 5) {
            int op;
            if (conjsL > 0) {
                printf("Escolha pelo numero qual conjunto quer exibir (1 a %d):\n", conjsL);
                for (int i = 1; i <= conjsL; i++) {
                    printf("Conjunto %d\n", i);
                }
                scanf("%d", &op);
                if (op <= conjsL && op > 0) {
                    c[op - 1].mostrarConjunto(op);
                } else {
                    printf("Conjunto invalido\n");
                }
            } else {
                printf("Você não leu nenhum conjunto\n");
            }
        } else if (n == 6) {
            break;
        } else {
            printf("Digite uma opção válida\n");
        }
    }

    return 0;
}
