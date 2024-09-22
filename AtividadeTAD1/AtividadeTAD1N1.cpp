#include <stdio.h>

struct Data {
    int dia, mes, ano;
    int diaA=21, mesA=9, anoA=2024;
    int age;

    int lerData() {
        printf("Digite a Data de nascimento do cliente no formato dd/mm/aaaa\n");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        calcularIdade();
        return age;
    }

    void calcularIdade() {
        age = anoA - ano;
        if (mesA < mes || (mesA == mes && diaA < dia)) {
            age--;
        }
    }
};

struct Cliente {
    char nome[100], sexo;
    int idade;
    Data dataNasc;

    void lerDados() {
        printf("Digite o nome do cliente:\n");
        scanf("%s%*c", nome);
        printf("Digite o sexo do cliente:\n");
        scanf("%c%*c", &sexo);
        idade = dataNasc.lerData();
    }


    void mostrarDados(int a) {
        printf("Cliente %d:\nNome: %s\nSexo: %c\nData de Nascimento: %02d/%02d/%d\nIdade: %d\n\n",a, nome, sexo, dataNasc.dia, dataNasc.mes, dataNasc.ano, idade);
    }
};

int main() {
    Cliente c[50];
    int cont = 0;

    while (777) {
        int n;
        printf("Escolha a ação a realizar:\n1-Cadastrar cliente\n2-Listar clientes\n3-Fechar programa\n\n");
        scanf("%d", &n);

        if (n == 1) {
            c[cont].lerDados();
            cont++;
        } else if (n == 2) {
            for (int i = 0; i < cont; i++) {
                c[i].mostrarDados(i + 1);
            }
        } else if (n == 3) {
            break;
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
