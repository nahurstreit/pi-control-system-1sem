#include "../../global/global.h"
#include "../interface.h"

void exibirTextoMeio(char string[]) {
	int i, tamanhoString = strlen(string);
	
	for(i = 1; i < (MAX_LINHA - tamanhoString)/2; i++) {
		printf(" ");
	}
	printf(string);
	printf("\n");
}
