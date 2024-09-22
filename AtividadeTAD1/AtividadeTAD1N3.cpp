#include<stdio.h>
#include<string.h>


struct Funcionario{
    char nome[100], cargo[100];
    double salB,desc,benef,salL;

    double lerDados(){
        printf("Digite o nome do funcionario:\n");
        scanf("%[^\n]%*c",nome);
        printf("Digite o cargo do funcionario:\n");
        scanf("%[^\n]%*c", cargo);
        printf("Digite o salário base do funcionario:\n");
        scanf("%lf", &salB);
        printf("Digite os descontos do funcionario:\n");
        scanf("%lf", &desc);
        printf("Digite os beneficios do funcionario:\n");
        scanf("%lf", &benef);
        salL=salB+benef-desc;

        return salL;

    }
    void mostrar(int a){
        printf("Funcionario %d:\n", a+1);
        printf("Nome: %s\n", nome);
        printf("Cargo: %s\n", cargo);
        printf("Salario base: %.2lf\n", salB);
        printf("Descontos: %.2lf\n", desc);
        printf("Beneficios: %.2lf\n", benef);
        printf("Salario liquido: %.2lf\n\n", salL);

    }

};

struct Loja{
    double salTotal=0;
    Funcionario f[10];
    char maiorN[100];
    double maior=0;
    double tmp,media;
    int cont=0;

    void lerCada(){
        tmp=f[cont].lerDados();
        salTotal+=tmp;
        if(maior<tmp){
            maior=tmp;
            strcpy(maiorN, f[cont].nome);
        }
        cont++;
    }
    void printCada(){
        for(int i=0; i<cont;i++){
            f[i].mostrar(i);
        }
    }
    void tirarMedia(){
        media=salTotal/cont;
        printf("A media salarial é: %.2lf\n\n", media);
    }
    void mostrarMaior(){
        printf("O funcionario com maior salario e %s\n\n", maiorN);
    }

};

int main(){
    Loja l;

    while(1){
        int n;
        printf("Digite a açao que deseja realizar\n");
        printf("1-Cadastrar funcionario\n");
        printf("2-Listar dados dos funcionarios\n");
        printf("3-Mostrar media salarial\n");
        printf("4-Mostrar funcionario com maior salario\n");
        scanf("%d", &n);
        if(n==1){
            l.lerCada();

        }else if(n==2){
            l.printCada();
        }else if(n==3){
            l.tirarMedia();
        }else if(n==4){
            l.mostrarMaior();
        }else{
            printf("Escolha uma opção valida\n");
        }
    }
return 0;
}
