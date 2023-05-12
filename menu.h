#ifndef MENU_H
#define MENU_H

#include <windows.h>

//Structs
	/**
	 * @brief Struct que define uma estrutura de menu, contendo um texto, n�mero da op��o e uma fun��o a ser executada.
	 *
	 * @param textoDaOpcao: o texto que ser� exibido para o usu�rio na op��o do menu.
	 * @param numeroDaOpcao: o n�mero que representa a op��o do menu e qual o n�mero que o usu�rio dever� digitar para acessar a op��o.
	 * @param funcao: ponteiro para a fun��o que ser� executada quando a op��o do menu for escolhida.
	 **/
	typedef struct {
		char textoDaOpcao[50];
		int numeroDaOpcao;
		void (*funcao)();
	} OpcaoDoMenu;

	/**
	 * @brief Struct que define uma estrutura de menu, contendo um t�tulo, n�mero de op��es e um array de op��es.
	 * 
	 * @param tituloDoMenu O t�tulo do menu.
	 * @param numeroDeOpcoes O n�mero de op��es no menu.
	 * @param opcoes Um array de OpcaoDoMenu contendo as op��es do menu.
	 **/
	typedef struct {
		char tituloDoMenu[50];
		int numeroDeOpcoes;
		OpcaoDoMenu opcoes[10];
	} Menu;
//

//Declara��o das fun��es de chamada das op��es
	/**
	 * @brief Fun��es de chamada das op��es do menu
	 * @return Nenhum
	 **/
		void exibirMenuPrincipal();
			void exibirMenuCadastro();
				void exibirMenuNovoCadastro();
					void executarNovoCadastro();
				void exibirMenuConsultarCadastro();
					void executarConsultaCadastro();
						void executarAlterarCadastro();
		/** Para uso posterior
			void exibirMenuOrdemProducao();
				void exibirMenuNovaOrdemProducao();
				void exibirMenuConsultarOrdemProducao();
		**/				
	//

	/**
	 * @brief Fun��o de fim do menu
	 *
	 * @note Redefine o valor do loopMenu para 0, fazendo com que o programa seja finalizado com sucesso.
	 *
	 * @param void
	 * @return int Retorna 0 se a fun��o foi executada com sucesso
	 **/
	void fimDoMenu();
	
//

