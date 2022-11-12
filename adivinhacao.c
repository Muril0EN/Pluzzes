#include <stdio.h>

int main (){
	printf("************************************\n");
	printf("* Bem vindo ao jogo de adivinhação *\n");
	printf("************************************\n");
//comentário de linha 	
	
	int numeroSecreto = 3;
	int teste;
	int chute;
	
	printf("Digite seu chute:");
	scanf("%d", &chute);

	int acertou = (chute == numeroSecreto);

	if(acertou){
		printf("Você acertou, parabéns!\n\n");
	} else {
		int maior = (numeroSecreto < chute);
		if (maior){
			printf("Você errou, seu chute foi maior que o número secreto.\n\n");
		} else {
			printf("Você errou, seu chute foi menor que o número secreto.\n\n");
		}
	}
}
