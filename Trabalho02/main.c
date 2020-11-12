#include <stdio.h>
#include <string.h>

int j;

int main(){
    struct Pessoas{
        char nome[20];
        int dependentes;
        float salario;
        float pensaoAlimenticia;
        float rendimento;
        float imposto;
    };
    struct Idade{
        int dia;
        int mes;
        int ano;
        int idade;
    };


    struct Pessoas pessoas[5];
    struct Idade idades[5];

    printf("\n------ CALCULO DE IRPF ------\n");

    for (int i = 0; i < 5; ++i) {
        printf("\n[%d] Digite seu nome: ", i);
        scanf("%s", &pessoas[i].nome[j]);

        printf("[%d] Digite o número de dependentes: ", i);
        scanf("%d", &pessoas[i].dependentes);

        printf("[%d] Digite o salário: ", i);
        scanf("%f", &pessoas[i].salario);

        printf("[%d] Digite a pensão alimentícia: ", i);
        scanf("%f", &pessoas[i].pensaoAlimenticia);

        struct Idade idades[5];
        printf("[%d] Digite o dia nascimento: ", i);
        scanf("%d", &idades[i].dia);
        printf("[%d] Digite o mes de nascimento: ", i);
        scanf("%d", &idades[i].mes);
        printf("[%d] Digite o ano nascimento: ", i);
        scanf("%d", &idades[i].ano);

        //calculo da idade
        idades[i].idade = 2020 - idades[i].ano;

    }


    printf("\n------ RESULTADO DOS CÁLCULOS: ------\n");
    for(int i = 0; i < 5; ++i) {
        float deducao = 189.59 * pessoas[i].dependentes;

        //calculo imposto mensal e do acordo com o salario
        if (pessoas[i].salario <= 1903.98f){
            pessoas[i].rendimento = pessoas[i].salario + pessoas[i].pensaoAlimenticia - deducao;
        }else if (pessoas[i].salario <= 2826.65f){
            pessoas[i].imposto = (7.5f/100) * pessoas[i].salario;
            pessoas[i].rendimento = pessoas[i].salario - pessoas[i].imposto - deducao + pessoas[i].pensaoAlimenticia;
        }else if (pessoas[i].salario <= 3751.05f){
            pessoas[i].imposto = 15.0f/100 * pessoas[i].salario;
            pessoas[i].rendimento = pessoas[i].salario - pessoas[i].imposto - deducao + pessoas[i].pensaoAlimenticia;
        }else if (pessoas[i].salario <= 4664.68f){
            pessoas[i].imposto = 22.5f/100 * pessoas[i].salario;
            pessoas[i].rendimento = pessoas[i].salario - pessoas[i].imposto - deducao + pessoas[i].pensaoAlimenticia;
        }else if (pessoas[i].salario > 4664.68f){
            pessoas[i].imposto = 27.5f/100 * pessoas[i].salario;
            pessoas[i].rendimento = pessoas[i].salario - pessoas[i].imposto - deducao + pessoas[i].pensaoAlimenticia;
        }


        for(int a = 0; a < strlen(pessoas[i].nome); a++){
            for(int j = 0; j < strlen(pessoas[i].nome); j++) {
                if (pessoas[i].nome[j] > 96 && pessoas[i].nome[j] < 123) {
                    pessoas[i].nome[j] = pessoas[i].nome[j] - 32;
                }
            }
        }

        printf("\nNOME: %s", pessoas[i].nome);

        printf("\nIDADE: %d", idades[i].idade);

        printf("\nIMPOSTO MENSAL: R$%.2f", pessoas[i].imposto);

        printf("\nRENDIMENTO MENSAL: R$%.2f", pessoas[i].rendimento);

        printf("\n----------------------------");
    }
    return 0;
}