//Declara��o de fun��es de uso
	/**
	 * @brief Recebe a op��o escolhida pelo usu�rio no menu, verifica se o usu�rio digitou um n�mero v�lido e executa a fun��o correspondente. 
	 *
	 * @note Se o usu�rio digitar uma letra retornar� o erro 1, se digitar um n�mero que n�o est� no menu retornar� o erro 2.
	 *
	 * @details A fun��o primeiro recebe a escolha do usu�rio atrav�s da vari�vel apontada por pEscolhaUser. Em seguida, verifica se o valor recebido
	 * � v�lido (maior ou igual a zero). Caso n�o seja, atribui o c�digo de erro 2 � vari�vel apontada por pErro (n�mero inv�lido). Caso seja, percorre
	 * as op��es do menu, verificando se a op��o escolhida pelo usu�rio corresponde a alguma das op��es do menu. Caso encontre uma correspond�ncia, 
	 * atribui o valor 0 � vari�vel apontada por pErro (sem erro) e chama a fun��o correspondente � op��o selecionada, passando como par�metros o ponteiro
	 * para a struct do menu atual e o ponteiro para a vari�vel que armazena o c�digo de erro. Caso n�o encontre nenhuma correspond�ncia, mant�m o valor
	 * atribu�do � vari�vel apontada por pErro como 2.
	 *	
	 * @param pEscolhaUser: ponteiro para inteiro que armazena a op��o escolhida pelo usu�rio a ser acessada por v�rias fun��es.
	 * @param pErro: ponteiro para inteiro que armazena o c�digo do erro.
	 * @param pMenuAtual: ponteiro para a estrutura Menu que cont�m as op��es do menu atual.
	 *
	 * @return Nenhum.
	 **/
	void receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual);
	
	/** 
	 * @brief Exibe uma mensagem de acordo com o c�digo fornecido e chama a fun��o de exibi��o da interface.
	 * @note Em seguida zera o valor da mensagem para indicar que a mensagem j� foi exibida.
	 *
	 * @param pMensagem: Ponteiro para o c�digo da mensagem a ser exibida.
	 *        Valores poss�veis: 1 - Sucesso! Cadastro Conclu�do!
	 *                            2 - Sucesso! Campo alterado!
	 *                            3 - Cadastro Exclu�do!
	 *                            (nenhum valor para mensagem vazia)
	 * @return Nenhum.
	 **/
	void exibirMensagem(int *pMensagem);


	/**
	 * @brief Exibe uma mensagem de erro de acordo com o c�digo fornecido e chama a fun��o de exibi��o da interface.
	 * Em seguida zera o valor do erro para indicar que o erro j� foi exibido.
	 *
	 * @param pErro Ponteiro para o c�digo do erro a ser exibido.
	 *        Valores poss�veis: 0 - sem erro
	 *                            1 - Erro: Digite apenas n�meros!
	 *                            2 - Erro: Op��o inv�lida! Digite novamente!
	 *                            3 - Erro: N�o foi poss�vel realizar sua consulta!
	 *                            4 - Erro: N�o existe nenhum registro para esse N�mero de Cadastro!
	 *                            (nenhum valor para mensagem vazia)
	 * @return Nenhum.
	 */
	void exibirErro(int *pErro);
	
	/**
	 * @brief Fun��o que recebe as op��es do usu�rio na tela de modificar cadastro e executa as a��es correspondentes. 
	 * @remark Essa fun��o precisou ser separada da fun��o habitual de receberOpcaoMenu() por ser uma situa��o que exige mostrar os dados do usu�rio e em 
	 * seguida mostrar as op��es. Na fase de testes, ficou muito dif�cil de conciliar apenas essa parte do menu com essa funcionalidade de exibi��o 
	 * enquanto as outras partes (que s�o a maioria) n�o exigiam que os dados do usu�rio fossem mostrados o tempo inteiro. 
	 * Para tanto, como o comportamento dessa se��o do menu, de modificar os aspectos de um cadastro, exigia desses displays espec�ficos e intera��es 
	 * diferentes, optou-se por usar um m�todo de recebimento de op��es diferentes do m�todo padr�o do menu inteiro, com receberOpcaoMenu()
	 *
	 *
	 * @details A fun��o utiliza um ponteiro para inteiro para controlar a escolha do usu�rio (escolhaUserMod e pEscolhaUserMod) e um ponteiro para a struct Menu
	 * para definir qual o menu atual. A fun��o exibe a interface de op��es e, em seguida, executa as a��es de acordo com a escolha do usu�rio.
	 *
	 * Solu��es:
	 * - Caso a escolha do usu�rio seja [1] executa a fun��o executarAlterarCadastro();
	 * - Caso a escolha seja: [2] (Alterar todo o Cadastro) ou [3] (Excluir Cadastro):
	 *		ambas op��es chamam primeiro a executarExcluirCadastro(), para excluir o cadastro e, em seguida, se a escolha for [2], chama a fun��o
	 * 		de executarNovoCadastro() e se a escolha for [3] executarConsultaCadastro().
	 *		Como essas duas op��es excluem todos os dados e depois fazem coisas diferentes, ambas chamam a fun��o de excluir primeiro e depois
	 * 		diferem na sequ�ncia de a��es. 
	 *		Quando o usu�rio quiser recadastrar, primeiro exclui o dado e executa a fun��o de executarNovoCadastro(pMenuAtual, pErro) e depois volta
	 *		para a consulta de cadastros. 
	 *		Quando o usu�rio quer apenas excluir, o dado � exclu�do e o usu�rio volta para a tela de sele��o, atrav�s da fun��o executarConsultaCadastro(pMenuAtual, pErro).
	 * - Caso a escolha seja [0], a fun��o exibe o menu de consultar cadastro;
	 * - Caso contr�rio, se digitar 9 ou qualquer outra coisa, a fun��o exibe o menu principal.
	 * @return void
	 */
	void receberOpcoesAlteracaoCadastro();
//

#endif
