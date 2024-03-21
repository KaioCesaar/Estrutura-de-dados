#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include "alunos.h"

int ultimaPosLivre = 0;

struct Aluno
{
    int idade;
    char nome[50];
    float nota;
};


struct Aluno *criaLista(int numAlunos){
    //alocando dinamicamente
    struct Aluno *alunos = (struct Aluno*) malloc(numAlunos*sizeof(Aluno));
    return alunos;
}



void adicionarAluno(struct Aluno **lista, struct Aluno aluno)
{
    strcpy(lista[ultimaPosLivre]->nome, aluno.nome);
    lista[ultimaPosLivre]->idade = aluno.idade;
    lista[ultimaPosLivre]->nota = aluno.nota;

    ultimaPosLivre++;
}

void listarAluno(struct Aluno *lista){
    for(int i = 0; i<ultimaPosLivre;i++){
        printf("Aluno: %d\n", i + 1);
        printf("Nome: %s\n", lista[i].nome );
        printf("Idade: %d\n", lista[i].idade);
        printf("Float: %f\n", lista[i].nota);
    }
}
int main(){
    struct Aluno *alunos;
    alunos = criaLista(10);

    struct Aluno aluno1,aluno2,aluno3;

    strcpy(aluno1.nome, "jao");
    aluno1.idade = 12;
    aluno1.nota = 12.5;

    strcpy(aluno2.nome, "berl");
    aluno2.idade = 12;
    aluno2.nota = 12.5;

    strcpy(aluno3.nome, "bedas");
    aluno3.idade = 12;
    aluno3.nota = 12.5;
    
    adicionarAluno(&alunos,aluno1);
    adicionarAluno(&alunos,aluno2);
    adicionarAluno(&alunos,aluno3);

    //adicionarAluno(alunos,);
    listarAluno(alunos);
    return 0;
}