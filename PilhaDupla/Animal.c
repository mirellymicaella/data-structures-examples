#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Animal.h"

struct animal{
    int especie;
    char* nome;
    char* som;
};

Animal* CriaAnimal(char* nome, char* som, int especie){
    Animal* animal = (Animal*)malloc(sizeof(Animal));

    animal->nome= strdup(nome);
    animal->som=strdup(som);
    animal->especie = especie;

    return animal;
}

char* RecuperaNome(Animal* animal){
    return animal->nome;
}

char* RecuperaSom(Animal* animal){
    return animal->som;
}

int RecuperaEspecie(Animal* animal){
    return animal->especie;
}

void ImprimeAnimal(Animal* animal){
    //printf("%s faz %s.\n",animal->nome, animal->som);
    if(animal->especie == MAMIFERO)
        printf("%s é mamífero.\n", animal->nome);

    if(animal->especie == OVIPARO)
        printf("%s é ovíparo.\n", animal->nome);
}

void DestroiAnimal(Animal* animal){
    free(animal->nome);
    free(animal->som);
    free(animal);
}