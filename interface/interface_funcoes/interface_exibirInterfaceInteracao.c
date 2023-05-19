#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceInteracao(char string[]) {
	int i;
	int tamanhoString = strlen(string); 
	
	for(i = 0; i < strlen(string) + 4; i++) {
		printf(".");
	}
		printf("\n| %s |\n", string);
	for(i = 0; i < strlen(string) + 4; i++) {
		printf(".");
	}
	
	printf("\n\n");
}
