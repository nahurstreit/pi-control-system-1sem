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
			erro = Erro_OpcaoInvalida; //Assume todos os valores retornando um erro de número inválido até que seja conferido pelo for
			for(i = 0; i < menuAtual.numeroDeOpcoes; i++) { // Laço para percorrer todas as opções do Menu e ver se existe a opção digitada
				if(menuAtual.opcoes[i].numeroDaOpcao == escolhaUser) { //Caso exista alguma opção que o usuário digitou
					erro = 0; //Reatribui o valor do erro
					menuAtual.opcoes[i].funcao(menuAtual); //Executa da função presente no item do menu
					break; //Encerra o for
				}
			}
		}
	} else {
		erro = Erro_Input_ApenasNumeros;
	}
}
