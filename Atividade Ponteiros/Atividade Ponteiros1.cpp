#include<stdio.h>

void decidir(int *a, int *b){
    if(a>b){
        printf("%d", *a);
    }else{
        printf("%d", *b);
    }

}

int main(){

    int a, b;

    scanf("%d%d",&a,&b);
    decidir(&a, &b);





    return 0;
}
