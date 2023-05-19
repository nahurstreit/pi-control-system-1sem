#include "../../global/global.h"
#include "../menu.h"

void receberOpcoesAlteracaoCadastro() {
	int escolhaUserAlterar = 1;
	int *pEscolhaUserAlterar = &escolhaUserAlterar;
	
	while(escolhaUserAlterar == 1 || escolhaUserAlterar == 2 || escolhaUserAlterar == 3) {
		menuAtual = menuModificarCadastro;
		exibirInterfaceOpcoes();
		exibirMensagem();
		scanf("%d", &escolhaUserAlterar);
		fflush(stdin);
		
		switch(escolhaUserAlterar) {
			case 1:
				executarAlterarCadastro();
				break;
			case 2:
				executarExcluirCadastro(2, pEscolhaUserAlterar);
				if(escolhaUserAlterar == 0) {
					exibirMenuNovoCadastro();
					mensagem = 0;
					executarNovoCadastro();
					menuAtual = menuConsultarCadastro;
					executarConsultaCadastro();
				}
				break;
			case 3:
				executarExcluirCadastro(1, pEscolhaUserAlterar);
				if(escolhaUserAlterar == 0) {
					menuAtual = menuConsultarCadastro;
					executarConsultaCadastro();
				}
				break;
			case 0:
				exibirMenuConsultarCadastro();
				break;
			default:
				exibirMenuPrincipal();
		}
	}
}
