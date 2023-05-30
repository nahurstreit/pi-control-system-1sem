#include "../../global/global.h"
#include "../menu.h"

void exibirMensagem() {
	char res[50];
	
	switch(mensagem) {
		case Mensagem_Cadastro_Novo:
			strcpy(res, "Sucesso! Cadastro Concluído!");
			break;
		case Mensagem_Cadastro_Excluido:
			strcpy(res, "Cadastro Excluído!");
			break;
		case Mensagem_Cadastro_Cancelado:
			strcpy(res, "Cadastro Cancelado!");
			break;
		case Mensagem_CampoAlterado:
			strcpy(res, "Sucesso! Campo alterado!");
			break;
		case Mensagem_Producao_Nova:
			strcpy(res, "Sucesso! Nova Ordem de Produção gerada!");
			break;
		case Mensagem_Producao_Cancelada:
			strcpy(res, "Ordem de Produção Cancelada!");
			break;
		case Mensagem_Impressao_Concluida:
			strcpy(res, "Processo de impressão concluído! Arquivo de impressão deletado.");
			break;
		case Mensagem_Producao_Item_Excluido:
			strcpy(res, "Item excluído da Ordem de Produção!");
			break;
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}
