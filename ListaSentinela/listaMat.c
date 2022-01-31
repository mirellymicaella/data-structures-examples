#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"


struct celula{
    Matriz* mat;
    Celula* prox;
};

struct lista {
    Celula* Prim;
    Celula* Ult;
};

Lista* IniciaLista(void){
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void InsereLista (Lista* lista, Matriz* mat){
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));

    novaCelula->mat = mat;
    novaCelula->prox = lista->Prim;
    lista->Prim= novaCelula;

    if(lista->Ult == NULL)
        lista->Ult= novaCelula;
}

void ImprimeLista (Lista* lista){
    Celula* p;

    for(p = lista->Prim; p != NULL ; p=p->prox){
        printf("------------\n");
        imprimeMatriz(p->mat);
    }
            printf("\n");
}

Matriz* RetiraLista (Lista* lista, int pos){
    Celula* p = lista->Prim;
    Matriz* mat;
    Celula* ant =  NULL;
    int i=0;

    while (p!=NULL && i<pos){
        ant = p;
        p = p->prox;
        i++;
    }
    
    if(p==NULL)
        return NULL;
    
    mat = p->mat;
    
    //se for unico
    if(p == lista->Prim && p== lista->Ult)
        lista->Prim = lista->Ult = NULL;
    else if (p == lista->Prim) //se for o primeiro
        lista->Prim = p->prox;
    else if (p == lista->Ult){ //se for o ultimo
        lista->Ult=ant;
        lista->Ult->prox= NULL;
    }else   //caso comum
        ant->prox = p->prox;

    free(p);

    return mat;
}

void DestroiLista (Lista* lista){
    Celula* p = lista->Prim;
    Celula* t;

    while( p != NULL){
        t = p->prox;
        destroiMatriz(p->mat);  
        free(p);
        p = t;
    }

    free(lista);
}

