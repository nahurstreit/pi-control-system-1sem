#include "../../global/global.h"
#include "../validar.h"

bool operacoesCNPJ(int *pCnpj);

bool validarCNPJ(char *pCnpj) {
    int cnpjInt[14];
    int i;

    removerCaracteresEspeciais(pCnpj, false);
    pCnpj[14] = '\0';
    
    if(verificarContemLetras(pCnpj)) {
    	erro = Erro_Input_ApenasNumeros;
        return false;
    }

    if(!verificarQtdDigitos(pCnpj, 14)) {
        erro = Erro_Input_CNPJ_Invalido;
        return false;
    }

    vetorStringParaInteiro(pCnpj, cnpjInt, 14);
    vetorInteiroParaString(cnpjInt, pCnpj, 2);
    
    for(i = 0; i < MAX_VETOR; i++) {
    	if(strncmp(pCnpj, fornecedores[i].cnpj, strlen(pCnpj)) == 0) {
    		erro = Erro_Input_CNPJ_JaCadastrado;
    		return false;
		}
	}

    if(operacoesCNPJ(cnpjInt)) {
        return true;
    } 
    
    erro = Erro_Input_CNPJ_Invalido;
    return false;
}

bool operacoesCNPJ(int *pCnpj) {
    int soma1 = 0, soma2 = 0;
    int i;

    // Cálculo do primeiro dígito verificador
    soma1 += pCnpj[0] * 5;
    soma1 += pCnpj[1] * 4;
    soma1 += pCnpj[2] * 3;
    soma1 += pCnpj[3] * 2;
    soma1 += pCnpj[4] * 9;
    soma1 += pCnpj[5] * 8;
    soma1 += pCnpj[6] * 7;
    soma1 += pCnpj[7] * 6;
    soma1 += pCnpj[8] * 5;
    soma1 += pCnpj[9] * 4;
    soma1 += pCnpj[10] * 3;
    soma1 += pCnpj[11] * 2;

    int digito1 = 11 - (soma1 % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    // Cálculo do segundo dígito verificador
    soma2 += pCnpj[0] * 6;
    soma2 += pCnpj[1] * 5;
    soma2 += pCnpj[2] * 4;
    soma2 += pCnpj[3] * 3;
    soma2 += pCnpj[4] * 2;
    soma2 += pCnpj[5] * 9;
    soma2 += pCnpj[6] * 8;
    soma2 += pCnpj[7] * 7;
    soma2 += pCnpj[8] * 6;
    soma2 += pCnpj[9] * 5;
    soma2 += pCnpj[10] * 4;
    soma2 += pCnpj[11] * 3;
    soma2 += pCnpj[12] * 2;

    int digito2 = 11 - (soma2 % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }

    return (digito1 == pCnpj[12] && digito2 == pCnpj[13]);
}
