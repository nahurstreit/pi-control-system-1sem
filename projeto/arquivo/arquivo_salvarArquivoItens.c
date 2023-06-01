#include "../global/global.h"
#include "../cadastro/cadastro.h"
#include "arquivo.h"
#include "../producao/producao.h"

void salvarArquivo_Itens(int numCadCliente, int numOrdemProducao) {
	FILE *pArq_Itens;
    char linha[MAX_STRING * 20];
    
    char stringPasta[40];
	char stringArquivo[40];
	char stringMkDir[40];
    
    sprintf(stringPasta, "data/historico_compras/data_Cliente%d", numCadCliente);
    
    mkdir(stringPasta);
    
    sprintf(stringArquivo, "%s", producoes[numOrdemProducao].arquivoSalvamentoItens);

    pArq_Itens = fopen(stringArquivo, "w");

    if(pArq_Itens == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        erro = Erro_Arquivo_ErroAoLerArquivos;
    }
	
	int contadorDadosExistentes = calcularDadosExistentes(vetorRefItensComprados);
	int i, j;
	
	char stringLinha[MAX_STRING * 11];
	char *pStringLinha = stringLinha;
	
	for(i = 0; i < MAX_VETOR; i++) {
		strcpy(stringLinha, "");
		
		if(contadorDadosExistentes <= 0) break;
		
		if(vetorRefItensComprados[i] == 1) {
			criarLinhaArquivo(pStringLinha, producoes[numOrdemProducao].itens[i].codigoProduto);
			criarLinhaArquivo(pStringLinha, producoes[numOrdemProducao].itens[i].nome);
			criarLinhaArquivo(pStringLinha, producoes[numOrdemProducao].itens[i].quantidade);
			criarLinhaArquivo(pStringLinha, producoes[numOrdemProducao].itens[i].valorUnit);
			strcat(stringLinha, "\n");
			contadorDadosExistentes--;
		} else {
			strcat(stringLinha, "!<>;\n");
		}
		
		fprintf(pArq_Itens, stringLinha);
	}
	
	fclose(pArq_Itens);
}
