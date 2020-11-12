#include <stdio.h>


void exercicio1(){
    int var1,var2;
    printf("Digite as duas variaveis:");
    scanf("%d",&var1);
    scanf("%d",&var2);
    printf("end:%ud %ud\n",&var1,&var2);
    if((&var1) > (&var2)){
        printf("O conteudo eh:%d\n",var1);
    }else if((&var1) < (&var2)){
        printf("O conteudo eh:%d\n",var2);
    }
}

void primeiroMaior(int* var1,int* var2){
    if( *var2 > *var1 ){
        int aux = *var1;
        *var1 = *var2;
        *var2 = aux;
    }
}
void exercicio2(){
    int var1,var2;
    printf("Digite as duas variaveis:");
    scanf("%d",&var1);
    scanf("%d",&var2);
    primeiroMaior(&var1,&var2);
    printf("%d %d",var1,var2);
}

void exercicio3(){
    int array[5];
    for (int i = 0; i < 5; ++i) {
        printf("Entre com a variavel:");
        /*array[1] = 5;
        *(array+1) = 5;*/
        scanf("%d",(array+i));
        printf("O dobro eh:%d\n",(*(array+i))*2);
    }
}


void contaMaiorNoArray(int *array,int size){
    int maior = *array;
    int contador = 1;
    for (int i = 1; i < size; ++i) {
        if(maior < *(array+i)){
            maior = *(array+i);
            contador = 1;
        }else if(maior == *(array+i)){
            contador++;
        }
    }
    printf("Maior elemento eh:%d\n",maior);
    printf("Ele repetiu:%d\n",contador);

}
void exercicio4(){
    int array[] = {15, 2, 15, 3, 71, 15, 8, 6, 15};
    contaMaiorNoArray(array,9);
}
int main() {
    //exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    int x = 10;
    int *px = &x;
    printf("Endereco *x:%ud valor:%d\n",px,*px);
    int **ppx = &px;
    printf("Endereco **x:%ud aponta:%ud e valor:%d\n",ppx,*ppx,**ppx);
    int ***pppx = &ppx;
    printf("Endereco ***x:%ud aponta:%ud q aponta:%ud e valor:%d\n",pppx,*pppx,**pppx,***pppx);
    return 0;
}
