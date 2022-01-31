#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaHet.h"

struct celula{
    Celula* prox;
    void* item;
    int tipo;
};

struct listaHet{
    Celula* Prim;
    Celula* Ult;
};

ListaHet* IniciaLista(void){
    ListaHet* lista = (ListaHet*)malloc(sizeof(ListaHet));
    lista->Prim=NULL;
    lista->Ult=NULL;
    return lista;
}

void InsereFruta(ListaHet* lista, Fruta* fruta){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = fruta;
    nova->tipo = FRUTA;
    nova->prox = lista->Prim;
    lista->Prim = nova;

    if(lista->Ult == NULL)
        lista->Ult = nova;
}

void InsereLegume(ListaHet* lista, Legume* legume){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    nova->item = legume;
    nova->tipo = LEGUME;
    nova->prox = lista->Prim;
    lista->Prim = nova;

    if(lista->Ult == NULL)
        lista->Ult = nova;
}

void ImprimeListaHet(ListaHet* lista){
    Celula* p;

    printf("--------------------------------------\n");
    printf("Frutas:\n");
    printf("--------------------------------------\n");
    for(p=lista->Prim; p != NULL ; p=p->prox){
        if(p->tipo == FRUTA)
            ImprimeFruta(p->item);
    }
    
    printf("--------------------------------------\n");
    printf("Total frutas: %.1f R$\n",CalculaTotalFruta(lista));
    
    printf("--------------------------------------\n");
    printf("Legumes:\n");
    printf("--------------------------------------\n");
    for(p=lista->Prim; p != NULL ; p=p->prox){
        if(p->tipo == LEGUME)
            ImprimeLegume(p->item);
    }

    printf("--------------------------------------\n");
    printf("Total legumes: %.1f R$\n",CalculaTotalLegume(lista));
    printf("--------------------------------------\n");
    printf("TOTAL FEIRA: %.1f R$\n",CalculaTotalLegume(lista)+ CalculaTotalFruta(lista));
    printf("--------------------------------------\n");
}

float CalculaTotalFruta(ListaHet* lista){
    float soma=0;
    Celula* p;

    for(p=lista->Prim; p != NULL ; p=p->prox){
        if(p->tipo == FRUTA)
            soma+=RetornaQuantFruta(p->item)*UNI_FRUTA;
    }
    free(p);

    return soma;
}

float CalculaTotalLegume(ListaHet* lista){
    float soma=0;
    Celula* p;

    for(p=lista->Prim; p != NULL ; p=p->prox){
        if(p->tipo == LEGUME)
            soma+=RetornaQuantKgLegume(p->item) * KG_LEGUME;
    }

    return soma;
}

void DestroiLista(ListaHet* lista){
    Celula* p = lista->Prim;
    Celula* t;

    while( p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }

    free(lista);
}