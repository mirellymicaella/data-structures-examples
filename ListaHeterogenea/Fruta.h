typedef struct fruta Fruta;

Fruta* CriaFruta(char* nome, int quant);

char* RetornaNomeFruta(Fruta* fruta);

int RetornaQuantFruta(Fruta* fruta);

void ImprimeFruta(Fruta* fruta);

void DestroiFruta(Fruta* fruta);
