#include <stdio.h>
#include "Fila.h"


int main(int argc, char const *argv[]){
    
    //Criando os animais
    Animal* pintinho = CriaAnimal("Pintinho","piu");
    Animal* galinha = CriaAnimal("Galinha", "có");
    Animal* galo = CriaAnimal("Galo", "corococó");
    Animal* peru = CriaAnimal("Peru", "gulugulu");
    Animal* capote = CriaAnimal("Capote", "tô fraco");
    Animal* gato = CriaAnimal("Gato", "miau");

    Fila* fila= IniciaFila();
    Fila* fila2 = IniciaFila();

    InsereFila(fila,pintinho);
    InsereFila(fila,galinha);
    InsereFila(fila,galo);
    InsereFila(fila,peru);
    InsereFila(fila,gato);

    printf("\n___________ FILA 1 _______________\n");
    ImprimeFila(fila);
    printf("\n___________ FILA 2 _______________\n");
    ImprimeFila(fila2);

    InsereFila(fila2, RetiraFila(fila));
    InsereFila(fila2, RetiraFila(fila));
    InsereFila(fila2, RetiraFila(fila));

    printf("\n\nRetirando 3 items da FILA1 e inserindo na FILA 2\n");
    printf("\n___________ FILA 1 _______________\n");
    ImprimeFila(fila);
    printf("\n___________ FILA 2 _______________\n");
    ImprimeFila(fila2);


    InsereFila(fila2, RetiraFila(fila));
    InsereFila(fila2, RetiraFila(fila));

    printf("\n\nRetirando 2 items da FILA1 e inserindo na FILA 2\n");
    printf("\n___________ FILA 1 _______________\n");
    ImprimeFila(fila);
    printf("\n___________ FILA 2 _______________\n");
    ImprimeFila(fila2);


    return 0;
}
