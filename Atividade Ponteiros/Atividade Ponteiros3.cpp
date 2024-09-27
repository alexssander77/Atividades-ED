#include<stdio.h>



float descobrir(float n,int *i){
    float a;
    *i=(int)n;
    a=n-*i;




    return a;
}


int main(){

    float n, f;
    int i;

    scanf("%f", &n);
    f=descobrir(n, &i);
    printf("inteiro:%d\nfracionaria:%.0f\n", i, f*100);

  return 0;
}
