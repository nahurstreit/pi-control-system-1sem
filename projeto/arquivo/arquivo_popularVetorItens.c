#include "../global/global.h"
#include "../producao/producao.h"
#include "arquivo.h"

void resetarVetorItens();

void popularVetorItens(int numOrdemProducao) {
	FILE *pArq_Itens;
    char linha[MAX_STRING * 20];
    char stringArquivo[40];

    pArq_Itens = fopen(producoes[numOrdemProducao].arquivoSalvamentoItens, "r");

    if(pArq_Itens == NULL) {
        return;
    }
    
    resetarVetorItens();

    int i = 0;
    while (fgets(linha, sizeof(linha), pArq_Itens) != NULL && i < MAX_VETOR) {
        linha[strcspn(linha, "\n")] = '\0';
		
        char *token = strtok(linha, ";");
        
        if(checarLinhaNula(token)) continue;
        
        if (token != NULL) {
        	if(checarCampoNulo_Arquivo(token))token = " ";
            strncpy(producoes[numOrdemProducao].itens[i].codigoProduto, token, MAX_STRING - 1);
            producoes[numOrdemProducao].itens[i].codigoProduto[MAX_STRING - 1] = '\0';
        }

        token = strtok(NULL, ";");

        if (token != NULL) {
        	if(checarCampoNulo_Arquivo(token))token = " ";
            strncpy(producoes[numOrdemProducao].itens[i].nome, token, MAX_STRING - 1);
            producoes[numOrdemProducao].itens[i].nome[MAX_STRING - 1] = '\0';
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
        	if(checarCampoNulo_Arquivo(token))token = " ";
            strncpy(producoes[numOrdemProducao].itens[i].quantidade, token, MAX_STRING - 1);
            producoes[numOrdemProducao].itens[i].quantidade[MAX_STRING - 1] = '\0';
        }
        
        token = strtok(NULL, ";");

        if (token != NULL) {
        	if(checarCampoNulo_Arquivo(token))token = " ";
            strncpy(producoes[numOrdemProducao].itens[i].valorUnit, token, MAX_STRING - 1);
            producoes[numOrdemProducao].itens[i].valorUnit[MAX_STRING - 1] = '\0';
        }
        vetorRefItensComprados[i] = 1;
        i++;
    }
    fclose(pArq_Itens);
}

void resetarVetorItens() {
	int i;
	
	for(i = 0; i < MAX_VETOR; i++) {
		vetorRefItensComprados[i] = 0;
		
		strcpy(producoes[producaoAtiva].itens[i].codigoProduto, "");
		strcpy(producoes[producaoAtiva].itens[i].nome, "");
		strcpy(producoes[producaoAtiva].itens[i].quantidade, "");
		strcpy(producoes[producaoAtiva].itens[i].valorUnit, "");
	}
}
