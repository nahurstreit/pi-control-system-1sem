#include "../../global/global.h"
#include "../interface.h"

void exibirTextoMeio(char string[]) {
	int i, tamanhoString = strlen(string);
	
	for(i = 0; i < (MAX_LINHA - tamanhoString - 2)/2; i++) {
		printf(" ");
	}
	printf(string);
	printf("\n");
}
