#include "../../global/global.h"
#include "../menu.h"

void receberOpcaoMenu() {
	int i;
	int valid = scanf("%d", &escolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(escolhaUser < 0) {
			erro = Erro_OpcaoInvalida;
		} else {
			erro = Erro_OpcaoInvalida; //Assume todos os valores retornando um erro de n�mero inv�lido at� que seja conferido pelo for
			for(i = 0; i < menuAtual.numeroDeOpcoes; i++) { // La�o para percorrer todas as op��es do Menu e ver se existe a op��o digitada
				if(menuAtual.opcoes[i].numeroDaOpcao == escolhaUser) { //Caso exista alguma op��o que o usu�rio digitou
					erro = 0; //Reatribui o valor do erro
					menuAtual.opcoes[i].funcao(menuAtual); //Executa da fun��o presente no item do menu
					break; //Encerra o for
				}
			}
		}
	} else {
		erro = Erro_Input_ApenasNumeros;
	}
}
