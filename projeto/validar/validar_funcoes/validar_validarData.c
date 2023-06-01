#include "../../global/global.h"
#include "../validar.h"

int transformarAno(int vetorAno[]);
int transformarMes(int vetorMes[]);
int transformarDia(int vetorDia[]);
bool checarAno(int dataInt[], int vetorDataInicio[], int vetorDataFim[]);
bool checarMes(int dataInt[], int vetorDataInicio[], int vetorDataFim[], bool impossivelMaiorQueHoje);
bool checarDia(int dataInt[], int vetorDataInicio[], int vetorDataFim[], bool impossivelMaiorQueHoje);
void receberDataIdade(char destino[], bool maximo);

bool validarData(char pString[], char dataInicio[], char dataFim[], bool permitirAtalhos, bool impossivelMaiorQueHoje) {
	int i;
	
	int dataInt[8];
	char stringDataInicio[10];
	int vetorDataInicio[8];
	char stringDataFim[10];
	int vetorDataFim[8];
	
	char dataHoje[11];
	int vetorDataHoje[8];
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
	
	if(strlen(pString) < 4) {
		erro = Erro_Input_Data_Invalida;
		return false;
	}
	
	removerCaracteresEspeciais(dataHoje, false);
	vetorStringParaInteiro(dataHoje, vetorDataHoje, strlen(dataHoje));
	
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
	
	if(impossivelMaiorQueHoje) {
		if(checarAno(vetorDataFim, vetorDataHoje, vetorDataFim)) {
			for(i = 0; i < sizeof(vetorDataHoje) / sizeof(vetorDataHoje[0]); i++) {
				vetorDataFim[i] = vetorDataHoje[i];
			}
		}
	}
	
	if(checarAno(dataInt, vetorDataInicio, vetorDataFim)) {
		if(checarMes(dataInt, vetorDataInicio, vetorDataFim, impossivelMaiorQueHoje)) {
			if(checarDia(dataInt, vetorDataInicio, vetorDataFim, impossivelMaiorQueHoje)) {
				return true;
			}
		}
	}
	
	erro = Erro_Input_Data_Invalida;
	return false;
}

int transformarAno(int vetorAno[8]) {
	char stringVetorAno[4];
	
	sprintf(stringVetorAno, "%d%d%d%d", vetorAno[4], vetorAno[5], vetorAno[6], vetorAno[7]);
	
	return atoi(stringVetorAno);
}

int transformarMes(int vetorMes[]) {
	char stringVetorMes[2];
	
	sprintf(stringVetorMes, "%d%d", vetorMes[2], vetorMes[3]);
	
	return atoi(stringVetorMes);
}

int transformarDia(int vetorDia[]) {
	char stringVetorDia[2];
	
	sprintf(stringVetorDia, "%d%d", vetorDia[0], vetorDia[1]);
	
	return atoi(stringVetorDia);
}

bool checarAno(int dataInt[], int vetorDataInicio[], int vetorDataFim[]) {

	int valid = 0;
	int anoDataInt = transformarAno(dataInt);
	int anoInicio = transformarAno(vetorDataInicio);
	int anoFim = transformarAno(vetorDataFim);
		
	if(anoDataInt >= anoInicio) {
		valid++;
	}
	
	if(anoDataInt <= anoFim) {
		valid++;
	}

	if(valid == 2) return true;
	return false;
}

bool checarMes(int dataInt[], int vetorDataInicio[], int vetorDataFim[], bool impossivelMaiorQueHoje) {
	
	int valid = 0;
	int mesDataInt = transformarMes(dataInt);
	int mesInicio = transformarMes(vetorDataInicio);
	int mesFim = transformarMes(vetorDataFim);
	
	if(mesDataInt <= 12) {
		valid++;
	}
	
	if(mesDataInt >= mesInicio) {
		valid++;
	} else if(!impossivelMaiorQueHoje) {
		valid++;
	}
	
	if(mesDataInt <= mesFim) {
		valid++;
	} else if(!impossivelMaiorQueHoje) {
		valid++;
	}
	
	if(valid == 3) return true;
	return false;
}

bool checarDia(int dataInt[], int vetorDataInicio[], int vetorDataFim[], bool impossivelMaiorQueHoje) {
	int valid = 0;
	
	int mesDataInt = transformarMes(dataInt);
	int diaDataInt = transformarDia(dataInt);
	int diaInicio = transformarDia(vetorDataInicio);
	int diaFim = transformarDia(vetorDataFim);
	
	switch(mesDataInt) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if(diaDataInt <= 31 && diaDataInt > 0) {
				valid++;
			}
			break;
		case 2:
			if(diaDataInt <= 28) {
				valid++;
			}
			break;
		default:
			if(diaDataInt <= 30 && diaDataInt > 0) {
				valid++;
			}
	}
	
	if(diaDataInt >= diaInicio) {
		valid++;
	} else if(!impossivelMaiorQueHoje) {
		valid++;
	}
	
	if(diaDataInt <= diaFim) {
		valid++;
	} else if(!impossivelMaiorQueHoje) {
		valid++;
	}
	
	if(valid == 3) return true;
	return false;
	
}

void receberDataIdade(char destino[], bool maximo) {
	int vetorDataAtual[8];
	char dataAtual[11];
	
	receberAnoAtual(dataAtual);
	removerCaracteresEspeciais(dataAtual, false);
	vetorStringParaInteiro(dataAtual, vetorDataAtual, 8);
	sprintf(dataAtual,"%d%d%d%d", vetorDataAtual[4], vetorDataAtual[5], vetorDataAtual[6], vetorDataAtual[7]);
	
	int anoAtual = atoi(dataAtual);
	
	if(maximo) {
		sprintf(dataAtual, "01/01/%d", anoAtual - IDADE_MAXIMA);
	} else {
		sprintf(dataAtual, "31/12/%d", anoAtual - IDADE_MINIMA);
	}
	
	strcpy(destino, dataAtual);
}
