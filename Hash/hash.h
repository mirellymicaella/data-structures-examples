#include "palavra.h"

typedef struct hash Hash;

Hash* inicHash(int tamanho);

//Faz acesso a hash realizando 2 possiveis operacoes
//1) insercao, caso a palavra não esteja na hash
//2) incremento de ocorrencia, caso a palavra ja esteja na hash
Palavra* acessa(Hash* h, char* string);

int contaPalavras(Hash* h);

void imprimeHash(Hash* h);

void liberaHash(Hash* h);
