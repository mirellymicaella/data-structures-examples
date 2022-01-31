#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

struct arv {
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};

Arv* abb_cria (){
    return NULL;
}

void abb_imprime (Arv* a){
    
    if(a != NULL){
        abb_imprime(a->esq);
        ImprimeAluno(a->aluno);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca (Arv* a, int chave){
    if (a == NULL)
        return NULL;
    else if (RetornaMatricula(a->aluno) > chave)
        return abb_busca (a->esq, chave);
    else if (RetornaMatricula(a->aluno) < chave)
        return abb_busca (a->dir, chave);
    else
        return a;
}

Arv* abb_insere (Arv* a, Aluno* aluno){
    if (a == NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->aluno = aluno;
        a->esq = a->dir = NULL;
    }

    else if (RetornaMatricula(aluno) < RetornaMatricula(a->aluno))
        a->esq = abb_insere(a->esq, aluno);
    else
        a->dir = abb_insere(a->dir, aluno);
    return a;
}

Arv* abb_retira (Arv* a, int chave){
    if(a==NULL)
        return NULL;
    else if (RetornaMatricula(a->aluno) > chave)
        a->esq = abb_retira(a->esq, chave);
    else if (RetornaMatricula(a->aluno) < chave)
        a->dir = abb_retira(a->dir, chave);
    else { 
        //(1)no eh folha
        if (a->esq == NULL && a->dir == NULL){
            free(a);
            a = NULL;
        }

        //(2a)no tem filho so a direita
        else if (a->esq == NULL){
            Arv* t = a;
            a = a->dir;
            free(t);
        }
       
        //(2b)no tem filho so a esquerda
        else if (a->dir == NULL){
            Arv* t = a;
            a = a->esq;
            free(t);
        }

        //(3)no tem filhos dos dois lados
        else{
            //acha o antecessor do no
            Arv* f = a->esq;
            while(f->dir != NULL){
                f = f->dir;
            }
            //troca os nos
            Aluno* t = a->aluno;
            a->aluno = f->aluno;
            f->aluno = t;

            //chama novamente a funcao
            a->esq = abb_retira(a->esq, chave);
        }
    }
    return a;
}

Arv* abb_libera (Arv* a){
    if (a == NULL)
        return NULL;
    abb_libera(a->esq); 
    abb_libera(a->dir); 
    free(a); 
}