#include "../../global/global.h"
#include "../arquivo.h"

bool checarCampoNulo_Arquivo(char campo[]) {
	if(strncmp(campo, "<>", 3) == 0) return true;
	else return false;
}

bool checarCampoNulo_Vetor(char campo[]) {
	if((strncmp(campo, "", 5) == 0) || (strncmp(campo, " ", 5) == 0)) return true;
	else return false;
}
