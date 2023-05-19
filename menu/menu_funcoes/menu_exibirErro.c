#include "../../global/global.h"
#include "../menu.h"

void exibirErro() {
	char res[50];
	switch(erro) {
		case 0:
			break;
		case 1:
			strcpy(res, "Erro: Digite apenas números!");
			break;
		case 2:
			strcpy(res, "Erro: Opção inválida! Digite novamente!");
		break;
		case 3:
			strcpy(res, "Erro: Não foi possível realizar sua consulta!");
			break;
		case 4:
			strcpy(res, "Erro: Não existe nenhum registro para esse Número de Cadastro!");
			break;
		case 5:
			strcpy(res, "Erro: Você ainda não digitou nenhum campo para poder alterar!");
			break;
		case 6:
			strcpy(res, "Erro: Campo inválido!");
			break;
		case 7:
			strcpy(res, "Erro: Você ainda não digitou esse campo!");
			break;
		case 8:
			strcpy(res, "Erro: Você só pode alterar o primeiro campo!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
}
