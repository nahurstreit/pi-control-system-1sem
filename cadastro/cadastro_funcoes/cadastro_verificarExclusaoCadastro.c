#include "../../global/global.h"
#include "../cadastro.h"

bool verificarExclusaoCadastro() {
	switch(tipoConsultaAtual) {
		case 1:
			if(vetorRefClientes[posicaoConsultaAtual] == 0) return true;
			break;
		case 2:
			if(vetorRefFuncionarios[posicaoConsultaAtual] == 0) return true;
			break;
		case 3:
			if(vetorRefFornecedores[posicaoConsultaAtual] == 0) return true;
			break;
		case 4:
			if(vetorRefProdutos[posicaoConsultaAtual] == 0) return true;
			break;
	}
	
	return false;
}
