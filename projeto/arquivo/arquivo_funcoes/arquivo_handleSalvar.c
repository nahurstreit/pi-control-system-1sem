#include "../../global/global.h"
#include "../arquivo.h"

void handleSalvar(int caso) {
	switch(caso) {
		case 1:
			salvarArquivo_Clientes();
			break;
		case 2:
			salvarArquivo_Funcionarios();
			break;
		case 3:
			salvarArquivo_Fornecedores();
			break;
		case 4:
			salvarArquivo_Produtos();
			break;
		case 5:
			salvarArquivo_Producoes();
			break;
		default:
			erro = Erro_Arquivo_ErroAoLerArquivos;
	}
}
