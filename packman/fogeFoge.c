#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h"
#include "mapa.h"

MAPA m; 
POSICAO heroi;

int acabou(){
    return 0;
}

void mover(char direcao) {

    //validar entrada do usuário
    if (direcao != 'a' &&
        direcao != 'w' &&
        direcao != 's' &&
        direcao != 'd') {
        return;//mata a função sem executar qualquer coisa
    }
    
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao){
        case 'a':
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        case 'w':
            m.matriz[heroi.x-1][heroi.y] = '@'; 
            heroi.x--;
            break;
        case 's':
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        case 'd':
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
    }
}

int main(){

    leMapa(&m);
    encontraMapa(&m, &heroi, '@');

    do { 
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        mover(comando);

    } while(!acabou()); 
    
    liberaMapa(&m);
}