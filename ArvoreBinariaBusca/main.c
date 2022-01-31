#include <stdio.h>
#include "abb.h"

int main (){

    Aluno* ana = InicAluno("Ana",700, 7.8);
    Aluno* bia = InicAluno("Bia",200, 8);
    Aluno* cris = InicAluno("Cris",100, 5.5);
    Aluno* dani = InicAluno("Dani",400, 6);
    Aluno* elsa = InicAluno("Elsa",800, 5.9);
    Aluno* fabio = InicAluno("Fabio",900, 6);

    Arv* a = abb_cria();

    a = abb_insere(a, ana);
    a = abb_insere(a, bia);
    a = abb_insere(a, cris);
    a = abb_insere(a, dani);
    a = abb_insere(a, elsa);
    a = abb_insere(a, fabio);


    printf("-------------------\n");
    abb_imprime(a);

    //Retira um aluno em caso comum (1)
    abb_retira(a,800); //elsa

    printf("-------------------\n");
    abb_imprime(a);

    //Retira um aluno em caso (2)
    abb_retira(a, 900); //fabio

    printf("-------------------\n");
    abb_imprime(a);

    //Retira um aluno em caso (3)
    abb_retira(a, 200); //bia

    printf("-------------------\n");
    abb_imprime(a);

    //Insere de volta os alunos retirados
    abb_insere(a, elsa);
    abb_insere(a, bia);
    abb_insere(a,fabio);

    printf("-------------------\n");
    abb_imprime(a);

    abb_libera(a);

    //Libera alunos
    DestroiAluno(ana);
    DestroiAluno(bia);
    DestroiAluno(cris);
    DestroiAluno(dani);
    DestroiAluno(elsa);
    DestroiAluno(fabio);

    return 0;
}