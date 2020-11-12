#include <stdio.h>

#define true 1
#define false 0

void exercicio1(){
    struct Aluno{
        int matricula;
        char nome[128];
        float provas[3];
        float media;
        int aprovado;
    };
    struct Aluno alunos[5];
    int maiorAlunoProva1 = 0,maiorAlunoMedia = 0,menorAlunoMedia = 0;
    for (int i = 0; i < 5; ++i) {
        printf("[%d]entre com a matricula:",i);
        scanf("%d",&alunos[i].matricula);
        printf("[%d]entre com o nome:",i);
        setbuf(stdin,NULL);
        fgets(alunos[i].nome,128*sizeof(char),stdin);

        alunos[i].media = 0.0f;
        for (int j = 0; j < 3; ++j) {
            printf("[%d]entre com a prova %d:",i,j);
            scanf("%f",&alunos[i].provas[j]);
            alunos[i].media += alunos[i].provas[j];
        }
        alunos[i].media /= 3.0f;
        alunos[i].aprovado = (alunos[i].media >= 7.0f)? true : false;
        /* o mesmo que a linha acima
        if(alunos[i].media >= 7.0f){
            alunos[i].aprovado = true;
        }else{
            alunos[i].aprovado = false;
        }
         */
        if(alunos[i].provas[0] > alunos[maiorAlunoProva1].provas[0]){
            maiorAlunoProva1 = i;
        }
        if(alunos[i].media > alunos[maiorAlunoMedia].media){
            maiorAlunoMedia = i;
        }
        if(alunos[i].media < alunos[menorAlunoMedia].media){
            menorAlunoMedia = i;
        }
    }
    printf("A maior nota da primeira prova (%f) foi do aluno:%s",
           alunos[maiorAlunoProva1].provas[0],
           alunos[maiorAlunoProva1].nome);
    printf("A maior nota media (%f) foi do aluno:%s",
           alunos[maiorAlunoMedia].media,
           alunos[maiorAlunoMedia].nome);
    printf("A menor nota media (%f) foi do aluno:%s",
           alunos[menorAlunoMedia].media,
           alunos[menorAlunoMedia].nome);
    for (int i = 0; i < 5; ++i) {
        printf("Aluno:%s %s\n",alunos[i].nome,
               ((alunos[i].aprovado == true)? "Aprovado":"Reprovado"));

    }
}


void exercicio2(){
    struct Funcionario{
        char nome[128];
        int idade;
        char sexo;
        char cpf[20];
        char dataNascimento[16];
        int codSetor;
        char cargo[30];
        float salario;
    };
    typedef struct Funcionario Funcionario;

    Funcionario funcionario;

    printf("Entre com o nome:");
    scanf("%s",funcionario.nome);
    printf("Entre com a idade:");
    scanf("%d",&funcionario.idade);
    printf("Entre com o sexo:");
    scanf(" %c",&funcionario.sexo);
    printf("Entre com o cpf:");

    scanf("%s",&funcionario.cpf);
    printf("Entre com a data de nascimento:");
    scanf("%s",&funcionario.dataNascimento);

    printf("Entre com o codigo do setor:");
    scanf("%d",&funcionario.codSetor);
    printf("Entre com o cargo:");
    scanf("%s",&funcionario.cargo);

    printf("Entre com o salario:");
    scanf("%f",&funcionario.salario);

    printf("Nome:%s\n",funcionario.nome);
    printf("Idade:%d\n",funcionario.idade);
    printf("Sexo:%c\n",funcionario.sexo);
    printf("CPF:%s\n",funcionario.cpf);
    printf("Data de nascimento:%s\n",funcionario.dataNascimento);
    printf("Codigo do setor:%d\n",funcionario.codSetor);
    printf("Cargo:%s\n",funcionario.cargo);
    printf("Salario:%.02f\n",funcionario.salario);
}


void exercicio3(){
    struct Data{
        int dia;
        int mes;
        int ano;
    };
    struct Compromissos{
        char descritivo[60];
        struct Data data;
    };
    struct Compromissos meusCompromissos[5];
    for (int i = 0; i < 5; ++i) {
        printf("Compromisso %d\n",i+1);
        printf("entre com o descritivo:\n");
        scanf("%s",&meusCompromissos[i].descritivo);
        printf("entre com o a data no formato dia mes ano:\n");
        scanf("%d %d %d",&meusCompromissos[i].data.dia
                ,&meusCompromissos[i].data.mes
                ,&meusCompromissos[i].data.ano);
    }
    int m,a;
    do{
        printf("Entre com o mes e ano do compromisso no formato mes ano:");
        scanf("%d %d",&m,&a);
        for (int i = 0; i < 5; ++i) {
            if(meusCompromissos[i].data.mes == m &&
               meusCompromissos[i].data.ano == a){
                printf("%s\n",meusCompromissos[i].descritivo);
            }
        }
    }while (m != 0);

}
void exercicio4(){
    struct Data{
        int dia;
        int mes;
        int ano;
    };
    struct Data data1 = {30,01,2022};
    struct Data data2 = {20,02,2020};
    int totalDeDias1 = 365*data1.ano + 30*data1.mes + data1.dia;
    int totalDeDias2 = 365*data2.ano + 30*data2.mes + data2.dia;
    printf("Diferenca entre datas:%d\n",totalDeDias1-totalDeDias2);
    //segunda forma de resolver
    int dif = 0;
    if(data1.dia < data2.dia){
        data1.mes--;
        data1.dia+=30;
    }
    if(data1.mes < data2.mes){
        data1.ano--;
        data1.mes += 12;
    }
    dif = data1.dia - data2.dia + 30*(data1.mes - data2.mes)+365*(data1.ano-data2.ano);
    printf("Diferenca entre datas:%d\n",totalDeDias1-totalDeDias2);
}
int main() {
    exercicio1();
    //exercicio2();
    //exercicio3();
    //exercicio4();
    return 0;
}
