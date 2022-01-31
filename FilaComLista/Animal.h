
typedef struct animal Animal;

Animal* CriaAnimal(char* nome, char* som);

char* RecuperaNome(Animal* animal);

char* RecuperaSom(Animal* animal);

void ImprimeAnimal(Animal* animal);

void DestroiAnimal(Animal* animal);