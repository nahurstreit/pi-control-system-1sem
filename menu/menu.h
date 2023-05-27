#ifndef MENU_H
#define MENU_H

#include "../global/global.h"
#include "../cadastro/cadastro.h"
#include "../interface/interface.h"
#include "menu_var/menu_var.h"

//Declara��o das fun��es de chamada das op��es
	/**
	 * @brief Fun��es de chamada das op��es do menu
	 * @return Nenhum
	 **/
		extern void exibirMenuPrincipal();
			extern void exibirMenuCadastro();
				extern void exibirMenuNovoCadastro();
					extern void executarNovoCadastro();
					extern void executarNovoProduto();
				extern void exibirMenuConsultarCadastro();
					extern void executarConsultaCadastro();
						extern void executarAlterarCadastro();

			void exibirMenuOrdemProducao();
				void exibirMenuNovaOrdemProducao();
				void exibirMenuConsultarOrdemProducao();			
	//

	/**
	 * @brief Fun��o de fim do menu
	 *
	 * @note Redefine o valor do loopMenu para 0, fazendo com que o programa seja finalizado com sucesso.
	 *
	 * @return int Retorna 0 se a fun��o foi executada com sucesso
	 **/
	extern void fimDoMenu();
	
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
	 * @return Nenhum.
	 **/
	extern void receberOpcaoMenu();
	
	/** 
	 * @brief Exibe uma mensagem de acordo com o c�digo fornecido e chama a fun��o de exibi��o da interface.
	 * @note Em seguida zera o valor da mensagem para indicar que a mensagem j� foi exibida.
	 *
	 * @return Nenhum.
	 **/
	extern void exibirMensagem();


	/**
	 * @brief Exibe uma mensagem de erro de acordo com o c�digo fornecido e chama a fun��o de exibi��o da interface.
	 * Em seguida zera o valor do erro para indicar que o erro j� foi exibido.
	 *
	 * @return Nenhum.
	 */
	extern void exibirErro();
	
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
	extern void receberOpcoesAlteracaoCadastro();
//

#endif
