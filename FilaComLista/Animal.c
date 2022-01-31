#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Animal.h"

struct animal{
    char* nome;
    char* som;
};

Animal* CriaAnimal(char* nome, char* som){
    Animal* animal = (Animal*)malloc(sizeof(Animal));

    animal->nome= strdup(nome);
    animal->som=strdup(som);

    return animal;
}

char* RecuperaNome(Animal* animal){
    return animal->nome;
}

char* RecuperaSom(Animal* animal){
    return animal->som;
}

void ImprimeAnimal(Animal* animal){
    printf("%s faz %s.\n",animal->nome, animal->som);
}

void DestroiAnimal(Animal* animal){
    free(animal->nome);
    free(animal->som);
    free(animal);
}