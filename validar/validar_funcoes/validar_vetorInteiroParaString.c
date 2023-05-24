#include "../../global/global.h"
#include "../validar.h"

void vetorInteiroParaString(int pVetor[], char pString[], int caso) {
	switch(caso) {
		case 1:
			sprintf(pString, "%d%d%d.%d%d%d.%d%d%d-%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7], pVetor[8], pVetor[9], pVetor[10]);
			break;
		case 2:
			sprintf(pString, "%d%d.%d%d%d.%d%d%d/%d%d%d%d-%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7], pVetor[8], pVetor[9], pVetor[10], pVetor[11], pVetor[12], pVetor[13]);
			break;
		case 3:
			sprintf(pString, "%d%d/%d%d/%d%d%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7]);
			break;
		case 4:
			sprintf(pString, "(%d%d) %d%d%d%d-%d%d%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7], pVetor[8], pVetor[9]);
			break;
		case 5:
			sprintf(pString, "(%d%d) %d %d%d%d%d-%d%d%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7], pVetor[8], pVetor[9], pVetor[10]);
			break;
		case 6:
			sprintf(pString, "%d%d%d%d%d-%d%d%d", pVetor[0], pVetor[1], pVetor[2], pVetor[3], pVetor[4], pVetor[5], pVetor[6], pVetor[7]);
			break;
		default: ;
	}
}
