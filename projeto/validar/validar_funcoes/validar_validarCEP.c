#include "../../global/global.h"
#include "../validar.h"

bool validarCEP(char *pString) {
	int cepInt[8];
	
	removerCaracteresEspeciais(pString, false);
	
	if(verificarContemLetras(pString)) {
	    erro = Erro_Input_ApenasNumeros;
	    return false;
    }
	
	if(verificarQtdDigitos(pString, 8)) {
		vetorStringParaInteiro(pString, cepInt, 8);
		vetorInteiroParaString(cepInt, pString, 6);
		return true;
	}
	
	erro = Erro_Input_CEP_Invalido;
	return false;
}
