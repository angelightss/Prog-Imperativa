#include <stdio.h>


void exercicio1(){
    FILE *arq = fopen("arq.txt","w");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return;
    }
    char c;
    printf("Digite o conteudo a ser gravado no arquivo(0 para a gravacao):");
    while (1){
        c = getchar();
        if (c == '0'){
            break;
        }
        fputc(c,arq);
    }
    fclose(arq);
    arq = fopen("arq.txt","r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo!");
        return;
    }
    printf("conteudo do arquivo \n");
    while ((c = fgetc(arq))!= EOF){
        printf("%c",c);
    }
    fclose(arq);
}

void exercicio2(){
    char nomeDoArquivo[128],c,charArquivo;
    int contador = 0;
    printf("entre com o nome do arquivo e o caracter a ser procurado:");
    scanf("%s %c",&nomeDoArquivo,&c);
    //printf("digite o char a ser contado:");
    //scanf("%c",&c);
    //printf("%s %c",nomeDoArquivo,c);
    FILE *arq = fopen(nomeDoArquivo,"r");
    while ((charArquivo = fgetc(arq))!= EOF){
        if(charArquivo == c){
            contador++;
        }
    }
    printf("%c aparece %d vezes.",c,contador);
    fclose(arq);
}

void exercicio3(){
    char nome[128],telefone[20];
    char c;
    int contadorNome = 0,contadorTelefone = 0;
    int modo = 0;//0 telefone,1 nome
    FILE *arq = fopen("arq2.txt","w");
    printf("Entre com o telefone:");
    while (1){
        c = getchar();
        if(c == '\n'){
            if(contadorTelefone == 1 && telefone[0] == '0'){
                break;
            }
            if (modo == 0){
                //printf("%s",telefone);
                telefone[contadorTelefone] = '\n';
                fputs(telefone,arq);
                printf("Entre com o nome:");
                contadorNome = 0;
                modo = 1;
            }else{
                nome[contadorNome] = '\n';

                fputs(nome,arq);
                //printf("%s",nome);
                printf("Entre com o telefone:");
                contadorTelefone = 0;
                modo = 0;
            }
        }else if (modo == 0){
            telefone[contadorTelefone++] = c;
        } else{
            nome[contadorNome++] = c;
        }
    }
    fclose(arq);
}

void exercicio4(){
    int vetor[10];
    char binario[256];
    int contadorBinario = 0;
    FILE *arq = fopen("binario.txt","w");
    printf("Entre com os 10 numeros\n");
    for (int i = 0; i < 10; ++i) {
        printf("Entre com o numero %d:",i);
        scanf("%d",&vetor[i]);
        contadorBinario = 0;
        while (vetor[i] > 0){
            binario[contadorBinario++] = (vetor[i] % 2) == 0 ? '0':'1';
            vetor[i] /= 2;
        }
        for (int j = contadorBinario-1; j >= 0; j--) {
            //printf("%c",binario[j]);
            fputc(binario[j],arq);
        }
        fputc('\n',arq);
        //printf("\n");
    }
    fclose(arq);
}
int main() {
    exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    return 0;
}
