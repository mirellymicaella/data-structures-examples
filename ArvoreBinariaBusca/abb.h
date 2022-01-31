#include "Aluno.h"

typedef struct arv Arv;

Arv* abb_cria ();

void abb_imprime (Arv* a);

Arv* abb_busca (Arv* a, int chave);

Arv* abb_insere (Arv* a, Aluno* aluno);

Arv* abb_retira (Arv* a, int chave);

Arv* abb_libera (Arv* a);