#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Legume.h"

struct legume{
    char* nome;
    float quantKg;
};

Legume* CriaLegume(char* nome, float quantKg){
    Legume* legume = (Legume*)malloc(sizeof(Legume));
    legume->nome = strdup(nome);
    legume->quantKg=quantKg;
}

char* RetornaNomeLegume(Legume* legume){
    return(legume->nome);
}

float RetornaQuantKgLegume(Legume* legume){
    return(legume->quantKg);
}

void ImprimeLegume(Legume* legume){
    printf("%15s:               ",legume->nome);
    printf("%.1f Kg\n", legume->quantKg);
}

void DestroiLegume(Legume* legume){
    free(legume->nome);
    free(legume);
}