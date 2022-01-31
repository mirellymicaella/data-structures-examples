
typedef struct legume Legume;

Legume* CriaLegume(char* nome, float quantKg);

char* RetornaNomeLegume(Legume* legume);

float RetornaQuantKgLegume(Legume* legume);

void ImprimeLegume(Legume* legume);

void DestroiLegume(Legume* legume);
