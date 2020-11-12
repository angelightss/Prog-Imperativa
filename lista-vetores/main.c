#include <stdio.h>
/*
 * Faca um programa que possua um vetor denominado A
 * que armazene 6 numeros inteiros.
 * O programa deve executar os seguintes passos:
(a) Atribua os seguintes valores a esse vetor:
 1, 0, 5, -2, -5, 7.
(b) Armazene em uma variavel inteira (simples) a soma
 entre os valores das posicoes A[0], A[1] e A[5] do vetor
 e mostre na tela esta soma.
(c) Modifique o vetor na posicoes 4, atribuindo a esta posicoes
 o valor 100.
 */

void exercicio1(){
    int A[6] = {1,0,5,-2,-5,7};
    for (int i = 0; i < 6; ++i) {
        printf("%d ",A[i]);
    }
    int b = A[0] + A[1] + A[5];
    printf("\nb = %d\n",b);
    A[4] = 100;
    printf("Vetor A:\n");
    for (int i = 0; i < 6; ++i) {
        printf("%d\n",A[i]);
    }
}

/*
 * Faca um programa que leia um vetor de 8 posições e,
 * em seguida, leia também dois valores X e Y quaisquer
 * correspondentes a duas posições no vetor.
 * Ao final seu programa devera escrever a soma dos valores
 * encontrados nas respectivas posições X e Y .
 */

void exercicio2(){
    int vetor[8],X,Y;
    for(int i=0;i<8;i++){
        printf("Digite a posicao %d do vetor:",i);
        scanf("%d",&vetor[i]);
    }
    do {
        printf("Digite a posicao de X entre 0 e 7:");
        scanf("%d", &X);
    }while (X < 0 || X > 7);
    do {
        printf("Digite a posicao de Y entre 0 e 7:");
        scanf("%d", &Y);
    }while (Y < 0 || Y > 7);
    int soma = vetor[X] + vetor[Y];
    printf("A soma eh:%d\n",soma);
    for(int i=0;i<8;i++){
        printf("%d ",vetor[i]);
    }
}

/*
 * 3.	Crie um programa que leia 6 valores inteiros e,
 * em seguida, mostre na tela os valores lidos na ordem inversa.
 */
void exercicio3(){
    int valores[6];
    for(int i=0;i<6;i++){
        printf("Digite o valor [%d]:",i);
        scanf("%d", &valores[i]);
    }
    printf("valores na ordem inversa:");
    for (int i=5;i>=0;i--){
        printf("%d,",valores[i]);
    }
}
/*
 * 4.	Fazer um programa para ler 5 valores e,
 * em seguida, mostrar todos os valores lidos juntamente
 * com o maior, o menor e a mÃ©dia dos valores.
 */
void exercicio4(){
    int valores[5];


    for(int i=0;i<5;i++){
        printf("Digite o valor [%d]:",i);
        scanf("%d", &valores[i]);
    }

    float media=0.0f;
    int  maior = valores[0],menor = valores[0];
    printf("Valores:");
    for(int i=0;i<5;i++){
        media += valores[i];
        printf("%d,",valores[i]);
        if(maior < valores[i]){
            maior = valores[i];
        }
        if(menor > valores[i]){
            menor = valores[i];
        }
    }
    printf("\n");
    media /= 5.0f;

    printf("Media eh:%f\n",media);

    printf("O maior numero eh:%d\n",maior);
    printf("O menor numero eh:%d\n",menor);

}
/*
 * Leia uma matriz de 3x3 elementos inteiros
 * e calcule a soma dos seus elementos

 */
void exemploMatriz(){
    int matriz[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("Digite o valor [%d][%d]:",i,j);
            //scanf("%d", &matriz[i][j]);
        }
    }
    int soma = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            soma += matriz[i][j];
        }
    }
    printf("soma e:%d",soma);

    int matriz2[2][2] = {{0,1},{0,2}};

}
void testeStr(){
    char str[10] = "joao";
    printf("%s",str);
}
int main() {
    testeStr();
    return 0;
}
