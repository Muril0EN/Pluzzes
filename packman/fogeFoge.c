#include <stdio.h>
#include <stdlib.h>
#include "fogeFoge.h"
#include "mapa.h"

MAPA m; 
POSICAO heroi;

int acabou(){
    return 0;
}

int ehDirecao(char direcao){
    return 
        direcao == 'a' ||
        direcao == 'w' ||
        direcao == 's' ||
        direcao == 'd';
}

void move(char direcao){

    if(!ehDirecao(direcao))
        return;

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao){ //essa função agora atribui ás variáveis prox... valores que serão comparados para fins de validação
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
    
    if(!ehValida(&m, proximox, proximoy))
        return;
    
    if(!ehVazia(&m, proximox, proximoy))//verifica se o espaço é diferente '.'
        return;
    //atualiza elemento na posição depois de passar por todas as condições
    
    andaNoMapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;//atualiza posição 'final'
    heroi.y = proximoy;//atualiza posição 'final'
}

int main(){

    leMapa(&m);
    encontraMapa(&m, &heroi, HEROI);

    do { 
        imprimeMapa(&m);

        char comando;
        scanf(" %c", &comando);
        
        move(comando);

    } while(!acabou()); 
    
    liberaMapa(&m);
}