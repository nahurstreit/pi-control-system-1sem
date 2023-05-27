#include "../../../global/global.h"
#include "../../validar.h"

void validarIdadeMinMax(char destino[], char maximoOuMinimo[3]) {
	int i;
	
	char dataAtual[11];
	int vetorDataAtual[8];
	
	int anoAtual;
	int anoConta;
	
	receberAnoAtual(dataAtual);
	
	removerCaracteresEspeciais(dataAtual, false);
	
	vetorStringParaInteiro(dataAtual, vetorDataAtual, sizeof(vetorDataAtual)/ sizeof(vetorDataAtual[0]));
	
	sprintf(dataAtual, "%d%d%d%d", vetorDataAtual[4], vetorDataAtual[5], vetorDataAtual[6], vetorDataAtual[7]);
	
	anoAtual = atoi(dataAtual);
	
	if(validarPalavraChave(maximoOuMinimo, "MAX")) {
		anoConta = anoAtual - IDADE_MAXIMA;
		sprintf(destino, "01/01/%d", anoConta);
	} else  {
		anoConta = anoAtual - IDADE_MINIMA;
		sprintf(destino, "31/12/%d", anoConta);
	}
	
}
