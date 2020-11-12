#include <stdio.h>

int mediaFinal(int prova,int trabalhos){
    int media = (prova + trabalhos) / 2;
    return media;
}

void exercicio1(){
    int dadosDisciplica[5][4];
    int maiorNota = -1;
    int indexMatricula = -1;
    printf("===CALCULO DAS MEDIAS===\n");
    for(int i=0;i<5;i++){
        printf("Entre com o numero de matricula do aluno %d:",i);
        scanf("%d",&dadosDisciplica[i][0]);
        printf("Entre com a media das provas do aluno %d:",i);
        scanf("%d",&dadosDisciplica[i][1]);
        printf("Entre com a media dos trabalhos do aluno %d:",i);
        scanf("%d",&dadosDisciplica[i][2]);
        dadosDisciplica[i][3] = mediaFinal(dadosDisciplica[i][1],
                                           dadosDisciplica[i][2]);
        printf("Media final do aluno %d:%d\n",i,dadosDisciplica[i][3]);
        if(maiorNota < dadosDisciplica[i][3]){
            maiorNota = dadosDisciplica[i][3];
            indexMatricula = i;
        }
    }
    printf("A maior nota foi %d do aluno:%d",
           maiorNota,dadosDisciplica[indexMatricula][0]);
}

void exercicio2(){
    double matriz[3][6];
    double somaImpar = 0;
    double media2e4 = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("Entre com o valor[%d][%d]:",i,j);
            scanf("%lf",&matriz[i][j]);
            if((j%2)==1){
                somaImpar += matriz[i][j];
            }
            if(j == 1 || j == 3){
                media2e4 += matriz[i][j];
            }
        }
    }
    media2e4 /= 6.0;
    printf("A soma das colunas impares eh:%lf\n",somaImpar);
    printf("A media das colunas 2 e 4 eh:%lf\n",media2e4);
    printf("Nova matriz\n");
    for(int i=0;i<3;i++){
        matriz[i][5] = matriz[i][0]+matriz[i][1];
        for(int j=0;j<6;j++){
            printf("%lf ",matriz[i][j]);
        }
        printf("\n");
    }
}
int main() {
    //exercicio1();
    exercicio2();
    return 0;
}
