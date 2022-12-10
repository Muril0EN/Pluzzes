#include <stdio.h>
#include <stdlib.h>

char** mapa; //declaração de ponteiros de ponteiros (necessário para matriz)
int linhas;
int colunas; 

int main(){
    
    FILE* arquivo; //nome do arquivo
    arquivo = fopen("mapa.txt", "r"); //lê arquivo
    if(arquivo == 0) { //trata erro e fecha o programa em caso de problemas com o arquivo
        printf("Erro na leitura do mapa!\n");
        exit(1);
    }

    fscanf(arquivo, "%d %d", &linhas, &colunas); //
    printf("linhas %d colunas %d\n", linhas, colunas);//

    mapa = malloc(sizeof(char*) * linhas);//malloc -> alocação dinâmica de mem. / sizeoff -> informa qtd de bytes cada tipo de var precisa / * -> multiplica quantidade  que vai 'entrar'
    for(int i = 0; i < linhas; i++){// para cada linha
        mapa[i] = malloc(sizeof(char) * (colunas + 1)); //alocar 'vezes' quantidade de colunas 
    }

    for(int i = 0; i < 5; i++) {// ler o arquivo
        fscanf(arquivo, "%s", mapa[i]);
    }

    for (int i = 0; i < 5; i++){//imprimir arquivo
        printf("%s\n", mapa[i]);//
    }
    
    fclose(arquivo);//fecha o arquivo

    for(int i = 0; i < linhas; i++){//
        free(mapa[i]);//liberar memória de cada uma das linhas (ponteiros)
    }

    free(mapa);//liberar memória do ponteiro de ponteiro

    for(int i = 0; i < 5; i++){
        fscanf(arquivo, "%s", mapa[i]);//lê a linha inteira e passa para o mapa a cada loop
    }

    for (int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);//imprime mapa
    }

    fclose(arquivo);
    
}