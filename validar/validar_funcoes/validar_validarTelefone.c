#include "../../global/global.h"
#include "../validar.h"

bool validarTelefone(char *pString) {
	int telInt1[11];
	int telInt2[12];
	
	removerCaracteresEspeciais(pString, false);
	
	if(verificarContemLetras(pString)) {
		erro = Erro_Input_ApenasNumeros;
		return false;
	}
	
	if(verificarQtdDigitos(pString, 10) || verificarQtdDigitos(pString, 11)) {
		if(verificarQtdDigitos(pString, 10)) {
			vetorStringParaInteiro(pString, telInt1, 10);
			vetorInteiroParaString(telInt1, pString, 4);
		} else {
			vetorStringParaInteiro(pString, telInt2, 11);
			vetorInteiroParaString(telInt2, pString, 5);
		}
		return true;
	}
	
	erro = Erro_Input_Telefone_Invalido;
	return false;
}
