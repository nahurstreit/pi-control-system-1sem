#include "../../global/global.h"
#include "../producao.h"

void excluirProducao(int numProd) {
	vetorRefProducoes[numProd] = 0;
	strcpy(producoes[numProd].data, "");
	strcpy(producoes[numProd].numCadCliente, "");
	strcpy(producoes[numProd].nomeCliente, "");
	strcpy(producoes[numProd].cpfCliente, "");
	strcpy(producoes[numProd].telefoneCliente, "");
	strcpy(producoes[numProd].enderecoCliente, "");
	strcpy(producoes[numProd].numEnderecoCliente, "");
	strcpy(producoes[numProd].compEnderecoCliente, "");
	strcpy(producoes[numProd].cepCliente, "");
	strcpy(producoes[numProd].bairroCliente, "");
	strcpy(producoes[numProd].cidadeCliente, "");
	strcpy(producoes[numProd].estadoCliente, "");
	strcpy(producoes[numProd].numCadFuncionario, "");
	strcpy(producoes[numProd].nomeFuncionario, "");
	strcpy(producoes[numProd].valorTotal, "");
	strcpy(producoes[numProd].arquivoSalvamentoItens, "");
	salvarArquivo_Producoes();
}
