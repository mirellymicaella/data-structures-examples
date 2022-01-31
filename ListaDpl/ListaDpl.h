#include "Animal.h"
typedef struct listaDpl ListaDpl;

ListaDpl* IniciaLista();

ListaDpl* InsereLista(ListaDpl* lista, Animal* animal);

static ListaDpl* busca(ListaDpl* lista, char* chave);

ListaDpl* RetiraLista(ListaDpl* lista, char* chave);

void ImprimeLista(ListaDpl* lista);

void DestroiLista (ListaDpl* lista);