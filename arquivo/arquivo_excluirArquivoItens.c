#include "../global/global.h"
#include "arquivo.h"

void excluirArquivoItens(int numCadCliente, int numOrdemProducao) {
    char caminhoPasta[MAX_STRING];
    sprintf(caminhoPasta, "data/historico_compras/data_Cliente%d", numCadCliente);

    char nomeArquivo[MAX_STRING];
    sprintf(nomeArquivo, "data_Compra%d.txt", numOrdemProducao + 1);
	
	char caminhoCompleto[100];
	
	sprintf(caminhoCompleto, "%s/%s", caminhoPasta, nomeArquivo);
	remove(caminhoCompleto);
}
