#include "../../global/global.h"
#include "../menu.h"

void exibirMensagem() {
	char res[50];
	
	switch(mensagem) {
		case 1:
			strcpy(res, "Sucesso! Cadastro Conclu�do!");
			break;
		case 2:
			strcpy(res, "Sucesso! Campo alterado!");
			break;
		case 3:
			strcpy(res, "Cadastro Exclu�do!");
			break;
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}
