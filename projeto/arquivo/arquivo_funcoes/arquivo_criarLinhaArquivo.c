#include "../../global/global.h"
#include "../arquivo.h"

void criarLinhaArquivo(char stringDestino[], char stringAdicao[]) {
	
	if(checarCampoNulo_Vetor(stringAdicao)) {
		strcat(stringDestino, "<>");
	} else {
		strcat(stringDestino, stringAdicao);
	}
	strcat(stringDestino, ";");
}
