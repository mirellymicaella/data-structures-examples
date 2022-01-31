#include "Animal.h"

typedef struct pilhaDupla PilhaDupla;
typedef struct indicePilha IndicePilha;

PilhaDupla* iniciaPilha();
void push(PilhaDupla* pilha, Animal* animal);
Animal* pop(PilhaDupla* pilha, int especie);
void imprime(PilhaDupla* pilha);
void destroi(PilhaDupla* pilha);