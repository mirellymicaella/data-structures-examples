#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

#define MAX_TAM 8

struct indicePilha{
    int Topo;
    int Base;
};

struct pilhaDupla{
    IndicePilha pilha1;
    IndicePilha pilha2;
    Animal* animais[MAX_TAM];
};

PilhaDupla* iniciaPilha(){
    PilhaDupla* p = (PilhaDupla*)malloc(sizeof(PilhaDupla));

    p->pilha1.Base =0;
    p->pilha1.Topo= -1;

    p->pilha2.Base = MAX_TAM -1 ;
    p->pilha2.Topo = MAX_TAM;

    return p;
}

void push(PilhaDupla* pilha, Animal* animal){

    if(!pilha ||( pilha->pilha1.Topo == pilha->pilha2.Topo -1 )){
        printf("Pilha cheia!\n");
        return;
    }
    if(!animal){
        printf("Animal invalido!\n");
        return;
    }

    if(RecuperaEspecie(animal) == MAMIFERO){
        pilha->animais[pilha->pilha1.Topo+1] = animal;
        pilha->pilha1.Topo++;
    }
    if(RecuperaEspecie(animal) == OVIPARO){
        pilha->animais[pilha->pilha2.Topo-1] = animal;
        pilha->pilha2.Topo--;
    }


}

Animal* pop(PilhaDupla* pilha, int especie){    
    if(!pilha ||
        pilha->pilha1.Topo == -1 || 
        pilha->pilha2.Topo == MAX_TAM){
            printf("Pilha vazia!\n");
            return NULL;
    }
    Animal* animal;

    if(especie == MAMIFERO){
        animal = pilha->animais[pilha->pilha1.Topo];
        pilha->pilha1.Topo--;
    }
    if(especie == OVIPARO){
        animal = pilha->animais[pilha->pilha2.Topo];
        pilha->pilha2.Topo++;
    }

    return animal;
}

void imprime(PilhaDupla* pilha){
    if(!pilha)
        return;

    int i;
    printf("\nPILHA 1:\n");
    for(i=(pilha->pilha1.Topo);i>=0;i--)
        ImprimeAnimal(pilha->animais[i]);

    printf("\nPILHA 2:\n");
    for(i=(pilha->pilha2.Topo);i<MAX_TAM;i++)
        ImprimeAnimal(pilha->animais[i]);
}

void destroi(PilhaDupla* pilha){
    if(!pilha)
        return;
    
    free(pilha);
}