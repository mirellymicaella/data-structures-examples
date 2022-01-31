#include "Fruta.h"
#include "Legume.h"

#define FRUTA 1
#define LEGUME 2

#define UNI_FRUTA 1.5
#define KG_LEGUME 3

typedef struct celula Celula;
typedef struct listaHet ListaHet;

ListaHet* IniciaLista(void);
void InsereFruta(ListaHet* lista, Fruta* fruta);
void InsereLegume(ListaHet* lista, Legume* legume);
void ImprimeListaHet(ListaHet* lista);
float CalculaTotalFruta(ListaHet* lista);
float CalculaTotalLegume(ListaHet* lista);
void DestroiLista(ListaHet* lista);