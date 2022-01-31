#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Arvore.h"

struct arv{
    Aluno* aluno;
    struct arv* esq;
    struct arv* dir;
};

typedef struct arv Arv;

Arv* arv_criavazia(){
    return NULL;
}

Arv* arv_cria(Aluno* aluno, Arv* e, Arv* d){
    Arv* a = (Arv*)malloc(sizeof(Arv));

    a->aluno = aluno;
    a->esq = e;
    a->dir = d;

    return a;
}

Arv* arv_libera(Arv* a){
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv* a){
    return a == NULL;  
}

int arv_pertence(Arv* a, char* nome){
    if(arv_vazia(a))
        return 0;
    else
        return !strcmp(RetornaNome(a->aluno), nome)||
            arv_pertence(a->esq,nome) ||
            arv_pertence(a->dir,nome);
}

void arv_imprime(Arv* a){
    printf(" <");
    if(!arv_vazia(a)){
        printf("%s", RetornaNome(a->aluno));
        arv_imprime(a->esq);
        arv_imprime(a->dir);
    }
    printf("> ");
}

Arv* arv_pai(Arv* a, char* nome){
    if(arv_vazia(a))
        return 0;

    if((!arv_vazia(a->esq) && 
            !strcmp(RetornaNome(a->esq->aluno), nome)) ||
         (!arv_vazia(a->dir) && 
            !strcmp(RetornaNome(a->dir->aluno), nome)) )
        return a;
    
    Arv* aux = arv_pai(a->esq,nome);
    if(aux == NULL)
        aux= arv_pai(a->dir,nome);
    return aux;
}

int folhas(Arv* a){
    if(arv_vazia(a->esq) && arv_vazia(a->dir))
        return 1;
    else if(!arv_vazia(a->esq) && arv_vazia(a->dir))
        return folhas(a->esq);
    else if(arv_vazia(a->esq) && !arv_vazia(a->dir))
        return folhas(a->dir);

    return folhas(a->esq) + folhas(a->dir);  
}

int ocorrencias(Arv* a, char* nome){
    if(arv_vazia(a))
        return 0;
    if(!strcmp(RetornaNome(a->aluno), nome))
        return (1 + 
            ocorrencias(a->dir, nome) +
            ocorrencias(a->esq,nome));

    return (ocorrencias(a->dir, nome) +
            ocorrencias(a->esq,nome));
}

Aluno* info(Arv* a ){
    if(!arv_vazia(a))
        return a->aluno;

    return 0;
}

static int max2 (int a, int b){
    return (a > b) ? a : b;
}

int altura (Arv* a){
    if(arv_vazia(a))
        return -1;
    else
        return 1 + max2 (altura(a->esq), altura(a->dir));
}