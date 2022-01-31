#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

int main(int argc, char const *argv[]){
    
    //Criando os animais
    Animal* pintinho = CriaAnimal("Pintinho","piu", OVIPARO);
    Animal* galinha = CriaAnimal("Galinha", "có", OVIPARO);
    Animal* galo = CriaAnimal("Galo", "corococó", OVIPARO);
    Animal* peru = CriaAnimal("Peru", "gulugulu", OVIPARO);
    Animal* capote = CriaAnimal("Capote", "tô fraco", OVIPARO);
    Animal* gato = CriaAnimal("Gato", "miau", MAMIFERO);
    Animal* cachorro = CriaAnimal("Cachorro", "auau", MAMIFERO);
    Animal* vaca = CriaAnimal("Vaca", "mu", MAMIFERO);
    Animal* cabra = CriaAnimal("Cabra", "meh", MAMIFERO);

    PilhaDupla* pilha = iniciaPilha();

    //Adicionando nas pilhas
    //Serão separados em:
    //Pilha1 = mamiferos
    //Pilha2 = oviparos
    push(pilha, pintinho);
    push(pilha, galinha);
    push(pilha, vaca);
    push(pilha, peru);
    push(pilha, gato);
    push(pilha, galo);
    push(pilha, cachorro);
    push(pilha, capote);

    //Esse nao entra pois a pilha já está cheia
    push(pilha, cabra);

    //Imprimindo a pilha ( cachorro)
    printf("Imprmindo pilha:\n\n");
    imprime(pilha);


    //retirando um animal ()
    Animal* deletado = pop(pilha, MAMIFERO);
    DestroiAnimal(deletado);

    //Imprimindo a pilha
    printf("Imprmindo pilha:\n\n");
    imprime(pilha);


    destroi(pilha);

    DestroiAnimal(pintinho);
    DestroiAnimal(galinha);
    DestroiAnimal(vaca);
    DestroiAnimal(peru);
    DestroiAnimal(galo);
    DestroiAnimal(gato);

    return 0;
}
