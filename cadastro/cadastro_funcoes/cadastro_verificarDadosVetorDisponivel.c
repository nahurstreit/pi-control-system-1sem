#include "../../global/global.h"
#include "../cadastro.h"

void verificarDadosVetorDisponivel(int *vetorReferencia, int posicaoConsultada) {
	posicaoConsultada -= 1;
	
	if(vetorReferencia[posicaoConsultada] == 0) {
		erro = 4;
	}
}
