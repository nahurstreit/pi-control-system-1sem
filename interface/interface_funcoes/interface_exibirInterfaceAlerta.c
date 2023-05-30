#include "../../global/global.h"
#include "../interface.h"

bool exibirInterfaceAlerta(char stringAlerta[], char stringOpcao[], char opcaoAfirmativa[], bool opcaoDireta, bool opcaoNumero, int qtdEspacos) {
	int i, tamanhoString = strlen(stringAlerta);
	char escolhaAlterar[2];
	
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("x");
	}
	printf("\nx");
	for(i = 0; i < MAX_LINHA - 3; i++) {
		printf(" ");
	}
	printf("x\nx");
	for(i = 0; i < ((MAX_LINHA - tamanhoString)/2) - 1; i++) {
		printf(" ");
	}
	printf("%s", stringAlerta);
	for(i = 0; i < ((MAX_LINHA - tamanhoString)/2) - 2; i++) {
		printf(" ");
	}
	printf("x\nx");
	for(i = 0; i < MAX_LINHA - 3; i++) {
		printf(" ");
	}
	printf("x\n");
	for(i = 0; i < MAX_LINHA - 1; i++) {
		printf("x");
	}
	
	for(i = 0; i <= qtdEspacos; i++) {
		printf("\n");
	}
	printf(stringOpcao);
	fflush(stdin);
	if(!opcaoDireta) printf("\nOpção: ");
	fgets(escolhaAlterar, MAX_STRING, stdin);
	escolhaAlterar[1] = '\0';
	
	if(opcaoNumero) {
		if(atoi(escolhaAlterar) == atoi(opcaoAfirmativa))	return true;
		return false;
	}
	
	if(validarPalavraChave(escolhaAlterar, opcaoAfirmativa)) return true;
	return false;
}
