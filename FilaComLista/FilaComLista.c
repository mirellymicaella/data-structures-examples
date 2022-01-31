#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaAnimal.h"

struct fila {
    Lista* animais;
};

Fila* IniciaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->animais = IniciaLista();
    return fila;
}

void InsereFila(Fila* fila, Animal* animal){
    InsereListaFinal(fila->animais,animal);
}

Animal* RetiraFila(Fila* fila){
    return RetiraLista(fila->animais,0);
}

void ImprimeFila(Fila* fila){
    ImprimeLista(fila->animais);
}

void DestroiFila(Fila* fila){
    if(fila){
        DestroiLista(fila->animais);
        free(fila);
    }
        
    
}