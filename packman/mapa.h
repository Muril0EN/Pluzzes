#define HEROI '@'
#define VAZIO '.'
#define PAREDE_VETICAL '|'
#define PAREDE_HORIZONTAL '-'
#define FANTASMA 'F'

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

int encontraMapa(MAPA* m, POSICAO* p, char c);

int ehValida(MAPA* m, int x, int y);
int ehParede(MAPA* m, int x, int y);
int ehPersonagem(MAPA* m, char personagem, int x, int y);

void andaNoMapa(MAPA* m, int xOrigem, int yOrigem, 
    int xDestino, int yDestino);

void copiaMapa(MAPA* destino, MAPA* origem);

int podeAndar(MAPA* m, char personagem, int x, int y);