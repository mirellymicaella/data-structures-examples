#include "Animal.h"

typedef struct lista Lista;
typedef struct celula Celula;

Lista* IniciaLista();

void InsereLista (Lista* lista, Animal* animal);

void InsereListaFinal(Lista* lista, Animal* animal);

void ImprimeLista (Lista* lista);

Animal* RetiraLista (Lista* lista, int pos);

void DestroiLista (Lista* lista);
