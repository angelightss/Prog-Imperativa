#include <stdio.h>
#include <string.h>

void exercicio1(){
    char palavra[32];
    int numVogais = 0;
    char caracter;
    printf("Entre com a palavra:");

    setbuf(stdin,NULL);
    //gets(palavra);
    fgets(palavra,sizeof(palavra),stdin);
    printf("Entre o caracter:");
    caracter = getc(stdin);

    for(int i=0;i<strlen(palavra);i++){
        if(palavra[i] == 'a' ||
           palavra[i] == 'e' ||
           palavra[i] == 'i' ||
           palavra[i] == 'o' ||
           palavra[i] == 'u'){
            numVogais++;
            palavra[i] = caracter;
        }
    }
    printf("o numero de vogais eh:%d\n",numVogais);
    printf("a nova palavra eh:%s\n",palavra);
}


void exercicio2(){
    char frase[140];
    int espacos = 0;
    setbuf(stdin,NULL);
    printf("Entre com uma frase:");
    fgets(frase,sizeof(frase),stdin);
    for (int i = 0; i < strlen(frase); ++i) {
        if(frase[i] == ' '){
            espacos++;
        }
    }
    printf("A frase tem %d espacos",espacos);
}
void tabelaASCII(){
    for(int i=0;i<256;i++){
        printf("%c ",i);
    }
}

void exercicio3(){
    char frase[140];
    int espacos = 0;
    setbuf(stdin,NULL);
    printf("Entre com uma frase:");
    fgets(frase,sizeof(frase),stdin);
    for (int i = 0; i < strlen(frase); ++i) {
        if(frase[i] >= 65 && frase[i] <= 90){
            frase[i] +=32;
        }
    }
    printf("A frase agora eh %s",frase);
}

void printFrase(char frase[]){
    int i;
    for(i=0;i<strlen(frase);i++){
        if(frase[i] == 'A'){
            printf("*");
        }else{
            printf("%c",frase[i]);
        }
    }
}
void exercicio4(){
    char frase1[64],frase2[64];
    setbuf(stdin,NULL);
    printf("Entre com a primeira frase:");
    fgets(frase1,sizeof(frase1),stdin);
    printf("Entre com a segunda frase:");
    fgets(frase2,sizeof(frase2),stdin);
    printFrase(frase2);
    printFrase(frase1);
}


void cesar(char *str,int pos){
    for(int i=0;i<strlen(str);i++){
        if(str[i] != ' '){
            str[i] += pos;
        }
    }
}
void exercicio5(){
    char frase[128];
    setbuf(stdin,NULL);
    printf("Entre com a frase:");
    fgets(frase,sizeof(frase),stdin);
    cesar(frase,3);
    printf("%s",frase);
}
struct aluno{
    int numero;
    float notas[3];
};
struct endereco{
    char logradouro[64];
    int numero;
};

int main() {
    exercicio1();
    //exercicio2();
    //tabelaASCII();
    //exercicio3();
    //exercicio5();
    return 0;
}
