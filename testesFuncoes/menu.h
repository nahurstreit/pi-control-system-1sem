#ifndef MENU_H
#define MENU_H

//Defini��o do tipo OpcaoDoMenu
typedef struct {
	char textoDaOpcao[50];
	int numeroDaOpcao;
	int (*funcao)();
} OpcaoDoMenu;

//Defini��o do tipo Menu
typedef struct {
	char tituloDoMenu[50];
	int numeroDeOpcoes;
	OpcaoDoMenu opcoes[10];
} Menu;

//Declara��o das fun��es de chamada das op��es
	//Op��es do Menu
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

	//Fun��o de fim do Menu
		int fimDoMenu();
	//
//

//Declara��o de fun��es de uso
	//Usada para receber o input do usu�rio e retornar erro caso seja digitado uma letra, ou um n�mero que n�o tem no menu
	int receberOpcaoMenu(int *pEscolhaUser, int *pErr, Menu *pMenuAtual);
	
	void receberOpcoesDeCadastro();
	
	//Exibe uma mensagem caso seja passada como par�metro
	void exibirMensagem(int *pMensagem);
	
	//Exibe uma mensagem de erro de acordo com o erro passado
	void exibirErro(int *pErr);
	
	//Exibe o t�tulo do Menu Atual com caracteres # do lado direito e lado esquerdo, para ficar mais bonito
	void exibirTituloMenuAtual(Menu *pMenuAtual);

	//Exibe as op��es dispon�veis no Menu Atual
	void exibirOpcoesMenuAtual(Menu *pMenuAtual);

//

#endif
