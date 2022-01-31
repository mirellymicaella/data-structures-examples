#include <stdio.h>
#include "Arvore.h"

char* pertenceString(int n){
    if(n)
        return "sim";
    else
        return "não";
}


int main(int argc, char const *argv[]){

    Aluno* ana = InicAluno("Ana",123545, 7.8);
    Aluno* bia = InicAluno("Bia",123445, 8);
    Aluno* cris = InicAluno("Cris",123114, 5.5);
    Aluno* dani = InicAluno("Dani",124423, 6);
    Aluno* elsa = InicAluno("Elsa",1277734, 5.9);

    
    Arv* a = arv_cria(
        //raiz
        ana,

        //esq
        arv_cria(
            //raiz
            bia,
            //esq
            arv_criavazia(),
            //dir
            arv_criavazia()),

        //dir
        arv_cria(
            //raiz
            cris,
            //esq
            arv_cria(
                //raiz
                dani,
                //esq
                arv_criavazia(),
                //dir
                arv_criavazia()),

            //dir
            arv_cria(
                //raiz
                elsa,
                //esq
                arv_criavazia(),
                //dir
                arv_criavazia()))        
    );

    arv_imprime(a);
   
    //Ana pertence a arvore (Sim)
    printf("\nAna pertence ? : %s\n", 
    pertenceString(arv_pertence(a, "Ana")));

    //Fabio pertence a arvore (Nao)
    printf("Fabio pertence ? : %s\n", 
    pertenceString(arv_pertence(a, "Fabio")));

    //Retorna o pai de Elsa (Cris)
    Arv* pai = arv_pai(a, "Elsa");
    printf("Pai de Elsa: %s\n", RetornaNome(info(pai)));

    //Retorna o número de folhas da árvore (3)
    printf("Numero de folhas da arvore: %d\n", folhas(a));

    //Retorna o número de ocirrencias de "Bia" (1)
    printf("Numero de ocorrencias de Bia: %d\n",ocorrencias(a, "Bia"));

    //Retorna altura da arvore (2)
    printf("Altura da arvore: %d\n", altura(a));

    //Libera a memória alocada
    arv_libera(a);
    DestroiAluno(ana);
    DestroiAluno(bia);
    DestroiAluno(cris);
    DestroiAluno(dani);
    DestroiAluno(elsa);
    return 0;
}
