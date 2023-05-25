#include "../../../global/global.h"
#include "../../interface.h"

void exibirInterfaceNovaProducao(int posicao) {
	int i, j;
	char posicaoString[3];
	char stringValorProduto[MAX_STRING];
	Display *pDisplayAtual;
	Display copiaDisplay[20];
	Display *pCopiaDisplay = copiaDisplay;
	
	tamanhoDisplay = sizeof(displayRefFormularioNovaOrdem);
	pDisplayAtual = displayRefFormularioNovaOrdem;
	
	tamanhoDisplay /= sizeof(Display);
	//Transforma a posi��o passada pelo usu�rio como int, para string, para conseguir ser exibida ao usu�rio
	sprintf(&posicaoString[0], "%d", posicao+1);
	
	//Copia os formul�rios de Display em uma vari�vel do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
		/*Substitui nas linhas do copiaDisplay, em espa�os espec�ficos, os conte�do presentes no vetor de dados. Como o vetor por padr�o tem o n�mero zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribui��o fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada � atribuido, portanto a linha permanece intacta at� que seja adicionada uma string. */
		 
	for(j = 0; j < strlen(posicaoString); j++) {
		pCopiaDisplay[1].linhaDisplay[12 + j] = posicaoString[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].data); j++) {
		pCopiaDisplay[1].linhaDisplay[31 + j] = producoes[posicao].data[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].numCadCliente); j++) {
		pCopiaDisplay[1].linhaDisplay[64 + j] = producoes[posicao].numCadCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].nomeCliente); j++) {
		pCopiaDisplay[3].linhaDisplay[19 + j] = producoes[posicao].nomeCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].numCadFuncionario); j++) {
		pCopiaDisplay[1].linhaDisplay[96 + j] = producoes[posicao].numCadFuncionario[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].nomeFuncionario); j++) {
		pCopiaDisplay[9].linhaDisplay[31 + j] = producoes[posicao].nomeFuncionario[j];
	}
	
	for(i = 0; i < tamanhoDisplay; i++) {
		printf("%s\n", pCopiaDisplay[i].linhaDisplay);
	}
}
