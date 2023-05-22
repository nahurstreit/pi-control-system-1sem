#include "../../global/global.h"
#include "../cadastro.h"

int calcularDadosExistentes(int vetorReferencia[MAX_VETOR]) {
	int i, contadorDadosExistentes = 0;
	
	for(i = 0; i < MAX_VETOR; i++) {
		contadorDadosExistentes += vetorReferencia[i];
	}
	
	return contadorDadosExistentes;
}
