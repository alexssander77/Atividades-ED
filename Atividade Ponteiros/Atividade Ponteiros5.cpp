#include<stdio.h>


void descobrir(int *v,int t ,int *mi,int *ma){
    for(int i=0;i<t;i++){
        if(v[i]<*mi){
            *mi=v[i];
        }
        if(v[i]>*ma){
            *ma=v[i];
        }
    }
}


int main(){
    int  mi=10000000000, ma=-100000000000, t;

    scanf("%d", &t);
    int v[t];
    for(int i=0;i<t;i++){
        scanf("%d", &v[i]);

    }
    descobrir(v, t,&mi,&ma);
    printf("Min:%d Max:%d\n", mi,ma);

    return 0;
}
