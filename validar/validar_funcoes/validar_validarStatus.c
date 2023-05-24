#include "../../global/global.h"
#include "../validar.h"

bool validarStatus(char *pString) {
	int i;
	
	if(pString[0] == '1' || validarPalavraChave(pString, "ATIVO") || validarPalavraChave(pString, "ATIVA")) {
		strcpy(pString, "Ativo");
		return true;
	}
	
	if(pString[0] == '0' || validarPalavraChave(pString, "INATIVO") || validarPalavraChave(pString, "INATIVA")) {
		strcpy(pString, "Inativo");
		return true;
	}
	
	erro = Erro_Input_Status_Invalido;
	return false;
}

