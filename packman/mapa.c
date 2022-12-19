#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

void leMapa (MAPA* m){
    FILE* f; //declara ponteiro que vai receber arquivo que vai ser lido de doc externo;
    f = fopen("mapa.txt", "r"); //atribui à variável declarada (ponteiro) doc.txt que vai ser lido pela função 'fopen()'
    if(f == 0) { //trata erro e fecha o programa em caso de problemas com o arquivo;
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas)); //'scanf' para arquivos externos lidos no código
    alocaMapa(m);//chama a função que aloca mapa recebendo m (declarado...)

    for (int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }
    
    fclose(f);//fecha o arquivo
}

void alocaMapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);//malloc -> alocação dinâmica de mem. / sizeoff -> informa qtd de bytes cada tipo de var precisa / * -> multiplica quantidade  que vai 'entrar'
    
    for(int i = 0; i < m->linhas; i++){// para cada linha
        m->matriz[i] = malloc(sizeof(char) * (m->colunas + 1)); //alocar 'vezes' quantidade de colunas 
    }
}

void liberaMapa (MAPA* m){
    for(int i = 0; i < m->linhas; i++){//mesma função presente na linha 5, porém, + simples
        free(m->matriz[i]);//ponteiro de structs
    }
    free((*m).matriz);
}

void imprimeMapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){//imprimir arquivo
        printf("%s\n", m->matriz[i]);//
    }
}