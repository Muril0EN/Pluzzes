void alocaMapa();
void leMapa();
void liberaMapa();

int acabou();
void move(char direcao);
void imprimeMapa();

struct mapa { //conjunto ou agrupamento de variáveis diferentes, mas que são essenciais para o funcionamento de uma estrutura 
    char** matriz; 
    int linhas;
    int colunas; 
};

typedef struct mapa MAPA; 