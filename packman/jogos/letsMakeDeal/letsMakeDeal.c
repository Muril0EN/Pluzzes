#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
        printf("\n***************************************\n");
    printf("          * Let's Make a Deal? *\n");
    printf("***************************************\n\n");

printf("     _____       _____       _____\n");
printf("    |     |     |     |     |     |\n");
printf("    |  1  |     |  2  |     |  3  |\n");
printf("    |     |     |     |     |     |\n");

printf("\n Atrás de uma dessas portas há um barra de ouro, atrás das outras duas há duas lixeiras.\n\n");

  printf("Terá duas chances: \n -> escolher / manter escolha; \n -> escolher / trocar.\n\n");

printf("Que comecem os jogos, boa sorte! \n\n");

  int numeroPortaSecreta, portaEscolhida;
  
  srand(time(0));
  numeroPortaSecreta = (rand() % 3) +1;

  printf("A porta secreta é : %d\n\n", numeroPortaSecreta);

  char trocar;
  int acertou;
  int errou;
  
  printf("Qual porta você escolhe?\n 1\n 2\n 3\n->");
  scanf("%d", &portaEscolhida);
  printf("Você escolheu a porta %d.\n", portaEscolhida);
  //printf("Quer trocar?  s/n\n-> ");
  //scanf("%s", &trocar);
  //printf("Escolheu trocar: %s\n", &trocar);

  if(portaEscolhida == numeroPortaSecreta){
    printf("Parabéns, você ganhou!\n");
  }
  else {
    printf("Você perdeu!\nA porta premiada era a porta %d.", numeroPortaSecreta);
  }
    
}