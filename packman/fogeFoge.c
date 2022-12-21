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
    
    //atualiza os valores de posição
    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao){ //essa função agora atribui ás variáveis prox... valores que serão comparados para fins de validação
        case 'a':
            proximoy--;
            break;
        case 'w':
            proximox--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
            proximoy++;
            break;
    }//nesse ponto o suite/case vai apontar para a posição desejada de destino
    //define limites
    if (proximox >= m.linhas)
        return;
    if (proximoy >= m.colunas)
        return;
    if(m.matriz[proximox][proximoy] != '.')//verifica se o espaço é diferente '.'
        return;
    //atualiza elemento na posição depois de passar por todas as condições
    m.matriz[proximox][proximoy] = '@';//com heroi
    m.matriz[heroi.x][heroi.y] = '.';//com ponto
    heroi.x = proximox;//atualiza posição 'final'
    heroi.y = proximoy;//atualiza posição 'final'
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