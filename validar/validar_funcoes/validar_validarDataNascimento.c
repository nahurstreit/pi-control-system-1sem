#include "../../global/global.h"
#include "../validar.h"

const int ANO_MAXIMO__NASCIMENTO[4] = {1,9,5,0};
const int ANO_MINIMO__NASCIMENTO[4] = {2,0,0,4};

bool validarDataNascimento(char pString[]) {
	int dataInt[8];
	
	removerCaracteresEspeciais(pString, false);
	pString[8] = '\0';
	
	if(verificarContemLetras(pString)) {
		erro = Erro_Input_ApenasNumeros;
		return false;
	}
	
	if(strlen(pString) == 8) {
		vetorStringParaInteiro(pString, dataInt , 8);
		vetorInteiroParaString(dataInt, pString, 3);
		if(checarAno(dataInt, ANO_MAXIMO__NASCIMENTO, ANO_MINIMO__NASCIMENTO) && checarMes(dataInt) && checarDia(dataInt)) return true;
	}
	
	erro = Erro_Input_DataNascimento_Invalida;
	return false;
}
