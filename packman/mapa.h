struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void alocaMapa (MAPA* m);
void leMapa (MAPA* m);
void liberaMapa (MAPA* m);
void imprimeMapa (MAPA* m);

