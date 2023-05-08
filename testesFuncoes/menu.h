#ifndef MENU_H
#define MENU_H

//Definição do tipo OpcaoDoMenu
typedef struct {
	char textoDaOpcao[50];
	int numeroDaOpcao;
	int (*funcao)();
} OpcaoDoMenu;

//Definição do tipo Menu
typedef struct {
	char tituloDoMenu[50];
	int numeroDeOpcoes;
	OpcaoDoMenu opcoes[10];
} Menu;

//Declaração das funções de chamada das opções
	//Opções do Menu
		int exibirMenuPrincipal();
			int exibirMenuCadastro();
				int exibirMenuNovoCadastro();
					int executarNovoCadastro();
				int exibirMenuConsultarCadastro();
					int executarConsultaCadastro();
						int executarAlterarCadastro();
			
			int exibirMenuOrdemProducao();
				int exibirMenuNovaOrdemProducao();
				int exibirMenuConsultarOrdemProducao();
	//

	//Função de fim do Menu
		int fimDoMenu();
	//
//

//Declaração de funções de uso
	//Usada para receber o input do usuário e retornar erro caso seja digitado uma letra, ou um número que não tem no menu
	int receberOpcaoMenu(int *pEscolhaUser, int *pErr, Menu *pMenuAtual);
	
	void receberOpcoesDeCadastro();
	
	//Exibe uma mensagem caso seja passada como parâmetro
	void exibirMensagem(int *pMensagem);
	
	//Exibe uma mensagem de erro de acordo com o erro passado
	void exibirErro(int *pErr);
	
	//Exibe o título do Menu Atual com caracteres # do lado direito e lado esquerdo, para ficar mais bonito
	void exibirTituloMenuAtual(Menu *pMenuAtual);

	//Exibe as opções disponíveis no Menu Atual
	void exibirOpcoesMenuAtual(Menu *pMenuAtual);

//

#endif
