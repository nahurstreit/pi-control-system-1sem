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
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}
