#include <stdio.h>
#include "ListaDpl.h"

int main(int argc, char const *argv[]){

    ListaDpl* lista = IniciaLista();

    Animal* pintinho = CriaAnimal("Pintinho","piu");
    Animal* galinha = CriaAnimal("Galinha", "có");
    Animal* galo = CriaAnimal("Galo", "corococó");
    Animal* peru = CriaAnimal("Peru", "gulugulu");
    Animal* capote = CriaAnimal("Capote", "tô fraco");
    Animal* gato = CriaAnimal("Gato", "miau");

    lista = InsereLista(lista,gato);
    lista = InsereLista(lista,capote);
    lista = InsereLista(lista,peru);
    lista = InsereLista(lista,galo);
    lista = InsereLista(lista,galinha);
    lista = InsereLista(lista,pintinho);

    ImprimeLista(lista);
    printf("____________________\n\n");

    //Retira um que não existe
    lista = RetiraLista(lista,"Cavalo");
    ImprimeLista(lista);
    printf("____________________\n\n");

    //Retira do começo
    lista = RetiraLista(lista,"Pintinho");
    ImprimeLista(lista);
    printf("____________________\n\n");

    //Retira do final
    lista = RetiraLista(lista,"Gato");
    ImprimeLista(lista);
    printf("____________________\n\n");


    //Insere no começo
    lista = InsereLista(lista,gato);
    ImprimeLista(lista);
    printf("____________________\n\n");

    //Retira do meio
    lista = RetiraLista(lista,"Peru");
    ImprimeLista(lista);
    printf("____________________\n\n");

    DestroiLista(lista);
    return 0;
}
