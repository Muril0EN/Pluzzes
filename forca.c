#include <stdio.h>
#include <string.h>

//variáveis declaradas fora de todas as funções são variáveis globais e podem ser usadas em qualquer função
//dispensa ponteiros 
//** deve ser usada com parcimônia pq é possível que se perca o controle dessa variável. Quanto menos for usado, melhor.
char palavraSecreta [20];
char chutes[26]; 
int tentativas = 0; 

void abertura () {
    printf("********************************\n");
    printf("*         Jogo de forca        *\n");
    printf("********************************\n\n");
}

void chuta () { 
    char chute;
    scanf(" %c", &chute); 

    chutes[tentativas] = chute;
    (tentativas)++; 
} 
int jaChutou (char letra){
    int achou = 0;
    
    for (int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaForca() {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
            
            int achou = jaChutou(palavraSecreta[i]);

            if(achou){
                printf("%c ", palavraSecreta[i]);
            } else {   
                printf("_ ");
            }
        }
        printf("\n");
}

void escolhePalavra (char palavraSecreta[20]){
    sprintf(palavraSecreta, "melancia");
}

int main () {

    //variáveis movidas para inicio para que sejam lidas como globais
    // char palavraSecreta [20];
    // char chutes[26]; 
    // int tentativas = 0; 

    int acertou = 0;
    int enforcou = 0;

    escolhePalavra (palavraSecreta);
    abertura(); 

    do {

        desenhaForca(palavraSecreta, chutes, tentativas);
        chuta(chutes, &tentativas); 

    } while (!acertou && !enforcou);
    
}