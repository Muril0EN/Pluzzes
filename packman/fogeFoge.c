#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "fogeFoge.h"
#include "mapa.h"

MAPA m; 
POSICAO heroi;

int acabou(){
    POSICAO pos;
    
    int perdeu = !encontraMapa(&m, &pos, HEROI);
    int ganhou = !encontraMapa(&m, &pos, FANTASMA);

    return ganhou || perdeu;

}

int ehDirecao(char direcao){
    return 
        direcao == ESQUERDA ||
        direcao == CIMA ||
        direcao == BAIXO ||
        direcao == DIREITA;
}

void move(char direcao){

    if(!ehDirecao(direcao))
        return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao) { //essa função agora atribui ás variáveis prox... valores que serão comparados para fins de validação
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
    }//nesse ponto o suite/case vai apontar para a posição desejada de destino
    //define limites
    
    if(!podeAndar(&m, HEROI, proximox, proximoy));
        return;

    andaNoMapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;//atualiza posição 'final'
    heroi.y = proximoy;//atualiza posição 'final'
}

int praOndeFantasmaVai (int xAtual, int yAtual, int* xDestino, int* yDestino){
    int opcoes[4][2] = {
        { xAtual, yAtual +1},
        { xAtual +1, yAtual},
        { xAtual -1, yAtual}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;
            
            if (podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
                *xDestino = opcoes[posicao][0];
                *yDestino = opcoes[posicao][1];

                return 1;
            }
    }

    return 0;
}


void fantasmas(){
    MAPA copia;

    copiaMapa(&copia, &m);

    for (int i = 0; i < copia.linhas; i++){
        for (int j = 0; j < copia.colunas; j++){
            
            if(copia.matriz[i][j] == FANTASMA){
                
                int xDestino;
                int yDestino;

                int encontrou = praOndeFantasmaVai(i, j, &xDestino, &yDestino);

                if(encontrou){
                    andaNoMapa(&m, i, j, xDestino, yDestino);
                }
            }
        }
    }

    liberaMapa(&copia);
}

int main(){

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do { 
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        move(comando);
        fantasmas();

    } while(!acabou()); 
    
    liberaMapa(&m);
}