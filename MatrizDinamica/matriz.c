#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz{
    int nlinhas;
    int ncolunas;
    int **mat;
};

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz *matriz = (Matriz *) malloc(sizeof(Matriz));

    matriz->nlinhas = nlinhas;
    matriz->ncolunas = ncolunas;

    matriz->mat = (int **)malloc(nlinhas * sizeof(int*));

    int i;
    for(i=0; i<nlinhas;i++){
        matriz->mat[i] = (int *)malloc(ncolunas * sizeof(int*));
    }

    return matriz;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->mat[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat){
    Matriz *transp = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    int i,j;
    for(i=0;i<mat->ncolunas;i++){
        for(j=0;j<mat->nlinhas;j++){
            transp->mat[i][j]= mat->mat[j][i];
        }
    }

    return transp;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz *mult = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);
    
    int i,j,k,soma =0;

    for(i=0;i<mat1->nlinhas;i++){
        for(j=0;j<mat2->ncolunas;j++){
            for(k=0;k<mat1->ncolunas;k++){
                soma += mat1->mat[i][k]*mat2->mat[k][j];
            }
            mult->mat[i][j] = soma;
            soma=0;
        }
    }
    return mult;
}

void imprimeMatriz(Matriz* mat){
    int i,j;
    for(i=0;i<mat->nlinhas;i++){
        for(j=0;j<mat->ncolunas;j++){
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz* mat){
    int i;
    for(i=0;i<mat->nlinhas;i++)
        free(mat->mat[i]);

    free(mat->mat);  
    free(mat);

}