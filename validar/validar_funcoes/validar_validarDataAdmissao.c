#include "../../global/global.h"
#include "../validar.h"

const int ANO_MAXIMO__ADMISSAO[4] = {2,0,1,8};
const int ANO_MINIMO__ADMISSAO[4] = {2,0,2,3};

bool checarAnoAdmissao(int dataInt[]);

bool validarDataAdmissao(char pString[]) {
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
		if(checarAnoAdmissao(dataInt) && checarMes(dataInt) && checarDia(dataInt)) return true;
	}
	
	erro = Erro_Input_DataAdmissao_Invalida;
	return false;
}

bool checarAnoAdmissao(int dataInt[]) {
	if(dataInt[4] == ANO_MAXIMO__ADMISSAO[0]) {
		if(dataInt[5] == ANO_MAXIMO__ADMISSAO[1]) {
			if(dataInt[6] == ANO_MAXIMO__ADMISSAO[2]) {
				if(dataInt[7] >= ANO_MAXIMO__ADMISSAO[3]) {
					return true;
				}
			} else if(dataInt[6] > ANO_MAXIMO__ADMISSAO[2]) {
				if(dataInt[6] == ANO_MINIMO__ADMISSAO[2]) {
					if(dataInt[7] <= ANO_MINIMO__ADMISSAO[3]){
						return true;
					}
				}
			}
		}
	}
	return false;
}
