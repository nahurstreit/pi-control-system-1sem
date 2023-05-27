#include "../../global/global.h"
#include "../validar.h"

void completarDataAbreviada(char data[], bool permiteDataFutura) {
	char dataChecar[11];
	int i;
	
	int vetorData[8];
	char dataAtual[11];
	int vetorDataAtual[11];
	char anoComp[2] = "20";
	
	removerCaracteresEspeciais(data, false);
	vetorStringParaInteiro(data, vetorData, sizeof(data));
	
	if(strlen(data) == 4) {
		strcpy(dataChecar, "01/01/");
		strcat(dataChecar, data);
	} else if(strlen(data) < 8) {
		
		receberAnoAtual(dataAtual);
		removerCaracteresEspeciais(dataAtual, false);
		vetorStringParaInteiro(dataAtual, vetorDataAtual, 11);
		if(vetorData[4] > vetorDataAtual[6]) strcpy(anoComp, "19");
		else if(vetorData[5] > vetorDataAtual[7] && permiteDataFutura) strcpy(anoComp, "19");
		sprintf(dataChecar, "%c%c/%c%c/%c%c%c%c", data[0], data[1], data[2], data[3], anoComp[0], anoComp[1], data[4], data[5]);
	} else {
		sprintf(dataChecar, "%c%c/%c%c/%c%c%c%c", data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7]);
	}
	
	strcpy(data, dataChecar);
	
}
