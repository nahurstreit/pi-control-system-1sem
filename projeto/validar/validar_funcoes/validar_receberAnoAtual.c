#include "../../global/global.h"
#include "../validar.h"

void receberAnoAtual(char data[]) {
	char diaTempFile[] = "dia_temp.txt";
	static char dataHoje[11];
	int vetorDataHoje[8];
	FILE *pDiaTempFile;
	
	system("echo %date% > dia_temp.txt");
	
	pDiaTempFile = fopen(diaTempFile, "r");
	
	if(pDiaTempFile) {
		fgets(dataHoje, 11, pDiaTempFile);
	} else {
		erro = Erro_Arquivo_ImpossivelLerDataAtual;
		strcpy(dataHoje,"00/00/0000");
	}
	
	fclose(pDiaTempFile);
	remove(diaTempFile);
	
	strcpy(data, dataHoje);
}
