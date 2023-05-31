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
		case Mensagem_Impressao_Concluida:
			strcpy(res, "Processo de impress�o conclu�do! Arquivo de impress�o deletado.");
			break;
		case Mensagem_Producao_Item_Excluido:
			strcpy(res, "Item exclu�do da Ordem de Produ��o!");
			break;
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}
