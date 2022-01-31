#include "ListaDpl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listaDpl{
    Animal* animal;
    ListaDpl* prox;
    ListaDpl* ant;
};

ListaDpl* IniciaLista(){
    return NULL;
}

ListaDpl* InsereLista(ListaDpl* lista, Animal* animal){
    ListaDpl* nova = (ListaDpl*)malloc(sizeof(ListaDpl));
    nova->animal = animal;
    nova->ant = NULL;
    nova->prox = lista;

    if(lista != NULL)
        lista->ant = nova;

    return nova;
}

static ListaDpl* busca(ListaDpl* lista, char* chave){
    ListaDpl* p;

    for(p=lista; p!=NULL; p=p->prox)
        if(strcmp(RecuperaNome(p->animal),chave) == 0)
    return p;
}

ListaDpl* RetiraLista(ListaDpl* lista, char* chave){    
      //Retorna o ponteiro para a celula a ser retirada (ou NULL)
    ListaDpl* p = busca(lista, chave);
    
    if (p == NULL)
    /* não achou o elemento: retorna lista inalterada */
        return lista;
    
    /* retira elemento do encadeamento */
    if (lista == p) /* testa se é o primeiro elemento */
        lista = p->prox;
    else
        p->ant->prox = p->prox;
    if (p->prox != NULL) /* testa se é o último elemento */
        p->prox->ant = p->ant;

    free(p);

    return lista;
}

void ImprimeLista(ListaDpl* lista){
     ListaDpl* p;
     
     for(p=lista; p!=NULL; p=p->prox)
        ImprimeAnimal(p->animal);    

}

void DestroiLista (ListaDpl* lista){
    ListaDpl* p = lista;
    ListaDpl* t;

    while( p != NULL){
        t = p->prox;
        DestroiAnimal(p->animal);  
        free(p);
        p = t;
    }
}