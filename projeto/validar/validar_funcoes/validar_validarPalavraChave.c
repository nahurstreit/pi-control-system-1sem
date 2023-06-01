#include "../../global/global.h"

bool validarPalavraChave(char string[], char stringChave[]) {
	char stringHolder[MAX_STRING];
	int i;
	
	for(i = 0; i < strlen(stringChave); i++) {
		stringHolder[i] = toupper(string[i]);
	}
	
	if(strncmp(stringHolder, stringChave, strlen(stringChave)) == 0) return true;
	else return false;
}
