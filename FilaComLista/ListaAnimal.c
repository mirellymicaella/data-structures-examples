#include <stdio.h>
#include <stdlib.h>
#include "ListaAnimal.h"


struct celula{
    Animal* animal;
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

void InsereLista (Lista* lista, Animal* animal){
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));

    novaCelula->animal = animal;
    novaCelula->prox = lista->Prim;
    lista->Prim= novaCelula;

    if(lista->Ult == NULL)
        lista->Ult= novaCelula;
}

void InsereListaFinal(Lista* lista, Animal* animal){
    Celula* novaCelula = (Celula*)malloc(sizeof(Celula));

    novaCelula->animal = animal;
    novaCelula->prox = NULL;

    if(lista->Ult == NULL ){
        lista->Prim = lista->Ult = novaCelula;
        return;
    }
    lista->Ult->prox = novaCelula;
    lista->Ult = novaCelula; 
    
}

void ImprimeLista (Lista* lista){
    Celula* p;

    for(p = lista->Prim; p != NULL ; p=p->prox){
        ImprimeAnimal(p->animal);
    }
    printf("\n");
}

Animal* RetiraLista (Lista* lista, int pos){
    Celula* p = lista->Prim;
    Animal* animal;
    Celula* ant =  NULL;
    int i=0;

    while (p!=NULL && i<pos){
        ant = p;
        p = p->prox;
        i++;
    }
    
    if(p==NULL)
        return NULL;
    
    animal = p->animal;
    
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

    return animal;
}

void DestroiLista (Lista* lista){
    Celula* p = lista->Prim;
    Celula* t;

    while( p != NULL){
        t = p->prox;
        DestroiAnimal(p->animal);  
        free(p);
        p = t;
    }

    free(lista);
}

