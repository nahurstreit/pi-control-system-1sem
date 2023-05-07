#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "interface.h"

#define TAM 103

void inserirTextoInterface(char *linhaCopia, char *string, int posicao);

void interfaceLinhaSimples(char *string, int posicao) {
	char linhaCopia[TAM];
	char *pLinhaCopia = linhaCopia;
	strcpy(pLinhaCopia, linhaBase);
	
	inserirTextoInterface(pLinhaCopia, string, posicao+1);
	strcpy(linhaCopia, pLinhaCopia);
	printf("%s\n", linhaCopia);

}

void interfaceLinhaComposta(char *string1, int posicao1, char *string2, int posicao2) {
	
	char linhaCopia[TAM];
	char *pLinhaCopia = linhaCopia;
	strcpy(pLinhaCopia, linhaBase);
	
	inserirTextoInterface(pLinhaCopia, string1, posicao1 + 1);
	inserirTextoInterface(pLinhaCopia, string2, posicao2+ 1);
	strcpy(linhaCopia, pLinhaCopia);
	printf("%s\n", linhaCopia);
	
}



void inserirTextoInterface(char *linhaCopia, char *string, int posicao) {
	int i;

	for(i = 0; i < strlen(string); i++) {
		linhaCopia[posicao + i] = string[i];
	}
}
