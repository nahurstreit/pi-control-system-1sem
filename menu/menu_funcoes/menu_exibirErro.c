#include "../../global/global.h"
#include "../menu.h"

void exibirErro() {
	char res[50];
	switch(erro) {
		case 0:
			break;
		case 1:
			strcpy(res, "Erro: Digite apenas n�meros!");
			break;
		case 2:
			strcpy(res, "Erro: Op��o inv�lida! Digite novamente!");
		break;
		case 3:
			strcpy(res, "Erro: N�o foi poss�vel realizar sua consulta!");
			break;
		case 4:
			strcpy(res, "Erro: N�o existe nenhum registro para esse N�mero de Cadastro!");
			break;
		case 5:
			strcpy(res, "Erro: Voc� ainda n�o digitou nenhum campo para poder alterar!");
			break;
		case 6:
			strcpy(res, "Erro: Campo inv�lido!");
			break;
		case 7:
			strcpy(res, "Erro: Voc� ainda n�o digitou esse campo!");
			break;
		case 8:
			strcpy(res, "Erro: Voc� s� pode alterar o primeiro campo!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
}
