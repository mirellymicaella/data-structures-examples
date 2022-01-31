#include "matriz.h"

typedef struct lista Lista;
typedef struct celula Celula;

Lista* IniciaLista();

void InsereLista (Lista* lista, Matriz* mat);

void ImprimeLista (Lista* lista);

Matriz* RetiraLista (Lista* lista, int pos);

void DestroiLista (Lista* lista);