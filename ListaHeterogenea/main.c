#include <stdio.h>
#include "ListaHet.h"

int main(int argc, char const *argv[]){
    
    ListaHet* lista = IniciaLista();

    //Criação de Frutas
    Fruta* banana = CriaFruta("cacho de banana", 5);
    Fruta* maca = CriaFruta("maca", 5);
    Fruta* melancina = CriaFruta("melancia", 1);
    Fruta* manga = CriaFruta("manga", 6);
    Fruta* laranja = CriaFruta("laranja", 10);
    Fruta* goiaba = CriaFruta("goiaba", 9);

    //Adiciona Frutas na lista
    InsereFruta(lista,banana);
    InsereFruta(lista,maca);
    InsereFruta(lista,melancina);
    InsereFruta(lista,manga);
    InsereFruta(lista,laranja);
    InsereFruta(lista,goiaba);

    //Criação de Frutas
    Legume* beterraba = CriaLegume("beterraba",1.3);
    Legume* cenoura = CriaLegume("cenoura",0.8);
    Legume* mandioca = CriaLegume("mandioca",2);
    Legume* abobora = CriaLegume("abobora",2);
    Legume* batata = CriaLegume("batata",1);

    //Adiciona Legumes na lista
    InsereLegume(lista,beterraba);
    InsereLegume(lista,cenoura);
    InsereLegume(lista,mandioca);
    InsereLegume(lista,abobora);
    InsereLegume(lista,batata);

    printf("--------------------------------------\n");
    printf("          PROMOCAO NA FEIRA           \n");
    printf("--------------------------------------\n");
    printf("%.1f R$ a unidade de qualquer fruta   \n",UNI_FRUTA);
    printf("%.1f R$ o quilo de qualquer legume       \n",KG_LEGUME);
    printf("--------------------------------------\n");
    printf("     Nota fiscal\n");


    ImprimeListaHet(lista);

    DestroiLista(lista);

    return 0;
}
