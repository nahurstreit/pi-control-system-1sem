#include "../../global/global.h"
#include "../validar.h"

bool operacoesCPF(int *pVetorIntCpf);

bool validarCPF(char *pCpf) {
	int cpfInt[11];
	int i;
	
    removerCaracteresEspeciais(pCpf, false);
    pCpf[11] = '\0';
    
    if(verificarContemLetras(pCpf)) {
	    erro = Erro_Input_ApenasNumeros;
	    return false;
    }

    if(!verificarQtdDigitos(pCpf, 11)) {
    	erro = Erro_Input_CPF_Invalido;
        return false;
    }

    vetorStringParaInteiro(pCpf, cpfInt, 11);
    vetorInteiroParaString(cpfInt, pCpf, 1);
    
    switch(escolhaUser) {
    	case 1:
		    for(i = 0; i < MAX_VETOR; i++) {
		    	if(strncmp(pCpf, clientes[i].cpf, strlen(pCpf)) == 0) {
		    		erro = Erro_Input_CPF_JaCadastrado;
		    		return false;
				}
			}
    		break;
    	case 2:
	    	for(i = 0; i < MAX_VETOR; i++) {
		    	if(strncmp(pCpf, funcionarios[i].cpf, strlen(pCpf)) == 0) {
		    		erro = Erro_Input_CPF_JaCadastrado;
		    		return false;
				}
			}
    		break;
	}
    

    if(operacoesCPF(cpfInt)) {
        return true;
    } else {
        erro = Erro_Input_CPF_Invalido;
        return false;
    }
}

bool operacoesCPF(int *pCpf) {
    int soma1 = 0, soma2 = 0;
    int i;

    for (i = 0; i < 9; i++) {
        soma1 += pCpf[i] * (10 - i);
    }
    int digito1 = 11 - (soma1 % 11);
    if (digito1 >= 10) {
        digito1 = 0;
    }

    for (i = 0; i < 10; i++) {
        soma2 += pCpf[i] * (11 - i);
    }
    int digito2 = 11 - (soma2 % 11);
    if (digito2 >= 10) {
        digito2 = 0;
    }

    return (digito1 == pCpf[9] && digito2 == pCpf[10]);
} 
