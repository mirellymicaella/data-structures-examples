#include "Aluno.h"

typedef struct arv Arv;

Arv* arv_criavazia();

Arv* arv_cria(Aluno* aluno, Arv* e, Arv* d);

Arv* arv_libera(Arv* a);

int arv_vazia(Arv* a);

int arv_pertence(Arv* a, char* nome);

void arv_imprime(Arv* a);

Arv* arv_pai(Arv* a, char* nome);

int folhas(Arv* a);

int ocorrencias(Arv* a, char* nome);

Aluno* info(Arv* a );

static int max2 (int a, int b);

int altura (Arv* a);