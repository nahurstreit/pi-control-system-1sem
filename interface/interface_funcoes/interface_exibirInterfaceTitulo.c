#include "../../global/global.h"
#include "../interface.h"

void exibirInterfaceTitulo(char string[], int limpar) {
	int i;
	int tamanhoString = strlen(string);
	int posicaoTitulo = (MAX_LINHA - tamanhoString)/2;
	
	if(limpar == 1) system("cls"); 
	exibirLogotipo();
	
	Display displayCopia[3];
	
	for(i = 0; i < 3; i++) {
		displayCopia[i] = displayRefTitulo[i];
	}
	
	for(i = 0; i < tamanhoString; i++) {
		displayCopia[1].linhaDisplay[posicaoTitulo + i] = string[i]; 
	}
	
	for(i = 0; i < 3; i++) {
		printf("%s\n", displayCopia[i].linhaDisplay);
	}
	printf("\n");
}
