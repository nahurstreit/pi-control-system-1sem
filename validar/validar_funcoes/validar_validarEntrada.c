#include "../../global/global.h"
#include "../validar.h"

bool validarEntrada(char *pString, bool removerCaracteres, bool permitirNumeros, bool permitirLetras, int tamanhoMaximoString) {
    
	if(removerCaracteres) removerCaracteresEspeciais(pString, true);
	
	pString[tamanhoMaximoString + 1] = '\0';
    
    if(!permitirNumeros) {
    	if(verificarContemNumeros(pString)) {
    		erro = Erro_Input_ApenasLetras;
    		return false;
		}
	}
	
	if(!permitirLetras) {
		if(verificarContemLetras(pString)) {
		    erro = Erro_Input_ApenasNumeros;
		    return false;
    	}
	}
	
	return true;
}

