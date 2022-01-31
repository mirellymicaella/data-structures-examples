#include "Animal.h"
#define TAM 6

typedef struct fila Fila;

Fila* IniciaFila();

void InsereFila(Fila* fila, Animal* animal);

Animal* RetiraFila(Fila* animal);

void ImprimeFila(Fila* fila);

void DestroiFila(Fila* fila);