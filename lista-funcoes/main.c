#include <stdio.h>
#include <string.h>

int verificaPositivo(int num){
    if(num > 0){
        return 1;
    }else if(num < 0){
        return -1;
    }else{
        return 0;
    }
}

float consumoAuto(float km,float l){
    float consumo = km/l;
    if(consumo < 8.0f){
        printf("Venda o carro!\n");
    }else if(consumo >= 8 && consumo <= 12){
        printf("Economico\n");
    }else if(consumo > 12){
        printf("Super Economico\n");
    }
    return consumo;
}


double media(double *vetor,int tamanho){
    double soma = 0;
    for(int i=0;i<tamanho;i++){
        soma += vetor[i];
    }
    return soma/tamanho;
}

void tamanho(char *str, int *strsize){
    *strsize = strlen(str);
}

struct Ponto{
    int x;
    int y;
};

int dentroRet (struct Ponto* inferiorEsquerdo, struct Ponto* superiorDireito,
               struct Ponto* p){
    if((p->x >= inferiorEsquerdo->x) && (p->x <= superiorDireito->x) &&
       (p->y >= inferiorEsquerdo->y) && (p->y <= superiorDireito->y)){
        return 1;
    }

    return 0;
}
int main() {
    printf("%d %d %d\n",verificaPositivo(3),
           verificaPositivo(0),
           verificaPositivo(-1));

    consumoAuto(400.0f,65.0f);

    double vetor[] = {2.5,5.0,7.5};
    printf("Media:%lf\n",media(vetor,3));

    char texto[] = "texto bem legal!";
    int t;
    tamanho(texto,&t);
    printf("%s tem %d tamanho\n",texto,t);

    struct Ponto inferiorEsquerdo,superiorDireito,p;
    inferiorEsquerdo.x = 10;
    inferiorEsquerdo.y = 10;
    superiorDireito.x = 20;
    superiorDireito.y = 20;
    p.x = 15;
    p.y = 25;
    printf("O rect esta:%d",dentroRet(&inferiorEsquerdo,&superiorDireito,&p));
    return 0;
}
