#include "../../global/global.h"
#include "../cadastro.h"

int consultarCPFouCNPJ(char string[]) {
	int i, k, res;
	char *pString = string;
	int cpfInt[11];
	int cnpjInt[14];
	
	switch(escolhaUser) {
		case 1: case 5:
			if(!verificarQtdDigitos(string, 11)) {
				erro = Erro_Consulta_NaoExiste;
				return -1;
			}
			vetorStringParaInteiro(pString, cpfInt, 11);
			vetorInteiroParaString(cpfInt, pString, 1);
			for(i = 0; i < MAX_VETOR; i++) {
				if(strncmp(string, clientes[i].cpf, strlen(string)) == 0) {
					return i + 1;
				}
			}
			break;
		case 2:
			if(!verificarQtdDigitos(string, 11)) {
				erro = Erro_Consulta_NaoExiste;
				return -1;
			}
			vetorStringParaInteiro(pString, cpfInt, 11);
			vetorInteiroParaString(cpfInt, pString, 1);
			for(i = 0; i < MAX_VETOR; i++) {
				if(strncmp(string, funcionarios[i].cpf, strlen(string)) == 0) {
					return i + 1;
				}
			}
			break;
		case 3:
			if(!verificarQtdDigitos(string, 14)) {
				erro = Erro_Consulta_NaoExiste;
				return -1;
			}
			vetorStringParaInteiro(pString, cnpjInt, 14);
			vetorInteiroParaString(cnpjInt, pString, 2);
			for(i = 0; i < MAX_VETOR; i++) {
				if(strncmp(string, fornecedores[i].cnpj, strlen(string)) == 0) {
					return i + 1;
				}
			}
			break;
		default:
			erro = Erro_Consulta_NaoPossivel;
	}
	
	erro = Erro_Consulta_NaoExiste;
	return -2;
}
