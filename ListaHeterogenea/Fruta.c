#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fruta.h"

struct fruta{
    char* nome;
    int quant;
};

Fruta* CriaFruta(char* nome, int quant){
    Fruta* fruta = (Fruta*)malloc(sizeof(Fruta));
    fruta->nome = strdup(nome);
    fruta->quant=quant;
}

char* RetornaNomeFruta(Fruta* fruta){
    return(fruta->nome);
}

int RetornaQuantFruta(Fruta* fruta){
    return(fruta->quant);
}

void ImprimeFruta(Fruta* fruta){
    printf("%15s:               %d Uni\n",fruta->nome,fruta->quant);
}

void DestroiFruta(Fruta* fruta){
    free(fruta->nome);
    free(fruta);
}