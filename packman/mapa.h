#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VETICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

void alocaMapa(MAPA* m);
void leMapa(MAPA* m);
void liberaMapa(MAPA* m);
void imprimeMapa(MAPA* m);

struct posicao {
    int x;
    int y;
};

typedef struct posicao POSICAO;

void encontraMapa(MAPA* m, POSICAO* p, char c);

int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);

void andaNoMapa(MAPA* m, int xOrigem, int yOrigem, 
    int xDestino, int yDestino);
