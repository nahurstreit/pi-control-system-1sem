#include "../../global/global.h"
#include "../menu.h"

void exibirMensagem() {
	char res[50];
	
	switch(mensagem) {
		case Mensagem_Cadastro_Novo:
			strcpy(res, "Sucesso! Cadastro Conclu�do!");
			break;
		case Mensagem_Cadastro_Excluido:
			strcpy(res, "Cadastro Exclu�do!");
			break;
		case Mensagem_Cadastro_Cancelado:
			strcpy(res, "Cadastro Cancelado!");
			break;
		case Mensagem_CampoAlterado:
			strcpy(res, "Sucesso! Campo alterado!");
			break;
		case Mensagem_Producao_Nova:
			strcpy(res, "Sucesso! Nova Ordem de Produ��o gerada!");
			break;
		case Mensagem_Producao_Cancelada:
			strcpy(res, "Ordem de Produ��o Cancelada!");
			break;
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}
