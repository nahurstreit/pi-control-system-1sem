#ifndef MENU_H
#define MENU_H

#include <windows.h>

//Structs
	/**
	 * @brief Struct que define uma estrutura de menu, contendo um texto, número da opção e uma função a ser executada.
	 *
	 * @param textoDaOpcao: o texto que será exibido para o usuário na opção do menu.
	 * @param numeroDaOpcao: o número que representa a opção do menu e qual o número que o usuário deverá digitar para acessar a opção.
	 * @param funcao: ponteiro para a função que será executada quando a opção do menu for escolhida.
	 **/
	typedef struct {
		char textoDaOpcao[50];
		int numeroDaOpcao;
		void (*funcao)();
	} OpcaoDoMenu;

	/**
	 * @brief Struct que define uma estrutura de menu, contendo um título, número de opções e um array de opções.
	 * 
	 * @param tituloDoMenu O título do menu.
	 * @param numeroDeOpcoes O número de opções no menu.
	 * @param opcoes Um array de OpcaoDoMenu contendo as opções do menu.
	 **/
	typedef struct {
		char tituloDoMenu[50];
		int numeroDeOpcoes;
		OpcaoDoMenu opcoes[10];
	} Menu;
//

//Declaração das funções de chamada das opções
	/**
	 * @brief Funções de chamada das opções do menu
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
	 * @brief Função de fim do menu
	 *
	 * @note Redefine o valor do loopMenu para 0, fazendo com que o programa seja finalizado com sucesso.
	 *
	 * @param void
	 * @return int Retorna 0 se a função foi executada com sucesso
	 **/
	void fimDoMenu();
	
//

//Declaração de funções de uso
	/**
	 * @brief Recebe a opção escolhida pelo usuário no menu, verifica se o usuário digitou um número válido e executa a função correspondente. 
	 *
	 * @note Se o usuário digitar uma letra retornará o erro 1, se digitar um número que não está no menu retornará o erro 2.
	 *
	 * @details A função primeiro recebe a escolha do usuário através da variável apontada por pEscolhaUser. Em seguida, verifica se o valor recebido
	 * é válido (maior ou igual a zero). Caso não seja, atribui o código de erro 2 à variável apontada por pErro (número inválido). Caso seja, percorre
	 * as opções do menu, verificando se a opção escolhida pelo usuário corresponde a alguma das opções do menu. Caso encontre uma correspondência, 
	 * atribui o valor 0 à variável apontada por pErro (sem erro) e chama a função correspondente à opção selecionada, passando como parâmetros o ponteiro
	 * para a struct do menu atual e o ponteiro para a variável que armazena o código de erro. Caso não encontre nenhuma correspondência, mantém o valor
	 * atribuído à variável apontada por pErro como 2.
	 *	
	 * @param pEscolhaUser: ponteiro para inteiro que armazena a opção escolhida pelo usuário a ser acessada por várias funções.
	 * @param pErro: ponteiro para inteiro que armazena o código do erro.
	 * @param pMenuAtual: ponteiro para a estrutura Menu que contém as opções do menu atual.
	 *
	 * @return Nenhum.
	 **/
	void receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual);
	
	/** 
	 * @brief Exibe uma mensagem de acordo com o código fornecido e chama a função de exibição da interface.
	 * @note Em seguida zera o valor da mensagem para indicar que a mensagem já foi exibida.
	 *
	 * @param pMensagem: Ponteiro para o código da mensagem a ser exibida.
	 *        Valores possíveis: 1 - Sucesso! Cadastro Concluído!
	 *                            2 - Sucesso! Campo alterado!
	 *                            3 - Cadastro Excluído!
	 *                            (nenhum valor para mensagem vazia)
	 * @return Nenhum.
	 **/
	void exibirMensagem(int *pMensagem);


	/**
	 * @brief Exibe uma mensagem de erro de acordo com o código fornecido e chama a função de exibição da interface.
	 * Em seguida zera o valor do erro para indicar que o erro já foi exibido.
	 *
	 * @param pErro Ponteiro para o código do erro a ser exibido.
	 *        Valores possíveis: 0 - sem erro
	 *                            1 - Erro: Digite apenas números!
	 *                            2 - Erro: Opção inválida! Digite novamente!
	 *                            3 - Erro: Não foi possível realizar sua consulta!
	 *                            4 - Erro: Não existe nenhum registro para esse Número de Cadastro!
	 *                            (nenhum valor para mensagem vazia)
	 * @return Nenhum.
	 */
	void exibirErro(int *pErro);
	
	/**
	 * @brief Função que recebe as opções do usuário na tela de modificar cadastro e executa as ações correspondentes. 
	 * @remark Essa função precisou ser separada da função habitual de receberOpcaoMenu() por ser uma situação que exige mostrar os dados do usuário e em 
	 * seguida mostrar as opções. Na fase de testes, ficou muito difícil de conciliar apenas essa parte do menu com essa funcionalidade de exibição 
	 * enquanto as outras partes (que são a maioria) não exigiam que os dados do usuário fossem mostrados o tempo inteiro. 
	 * Para tanto, como o comportamento dessa seção do menu, de modificar os aspectos de um cadastro, exigia desses displays específicos e interações 
	 * diferentes, optou-se por usar um método de recebimento de opções diferentes do método padrão do menu inteiro, com receberOpcaoMenu()
	 *
	 *
	 * @details A função utiliza um ponteiro para inteiro para controlar a escolha do usuário (escolhaUserMod e pEscolhaUserMod) e um ponteiro para a struct Menu
	 * para definir qual o menu atual. A função exibe a interface de opções e, em seguida, executa as ações de acordo com a escolha do usuário.
	 *
	 * Soluções:
	 * - Caso a escolha do usuário seja [1] executa a função executarAlterarCadastro();
	 * - Caso a escolha seja: [2] (Alterar todo o Cadastro) ou [3] (Excluir Cadastro):
	 *		ambas opções chamam primeiro a executarExcluirCadastro(), para excluir o cadastro e, em seguida, se a escolha for [2], chama a função
	 * 		de executarNovoCadastro() e se a escolha for [3] executarConsultaCadastro().
	 *		Como essas duas opções excluem todos os dados e depois fazem coisas diferentes, ambas chamam a função de excluir primeiro e depois
	 * 		diferem na sequência de ações. 
	 *		Quando o usuário quiser recadastrar, primeiro exclui o dado e executa a função de executarNovoCadastro(pMenuAtual, pErro) e depois volta
	 *		para a consulta de cadastros. 
	 *		Quando o usuário quer apenas excluir, o dado é excluído e o usuário volta para a tela de seleção, através da função executarConsultaCadastro(pMenuAtual, pErro).
	 * - Caso a escolha seja [0], a função exibe o menu de consultar cadastro;
	 * - Caso contrário, se digitar 9 ou qualquer outra coisa, a função exibe o menu principal.
	 * @return void
	 */
	void receberOpcoesAlteracaoCadastro();
//

#endif
