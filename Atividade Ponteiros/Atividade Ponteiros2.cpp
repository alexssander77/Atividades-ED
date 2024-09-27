#include <stdio.h>


void mostrar(float *v){
    printf("%d ", v);

}


int main(){
 float v[10];

 for(int i=0; i<10; i++){
    scanf("%lf", &v[i]);
    mostrar(&v[i]);
 }

printf("\n");



return 0;
}
