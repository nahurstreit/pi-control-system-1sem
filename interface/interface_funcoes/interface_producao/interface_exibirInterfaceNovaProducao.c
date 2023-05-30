#include "../../../global/global.h"
#include "../../../cadastro/cadastro.h"
#include "../../interface.h"

void exibirInterfaceNovaProducao(int posicao) {
	int i, j, k;
	char posicaoString[3];
	char stringValorProduto[MAX_STRING];
	
	int qtdItensComprados = calcularDadosExistentes(vetorRefItensComprados);
	char stringRefItem[6];
	
	char stringValorTotalItemAtual[10];
	float qtdItemAtual;
	float valorUnitItemAtual;
	
	float valorTotalFinal = 0.0;
	
	Display *pDisplayAtual;
	Display copiaDisplay[21 + qtdItensComprados + 3];
	Display *pCopiaDisplay = copiaDisplay;
	
	tamanhoDisplay = sizeof(displayRefFormularioNovaOrdem);
	pDisplayAtual = displayRefFormularioNovaOrdem;
	
	tamanhoDisplay /= sizeof(Display);
	
	//Transforma a posição passada pelo usuário como int, para string, para conseguir ser exibida ao usuário
	sprintf(&posicaoString[0], "%d", posicao+1);
	
	//Copia os formulários de Display em uma variável do tipo Display chamada copiaDisplay.
	for(i = 0; i < tamanhoDisplay; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
	
		/*Substitui nas linhas do copiaDisplay, em espaços específicos, os conteúdo presentes no vetor de dados. Como o vetor por padrão tem o número zero em todos os campos,
		 ao tentar imprimir nas linhas um tipo char, o resultado da atribuição fica como null. Dessa forma, por mais que, se acessados, os dados do vetor de dados for 0, 
		 nada é atribuido, portanto a linha permanece intacta até que seja adicionada uma string. */
		 
	for(j = 0; j < strlen(posicaoString); j++) {
		pCopiaDisplay[1].linhaDisplay[12 + j] = posicaoString[j];
	}
	
	k = 0;
	for(j = 0; j < strlen(producoes[posicao].data); j++) {
		if(j == 6 || j == 7) {
			k++;
			continue;
		}
		pCopiaDisplay[1].linhaDisplay[31 + j - k] = producoes[posicao].data[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].numCadCliente); j++) {
		pCopiaDisplay[1].linhaDisplay[64 + j] = producoes[posicao].numCadCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].nomeCliente); j++) {
		pCopiaDisplay[5].linhaDisplay[19 + j] = producoes[posicao].nomeCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].cpfCliente); j++) {
		pCopiaDisplay[7].linhaDisplay[7 + j] = producoes[posicao].cpfCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].telefoneCliente); j++) {
		pCopiaDisplay[7].linhaDisplay[56 + j] = producoes[posicao].telefoneCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].enderecoCliente); j++) {
		pCopiaDisplay[9].linhaDisplay[12 + j] = producoes[posicao].enderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].numEnderecoCliente); j++) {
		pCopiaDisplay[9].linhaDisplay[89 + j] = producoes[posicao].numEnderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].compEnderecoCliente); j++) {
		pCopiaDisplay[11].linhaDisplay[15 + j] = producoes[posicao].compEnderecoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].bairroCliente); j++) {
		pCopiaDisplay[11].linhaDisplay[56 + j] = producoes[posicao].bairroCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].cepCliente); j++) {
		pCopiaDisplay[13].linhaDisplay[7 + j] = producoes[posicao].cepCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].cidadeCliente); j++) {
		pCopiaDisplay[13].linhaDisplay[38 + j] = producoes[posicao].cidadeCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].estadoCliente); j++) {
		pCopiaDisplay[13].linhaDisplay[89 + j] = producoes[posicao].estadoCliente[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].numCadFuncionario); j++) {
		pCopiaDisplay[1].linhaDisplay[96 + j] = producoes[posicao].numCadFuncionario[j];
	}
	
	for(j = 0; j < strlen(producoes[posicao].nomeFuncionario); j++) {
		pCopiaDisplay[17].linhaDisplay[27 + j] = producoes[posicao].nomeFuncionario[j];
	}
	
	//Display do formulário superior
	for(i = 0; i < tamanhoDisplay; i++) {
		printf("%s\n", pCopiaDisplay[i].linhaDisplay);
	}
	
	
	//Formulário itens
	
	for(i = 0; i < qtdItensComprados; i++) {
		if(vetorRefItensComprados[i] == 1) {
			pDisplayAtual = displayRefFormularioNovaOrdem_Item;
			
			for(k = 0; k < 2; k++) {
				copiaDisplay[k] = pDisplayAtual[k];
			}
			
			sprintf(stringRefItem, "(%d)", i+1);
			
			for(j = 0; j < strlen(stringRefItem); j++) {
				pCopiaDisplay[0].linhaDisplay[4 + j] = stringRefItem[j];
			}
			
			for(j = 0; j < strlen(producoes[posicao].itens[i].nome); j++) {
				pCopiaDisplay[0].linhaDisplay[13 + j] = producoes[posicao].itens[i].nome[j];
			}
			
			k = j;
			
			for(j = 0; j < strlen(producoes[posicao].itens[i].valorUnit); j++) {
				pCopiaDisplay[0].linhaDisplay[56 + j] = producoes[posicao].itens[i].valorUnit[j];
			}
			
			for(j = 0; j < strlen(producoes[posicao].itens[i].quantidade); j++) {
				pCopiaDisplay[0].linhaDisplay[77] = producoes[posicao].itens[i].quantidade[j];
			}
			
			valorUnitItemAtual = atof(producoes[posicao].itens[i].valorUnit);
			qtdItemAtual = atof(producoes[posicao].itens[i].quantidade);
			
			valorTotalFinal += qtdItemAtual * valorUnitItemAtual;
			
			sprintf(stringValorTotalItemAtual, "%.2f", qtdItemAtual * valorUnitItemAtual);
			
			for(j = 0; j < strlen(stringValorTotalItemAtual); j++) {
				pCopiaDisplay[0].linhaDisplay[90 + j] = stringValorTotalItemAtual[j];
			}
			
			//Display dos itens
			for(k = 0; k < 2; k++) {
				printf("%s\n", pCopiaDisplay[k].linhaDisplay);
			}
		}
	}
	
	pDisplayAtual = displayRefFormularioNovaOrdem_Final;
	
	for(i = 0; i < 2; i++) {
		copiaDisplay[i] = pDisplayAtual[i];
	}
	
	sprintf(stringValorTotalItemAtual, "%.2f", valorTotalFinal);
		
	for(j = 0; j < strlen(stringValorTotalItemAtual); j++) {
		pCopiaDisplay[0].linhaDisplay[86 + j] = stringValorTotalItemAtual[j];
	}
	
	for(i = 0; i < 2; i++) {
		printf("%s\n", pCopiaDisplay[i].linhaDisplay);
	}
	
}
