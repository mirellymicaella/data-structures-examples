#define MAMIFERO 1
#define OVIPARO 2

typedef struct animal Animal;

Animal* CriaAnimal(char* nome, char* som, int especie);

char* RecuperaNome(Animal* animal);

char* RecuperaSom(Animal* animal);

int RecuperaEspecie(Animal* animal);

void ImprimeAnimal(Animal* animal);

void DestroiAnimal(Animal* animal);