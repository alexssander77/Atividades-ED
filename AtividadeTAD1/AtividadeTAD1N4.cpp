#include<stdio.h>
#include<string.h>


struct Livro{
    char titulo[100], autor[100];
    int np;

    int lerLivro(){
        printf("Digite o titulo do livro:\n");

        scanf("%[^\n]%*c",titulo);

        printf("Digite o nome do autor do livro:\n");

        scanf("%[^\n]%*c",autor);

        printf("Digite o numero de paginas:\n");

        scanf("%d",&np);

    return np;
    }
    void imprimirLivro(int a){
        printf("Livro %d:\n",a);
        printf("Titulo do livro: %s\n", titulo);
        printf("Autor do livro: %s\n", autor);
        printf("Numero de paginas: %d\n\n", np);

    }


};

struct Biblioteca{
    Livro l[10];
    int cont=0;
    int maior=0;
    int liv;

    void lerB(){
        int tmp;
        tmp=l[cont].lerLivro();
        if(maior<tmp){
            maior=tmp;
            liv=cont;
        }
        cont++;
    }

    void imprimirB(){
        for(int i=0;i<cont;i++){
            l[i].imprimirLivro(i+1);

        }

    }

    void mostrarMaior(){
        printf("o livro com mais paginas e:\n");
        l[liv].imprimirLivro(liv+1);
    }

};

int main(){
    Biblioteca b;
    while(1){
        int n;
        printf("Escolha a acao a ser realizada:\n1-Ler novo livro\n2-Listar livros\n3-Mostrar livro com mais paginas\n4-fechar programa\n");
        scanf("%d%*c", &n);
        if(n==1){
            b.lerB();
        }else if(n==2){
            b.imprimirB();
        }else if(n==3){
            b.mostrarMaior();
        }else if(n==4){
            break;
        }else{
            printf("Escolha uma opcao valida\n");
        }


    }

return 0;
}
