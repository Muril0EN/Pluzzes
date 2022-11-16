#include <stdio.h>

int main (){
	printf("************************************\n");
	printf("* Bem vindo ao jogo de adivinhação *\n");
	printf("************************************\n");
//comentário de linha 	
/*comentário de bloco*/	
	int numeroSecreto = 3;
	int chute;
	int tentativas = 1;

	while (1){ /*sintaxe para looping infinito*/
		printf(" * Tentativa %d *\n", tentativas);/*ajuste pq tentativas é declarado como 0*/
		printf("Digite seu chute:");
		scanf("%d", &chute);

		if(chute < 0){ /*validando a entrada do usuário*/
			printf("Você não pode chutar número negativos!\n");
			
			continue; /*faz com que o código continue, indo para a próxima iteração 'i++'
			antes de seguir a executar o resto do código (economiza execução)*/
		}

		int acertou = (chute == numeroSecreto);
		int maior = chute > numeroSecreto;

		if(acertou){
			printf("Você acertou, parabéns!\n\n");
			
			break;/*usar quando houver looping infinito*/
		} 
		
		else if (maior){ /*quando se 'combina' else if elimina verificações desnecessárias*/
			printf("Você errou, seu chute foi maior que o número secreto.\n\n");
		}
		else {
			printf("Você errou, seu chute foi menor que o número secreto.\n\n");
		}

		tentativas++;	
	}

	printf("Fim de jogo!\n");
	printf("Você acertou em %d tentativas!\n", tentativas);
}