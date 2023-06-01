#include "../../../global/global.h"
#include "../../../cadastro/cadastro.h"
#include "../../interface.h"
#include "../../../producao/producao.h"

void imprimirOrdemProducao() {
	int i, j, k;
	char posicaoString[3];
	char stringValorProduto[MAX_STRING];
	
	FILE *pArq_tempImpress;
	
	int numOrdemProducao = producaoAtiva;
	
	pArq_tempImpress = fopen("tempImpress.txt", "w");
	
	popularVetorItens(numOrdemProducao);
	
	int qtdItensComprados = calcularDadosExistentes(vetorRefItensComprados);
	char stringRefItem[6];
	
	Display *pDisplayAtual;
	Display copiaDisplay[25 + qtdItensComprados + 2];
	Display *pCopiaDisplay = copiaDisplay;
	
	tamanhoDisplay = sizeof(displayImpressaoNovaOrdem);
	pDisplayAtual = displayImpressaoNovaOrdem;
	
	tamanhoDisplay /= sizeof(Display);
	
	//Transforma a posição passada pelo usuário como int, para string, para conseguir ser exibida ao usuário
	sprintf(&posicaoString[0], "%d", numOrdemProducao+1);
	
	//Copia os formulários de Display em uma variável do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
	
		/*Substitui nas linhas do copiaDisplay, em espaços específicos, os conteúdo presentes no vetor de dados. Como o vetor por padrão tem o número zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribuição fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada é atribuido, portanto a linha permanece intacta até que seja adicionada uma string. */
		 
	for(j = 0; j < strlen(posicaoString); j++) {
		pCopiaDisplay[3].linhaDisplay[12 + j] = posicaoString[j];
	}
	
	k = 0;
	for(j = 0; j < strlen(producoes[numOrdemProducao].data); j++) {
		if(j == 6 || j == 7) {
			k++;
			continue;
		}
		pCopiaDisplay[3].linhaDisplay[36 + j - k] = producoes[numOrdemProducao].data[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].numCadCliente); j++) {
		pCopiaDisplay[5].linhaDisplay[18 + j] = producoes[numOrdemProducao].numCadCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].nomeCliente); j++) {
		pCopiaDisplay[9].linhaDisplay[8 + j] = producoes[numOrdemProducao].nomeCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].cpfCliente); j++) {
		pCopiaDisplay[11].linhaDisplay[7 + j] = producoes[numOrdemProducao].cpfCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].telefoneCliente); j++) {
		pCopiaDisplay[11].linhaDisplay[40 + j] = producoes[numOrdemProducao].telefoneCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].enderecoCliente); j++) {
		pCopiaDisplay[13].linhaDisplay[12 + j] = producoes[numOrdemProducao].enderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].numEnderecoCliente); j++) {
		pCopiaDisplay[13].linhaDisplay[54 + j] = producoes[numOrdemProducao].numEnderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].compEnderecoCliente); j++) {
		pCopiaDisplay[15].linhaDisplay[8 + j] = producoes[numOrdemProducao].compEnderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].bairroCliente); j++) {
		pCopiaDisplay[15].linhaDisplay[38 + j] = producoes[numOrdemProducao].bairroCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].cepCliente); j++) {
		pCopiaDisplay[17].linhaDisplay[7 + j] = producoes[numOrdemProducao].cepCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].cidadeCliente); j++) {
		pCopiaDisplay[17].linhaDisplay[27 + j] = producoes[numOrdemProducao].cidadeCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].estadoCliente); j++) {
		pCopiaDisplay[17].linhaDisplay[58 + j] = producoes[numOrdemProducao].estadoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].numCadFuncionario); j++) {
		pCopiaDisplay[5].linhaDisplay[50 + j] = producoes[numOrdemProducao].numCadFuncionario[j];
	}
	
	for(j = 0; j < strlen(producoes[numOrdemProducao].nomeFuncionario); j++) {
		pCopiaDisplay[21].linhaDisplay[27 + j] = producoes[numOrdemProducao].nomeFuncionario[j];
	}
	
	//Display do formulário superior
	for(i = 0; i < tamanhoDisplay; i++) {
		fprintf(pArq_tempImpress, "%s\n", pCopiaDisplay[i].linhaDisplay);
	}
	
	
	//Formulário itens
	
	for(i = 0; i < qtdItensComprados; i++) {
		pDisplayAtual = displayImpressaoNovaOrdem_Item;
		
		for(k = 0; k < 2; k++) {
			copiaDisplay[k] = pDisplayAtual[k];
		}
		
		sprintf(stringRefItem, "(%d)", i+1);
		
		for(j = 0; j < strlen(stringRefItem); j++) {
			pCopiaDisplay[0].linhaDisplay[2 + j] = stringRefItem[j];
		}
		
		for(j = 0; j < strlen(producoes[numOrdemProducao].itens[i].nome); j++) {
			pCopiaDisplay[0].linhaDisplay[9 + j] = producoes[numOrdemProducao].itens[i].nome[j];
		}
		
		k = j;
		
		for(j = 0; j < strlen(producoes[numOrdemProducao].itens[i].valorUnit); j++) {
			pCopiaDisplay[0].linhaDisplay[33 + j] = producoes[numOrdemProducao].itens[i].valorUnit[j];
		}
		
		for(j = 0; j < strlen(producoes[numOrdemProducao].itens[i].quantidade); j++) {
			pCopiaDisplay[0].linhaDisplay[45] = producoes[numOrdemProducao].itens[i].quantidade[j];
		}
		
		float valorUnitItemAtual = atof(producoes[numOrdemProducao].itens[i].valorUnit);
		float qtdItemAtual = atof(producoes[numOrdemProducao].itens[i].quantidade);
		char stringValorTotalItemAtual[MAX_STRING];
		
		sprintf(stringValorTotalItemAtual, "%.2f", qtdItemAtual * valorUnitItemAtual);
		
		for(j = 0; j < strlen(stringValorTotalItemAtual); j++) {
			pCopiaDisplay[0].linhaDisplay[52 + j] = stringValorTotalItemAtual[j];
		}
		
		//Display dos itens
		for(k = 0; k < 2; k++) {
			fprintf(pArq_tempImpress, "%s\n", pCopiaDisplay[k].linhaDisplay);
		}
	}
	
	pDisplayAtual = displayImpressaoNovaOrdem_Final;
	
	for(i = 0; i < 2; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
		
	for(j = 0; j < strlen(producoes[numOrdemProducao].valorTotal); j++) {
		pCopiaDisplay[0].linhaDisplay[50 + j] = producoes[numOrdemProducao].valorTotal[j];
	}
	
	for(i = 0; i < 2; i++) {
		fprintf(pArq_tempImpress, "%s\n", pCopiaDisplay[i].linhaDisplay);
	}
	
	fclose(pArq_tempImpress);
	
	system("write tempImpress.txt");
}
