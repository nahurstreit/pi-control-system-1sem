#include "../../global/global.h"
#include "../cadastro.h"

int posicaoDisponivel(int *vetorReferencia) {
	int i;
	
	for(i = 0; i < MAX_VETOR; i++) {
		if(vetorReferencia[i] == 0) {
			vetorReferencia[i] = 1;
			break;
		}
	}
	return i;
}
