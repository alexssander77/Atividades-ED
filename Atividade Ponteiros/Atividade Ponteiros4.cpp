#include<stdio.h>
#include<math.h>
#define pi 3.14


void calcular(float r, float *a, float *v){
    *a=4*pi*pow(r,2);
    *v=(4.0/3.0)*(pi*pow(r,3));

}

int main(){
    float a, r, v;

    scanf("%f", &r);
    calcular(r,&a,&v);
    printf("Area=%.2f Volume=%.2f", a, v);

    return 0;
}
