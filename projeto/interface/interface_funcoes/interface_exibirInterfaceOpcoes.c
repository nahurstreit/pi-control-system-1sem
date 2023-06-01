#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceOpcoes() {
	int i;
	int numOpcoes = menuAtual.numeroDeOpcoes;
	char stringMeio[10] = " Opções ";

	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	printf(stringMeio);
	for(i = 0; i < (MAX_LINHA - strlen(stringMeio))/2; i++) {
		printf("~");
	}
	
	printf("\n\n");
	for(i = 0; i < numOpcoes; i++) {
		printf(" [%d] - %s\n\n", menuAtual.opcoes[i].numeroDaOpcao, menuAtual.opcoes[i].textoDaOpcao);
	}
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("~");
	}
	
	printf("\n\nOpção: ");
}
