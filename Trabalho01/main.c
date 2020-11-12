#include <stdio.h>
// variaveis globais
int op, op2, trabalhos[4], nota, pjbl[4], notapjbl;
int mediaRA1, mediaRA2, mediaRA3, mediaRA4, mediaFINAL;

// op 1 menu secundário para enviar notas
void opcao1() {
    printf("----------------------------\n");
    printf("Opção selecionada: Enviar nota dos Trabalhos\n");
    printf("----------------------------\n");
    for (nota = 0; nota <= 3; nota++) {
        printf("Digite a nota do trabalho %d \n", nota);
        scanf("%d", &trabalhos[nota]);
    }
    for (notapjbl = 0; notapjbl <= 3; notapjbl++) {
        printf("Digite a nota do Pjbl %d \n", notapjbl);
        scanf("%d", &pjbl[notapjbl]);
    }

// substituição de notas
    printf("Deseja Substituir alguma nota já enviada? \n"
           "Digite 1 para substituir a nota dos Trabalhos\n"
           "Digite 2 para substituir a nota do PJBL \nDigite 0 para retornar ao Menu Principal: ");
    scanf("%d", &op2);
    if (op2 == 1) {
        for (nota = 0; nota <= 3; nota++) {
            printf("Digite a nota do trabalho %d \n", nota);
            scanf("%d", &trabalhos[nota]);
        }
        printf("Digite 0 para retornar ao Menu Principal: ");
        scanf("%d", &op);
    } else if(op2 == 2) {
        for (notapjbl = 0; notapjbl <= 3; notapjbl++) {
            printf("Digite a nota do Pjbl %d \n", notapjbl);
            scanf("%d", &pjbl[notapjbl]);
        }
        printf("Digite 0 para retornar ao Menu Principal: ");
        scanf("%d", &op);
    } else if(op2 == 0) {
        op = 0;
        printf("----------------------------\n");}
}

// op 2 menu secundário para visualizar médias
void opcao2(){
    printf("----------------------------\n");
    printf("Opção selecionada: Visualizar Médias\n");
    printf("----------------------------\n");

// Validação do envio das notas
    while (mediaRA1 == 0 || mediaRA2 == 0 || mediaRA3 == 0 || mediaRA4 == 0) {
        for (nota = 0; nota <= 3; nota++) {
            if (nota == 0)
                printf("Você precisa informar a nota do trabalho %d \n", trabalhos[nota]);
        }
        for (notapjbl = 0; notapjbl <= 3; notapjbl++) {
            if (nota == 0)
                printf("Você precisa informar a nota do trabalho %d \n", trabalhos[nota]);
        }
        break;
    }
    mediaRA1 = trabalhos[0] + pjbl[0];
    mediaRA2 = trabalhos[1] + pjbl[1];
    mediaRA3 = trabalhos[2] + pjbl[2];
    mediaRA4 = trabalhos[3] + pjbl[3];
    int peso1 = 02;
    int peso2 = 03;
    mediaFINAL =
            (mediaRA1*peso1)+(mediaRA2*peso2)+(mediaRA3*peso2)+(mediaRA4+peso1)/(peso1 +
                                                                                 peso2 + peso2 + peso1);
    while (mediaRA1 != 0 || mediaRA2 != 0 || mediaRA3 != 0 || mediaRA4 != 0) {
        printf("Média RA1: %d \n", mediaRA1);
        printf("Média RA2: %d \n", mediaRA2);
        printf("Média RA3: %d \n", mediaRA3);
        printf("Média RA4: %d \n", mediaRA4);
        printf("Média Final: %d \n", mediaFINAL);
        if (mediaFINAL < 10) {
            printf("Situação Final do Aluno: Reprovado!\n");
        } else {
            printf("Situação Final do Aluno: Aprovado!\n");
        }
        break;
    }
    printf("Digite 0 para voltar ao menu principal \n");
    scanf("%d", &op);printf("----------------------------\n");
}

// op 3 sair do sistema e opção para voltar ao menu
void opcao3(){
    printf("Você saiu do Sistema!\n");
    printf("----G 0 0 D B Y E-----\n");
}
void menu(){
    while (op == 0) {
        printf("MENU:\n");
        printf("1)Enviar nota dos Trabalhos\n");
        printf("2)Visualizar Medias\n");
        printf("3)Sair\n");
        printf("Digite o número da opção desejada: ");
        scanf("%d", &op);
        switch (op) {
            return;
            break;
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                op = 0;
                break;
        }
    }
}
int main() {
    printf("----------------------------\n");
    printf("Sistema de Cálculo de Médias.\n");
    printf("----------------------------\n");
    menu();
    return 0;
}

