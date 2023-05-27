#include "../../global/global.h"
#include "../validar.h"

bool checarAno1(int dataInt[], int vetorDataInicio[], int vetorDataFim[]);

bool validarData(char pString[], char dataInicio[], char dataFim[], bool permitirAtalhos, bool impossivelMaiorQueHoje) {
	int dataInt[8];
	char stringDataInicio[11];
	int vetorDataInicio[8];
	char stringDataFim[11];
	int vetorDataFim[8];
	bool dataAbreviada;
	
	char dataHoje[11];
	strcpy(stringDataInicio, dataInicio);
	strcpy(stringDataFim, dataFim);
	
	receberAnoAtual(dataHoje);
	
	if(verificarContemLetras(pString) && !permitirAtalhos) {
		erro = Erro_Input_ApenasNumeros;
		return false;
	}
	
	if(validarPalavraChave(pString, "HOJE") || validarPalavraChave(pString, "H")) {
		strcpy(pString, dataHoje);
	}
	
	if(impossivelMaiorQueHoje) {
		if(strncmp(dataFim, dataHoje, 11) != 0);
		strcpy(stringDataFim, dataHoje);
	}
	
	printf("\n\nData hoje: %s, pString: %s, dataInicio: %s, dataFim: %s\n\n", dataHoje, pString, dataInicio, dataFim);
	printf("Até aqui, ok!");
	system("pause");
	
	removerCaracteresEspeciais(pString, false);
	removerCaracteresEspeciais(stringDataInicio, false);
	removerCaracteresEspeciais(stringDataFim, false);
	
	completarDataAbreviada(pString, !impossivelMaiorQueHoje);
	completarDataAbreviada(stringDataInicio, !impossivelMaiorQueHoje);
	completarDataAbreviada(stringDataFim, !impossivelMaiorQueHoje);

	vetorStringParaInteiro(pString, dataInt, strlen(pString));
	vetorStringParaInteiro(stringDataInicio, vetorDataInicio, strlen(stringDataInicio));
	vetorStringParaInteiro(stringDataFim, vetorDataFim, strlen(stringDataFim));
	
	sprintf(pString, "%d%d/%d%d/%d%d%d%d", dataInt[0], dataInt[1], dataInt[2], dataInt[3], dataInt[4], dataInt[5], dataInt[6], dataInt[7]);

	
//	printf("\n\nData hoje: %s, pString: %s, dataInicio: %s, dataFim: %s\n\n", dataHoje, pString, dataInicio, dataFim);

	
	if(!(checarDia(dataInt) && checarMes(dataInt))) {
		Erro_Input_DataAdmissao_Invalida;
		return false;
	}
	
	if(checarAno1(dataInt, vetorDataInicio, vetorDataFim)) return true;
	return false;
}

bool checarAno1(int dataInt[], int vetorDataInicio[], int vetorDataFim[]) {

	int valid = 0;

	if(dataInt[4] >= vetorDataInicio[4]) {
		if(dataInt[5] >= vetorDataInicio[5]) {
			if(dataInt[6] >= vetorDataInicio[6]) {
				if(dataInt[7] >= vetorDataInicio[7]) {
					valid++;
				}
			}
		}
	}
	
	if(dataInt[4] <= vetorDataFim[4]) {
		if(dataInt[5] <= vetorDataFim[5]) {
			if(dataInt[6] <= vetorDataFim[6]) {
				if(dataInt[7] <= vetorDataFim[7]) {
					valid++;
				}
			}
		}
	}
	
	if(valid == 2) return true;
	return false;
}
