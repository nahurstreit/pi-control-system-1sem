#include "../../global/global.h"
#include "../validar.h"

bool validarEstadoCivil(char *pString) {
	
	if(verificarContemNumeros(pString)) {
		erro = Erro_Input_ApenasLetras;
		return false;
	}
	
	if(validarPalavraChave(pString, "S") || validarPalavraChave(pString, "SOLTEIRO") || validarPalavraChave(pString, "SOLTEIRA")) {
		strcpy(pString, "Solteiro(a)");
		return true;
	} else if(validarPalavraChave(pString, "C") || validarPalavraChave(pString, "CASADO") || validarPalavraChave(pString, "CASADA")) {
		strcpy(pString, "Casado(a)");
		return true;
	} else if(validarPalavraChave(pString, "D") || validarPalavraChave(pString, "DIVORCIADO") || validarPalavraChave(pString, "DIVORCIADA")) {
		strcpy(pString, "Divorciado(a)");
		return true;
	} else if(validarPalavraChave(pString, "V") || validarPalavraChave(pString, "VIUVO") || validarPalavraChave(pString, "VIUVA")) {
		strcpy(pString, "Viúvo(a)");
		return true;
	}
	
	erro = Erro_Input_EstadoCivil_Invalido;
	return false;
	
}
