#include <stdio.h>
#include <stdlib.h>

void exercicio1(){
    int A;
    int *B = &A;
    int **C = &B;
    int ***D = &C;
    printf("Entre com o valor de A:");
    scanf("%d",&A);
    printf("O Dobro:%d\n",(*B * 2));
    printf("O triplo:%d\n",(**C * 3));
    printf("O Quadruplo:%d\n",(***D * 4));
}

void frac(double num, int* inteiro, double* frac){
    *inteiro = (int)num;
    *frac = num - *inteiro;
}
void exercicio2(){
    double num = 35.565;
    int inteiro;
    double fracao;
    frac(num,&inteiro,&fracao);
    printf("num= %lf, inteiro=%d, frac=%lf",num,inteiro,fracao);
}

void exercicio3(){
    int tamanho,impares = 0,pares = 0;
    int *vetor;
    printf("entre com o tamanho do vetor:");
    scanf("%d",&tamanho);
    vetor = (int *)malloc(sizeof(int)*tamanho);
    //vetor = (int *)calloc(tamanho,sizeof(int ));
    for(int i=0;i<tamanho;i++){
        printf("Entre com o valor da pos %d:",i);
        scanf("%d",&vetor[i]);
        if(vetor[i]%2 == 0){
            pares++;
        } else{
            impares++;
        }
    }
    printf("O vetor tem %d pares e %d impares",pares,impares);
    free(vetor);
}

void entradaDosNumerosDaLoteria(int *numero){
    for (int i = 0; i < 6; ++i) {
        printf("Entre com o proximo numero:");
        scanf("%d",&numero[i]);
    }
}
int numerosIguais(int *v1,int *v2,int tamanho){
    int iguais = 0;
    for (int i = 0; i < tamanho; ++i) {
        int num1 = v1[i];
        for (int j = 0; j < tamanho; ++j) {
            if(num1 == v2[j]){
                iguais++;
                break;
            }
        }
    }
    return iguais;
}
void guardaNumerosIguais(int *v1,int *v2,int *v3,int tamanho){
    int iguais = 0;
    for (int i = 0; i < tamanho; ++i) {
        int num1 = v1[i];
        for (int j = 0; j < tamanho; ++j) {
            if(num1 == v2[j]){
                v3[iguais] = num1;
                iguais++;
                break;
            }
        }
    }
}
void imprimeVetor(int *v,int tamanho){
    for (int i = 0; i < tamanho; ++i) {
        printf("%d,",v[i]);
    }
}
int guardaNumerosIguaisRealoc(int *v1,int *v2,int **v3,int tamanho){
    int iguais = 0;
    int *memoria = NULL;
    for (int i = 0; i < tamanho; ++i) {
        int num1 = v1[i];
        for (int j = 0; j < tamanho; ++j) {
            if(num1 == v2[j]){
                iguais++;
                printf("Iguais[%d]:%d\n",num1,iguais);
                memoria = (int *)realloc(memoria,iguais*sizeof(int));
                memoria[iguais-1] = num1;
                break;
            }
        }
    }
    *v3 = (int *)memoria;
    return iguais;
}

void exercicio4(){
    int loteria[6],bilhete[6];
    int *corretos = NULL;
    printf("Entre com os numeros da loteria\n");
    entradaDosNumerosDaLoteria(loteria);
    printf("Entre com os numeros do seu bilhete\n");
    entradaDosNumerosDaLoteria(bilhete);
    /*int tamanho = numerosIguais(bilhete,loteria,6);
    corretos = (int *)malloc(tamanho*sizeof(int ));
    guardaNumerosIguais(bilhete,loteria,corretos,6);*/
    int tamanho = guardaNumerosIguaisRealoc(bilhete,loteria,&corretos,6);
    printf("tamanho:%d\n",tamanho);
    imprimeVetor(corretos,tamanho);
    free(corretos);
}

void exercicio5(){
    int *vetor = NULL;
    int tamanho = 0,num;
    while (1){
        printf("Entre com o prox num:");
        scanf("%d",&num);
        if(num < 0){
            break;
        }
        tamanho++;
        vetor = (int *)realloc(vetor,tamanho*sizeof(int));
        vetor[tamanho-1]=num;
    }
    imprimeVetor(vetor,tamanho);
    free(vetor);
}
int main() {
    exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    //exercicio5();
    return 0;
}
