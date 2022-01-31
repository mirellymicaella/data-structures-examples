#include <stdio.h>
#include "listaMat.h"

void PreencheMatriz(Matriz* mat){
    int i,j;
    int l = recuperaNLinhas(mat);
    int c = recuperaNColunas(mat);
    for(i=0; i<l;i++)
        for(j=0;j<c;j++)
            modificaElemento(mat,i,j, i+j);

}

int main(){

    //Incialização das matrizes
    Matriz* mat1 = inicializaMatriz(5,4);
    Matriz* mat2= inicializaMatriz(3,4);
    Matriz* mat3 = inicializaMatriz(3,3);
    Matriz* mat4 = inicializaMatriz(2,5);
    Matriz* mat5 = inicializaMatriz(4,3);
    Matriz* matExcluida;

    //Preenchimento das matrizes
    PreencheMatriz(mat1);
    PreencheMatriz(mat2);
    PreencheMatriz(mat3);
    PreencheMatriz(mat4);
    PreencheMatriz(mat5);

    //LISTA 1
    Lista* lista1 = IniciaLista();
    InsereLista(lista1,mat1);
    InsereLista(lista1,mat2);
    InsereLista(lista1,mat3);
    InsereLista(lista1,mat4);
    InsereLista(lista1,mat5);

    printf("Lista inicial:\n\n");
    ImprimeLista(lista1);
    
    //LISTA2
    Lista* lista2 = IniciaLista();
    InsereLista(lista2,transposta(mat1));
    InsereLista(lista2,transposta(mat2));
    InsereLista(lista2,transposta(mat3));
    InsereLista(lista2,transposta(mat4));
    InsereLista(lista2,transposta(mat5));

    printf("Lista de transpostas:\n\n");
    ImprimeLista(lista2);

    // //Tirar a 3a posição da lista1 (começa em 0)
    // matExcluida = RetiraLista(lista1,2);
    // destroiMatriz(matExcluida);
    // printf("Retirando 3a matriz da lista1:\n\n");
    // ImprimeLista(lista1);

    // //Tirar a 1a posição da lista de trasnpostas
    // matExcluida = RetiraLista(lista2,0);
    // destroiMatriz(matExcluida);
    // printf("Retirando 1a posição da lista de trasnpostas:\n\n");
    // ImprimeLista(lista2);

    // //Tirar a ultima posição da lista1 
    // matExcluida = RetiraLista(lista1,4);
    // destroiMatriz(matExcluida);
    // printf("Retirando ultima matriz da lista1:\n\n");
    // ImprimeLista(lista1);

    // //Inserindo uma nova matriz na lista de transpostas
    // Matriz* mat6 = inicializaMatriz(2,2);
    // PreencheMatriz(mat6);
    // InsereLista(lista2,mat6);
    // printf("Inserindo novamente uma matriz na lista de trasnpostas:\n");
    // ImprimeLista(lista2);
    
    // //Inserindo uma nova matriz na lista1
    // Matriz* mat7 = inicializaMatriz(1,5);
    // PreencheMatriz(mat7);
    // InsereLista(lista1,mat7);
    // printf("Inserindo novamente uma matriz na lista1:\n");
    // ImprimeLista(lista1);

    DestroiLista(lista1);
    DestroiLista(lista2);

    return 0;
}