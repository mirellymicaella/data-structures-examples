#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

struct fila {
    int ini;
    int n;
    Animal* animais[TAM];
};

Fila* IniciaFila(){
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->ini = 0;
    fila->n = 0;

    return fila;
}

void InsereFila(Fila* fila, Animal* animal){
    if(!fila ||  fila->n >=TAM){
        printf("Fila inválida ou cheia!\n");
        return;
    }

    int pos = (fila->ini + fila->n)%TAM;

    fila->animais[pos] = animal;
    fila->n++;

}

Animal* RetiraFila(Fila* fila){
    if(!fila ||  fila->n == 0){
        printf("Fila inválida ou vazia!\n");
        return NULL;
    }

    Animal* animal = fila->animais[fila->ini];

    fila->ini = (fila->ini+1)%TAM;
    fila->n--;

    return animal;
}

void ImprimeFila(Fila* fila){
    if(!fila)
        return;

    int i;
    int pos=0;

    for(i=0; i<fila->n; i++){
        pos = (fila->ini + i)%TAM;
        ImprimeAnimal(fila->animais[pos]);
    }
}

void DestroiFila(Fila* fila){
    if(fila)
        free(fila);
    
}