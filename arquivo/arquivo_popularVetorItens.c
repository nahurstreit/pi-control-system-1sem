#include "../global/global.h"
#include "arquivo.h"

void resetarVetorItens();

void popularVetorItens(int numCadCliente, int numOrdemProducao) {
	FILE *pArq_Itens;
    char linha[MAX_STRING * 20];
    char stringArquivo[40];
    
    sprintf(stringArquivo, "data/historico_compras/data_Cliente%d/data_Compra%d.txt", numCadCliente, numOrdemProducao);

    pArq_Itens = fopen(stringArquivo, "r");

    if(pArq_Itens == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
    
//    resetarVetorItens();

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Itens) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(!checarLinhaNula(token)) {
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(itensComprados[i].codigoProduto, token, MAX_STRING - 1);
	            itensComprados[i].codigoProduto[MAX_STRING - 1] = '\0';
	        }
	
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(itensComprados[i].nome, token, MAX_STRING - 1);
	            itensComprados[i].nome[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(itensComprados[i].quantidade, token, MAX_STRING - 1);
	            itensComprados[i].quantidade[MAX_STRING - 1] = '\0';
	        }
	        
	        token = strtok(NULL, ";");
	
	        if (token != NULL) {
	        	if(checarCampoNulo_Arquivo(token))token = " ";
	            strncpy(itensComprados[i].valorUnit, token, MAX_STRING - 1);
	            itensComprados[i].valorUnit[MAX_STRING - 1] = '\0';
	        }
	        
	        vetorRefItensComprados[i] = 1;
		}
        i++;
    }
    fclose(pArq_Itens);
}

void resetarVetorItens() {
	int i;
	
	for(i = 0; i < MAX_VETOR; i++) {
		vetorRefItensComprados[i] = 0;
		
		strcpy(itensComprados[i].codigoProduto, "");
		strcpy(itensComprados[i].nome, "");
		strcpy(itensComprados[i].quantidade, "");
		strcpy(itensComprados[i].valorUnit, "");
	}
}
