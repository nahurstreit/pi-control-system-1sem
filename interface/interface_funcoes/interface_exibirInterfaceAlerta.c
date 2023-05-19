#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceAlerta(char string[]) {
	int i, tamanhoString = strlen(string);
	
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
	printf("%s", string);
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
}
