#include "../../global/global.h"
#include "../validar.h"

void removerPontoVirgula(char *pString) {
	char caracteres[] = ";";
	int i, j;
	
    for (i = 0; i < strlen(caracteres); i++) {
	    for (j = 0; j < strlen(pString); j++) {
	        if (pString[j] == caracteres[i]) {
	            int k;
	            for (k = j; k < strlen(pString); k++) {
	                pString[k] = pString[k + 1];
	            }
	            j--;
	        }
	    }
    }

    i = strlen(pString) - 1;
    while (i >= 0 && isspace(pString[i])) {
        pString[i] = '\0';
        i--;
    }
}
