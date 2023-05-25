#ifndef MENU_H
#define MENU_H

#include "../global/global.h"
#include "../cadastro/cadastro.h"
#include "../interface/interface.h"
#include "menu_var/menu_var.h"

//Declaração das funções de chamada das opções
	/**
	 * @brief Funções de chamada das opções do menu
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
	 * @brief Função de fim do menu
	 *
	 * @note Redefine o valor do loopMenu para 0, fazendo com que o programa seja finalizado com sucesso.
	 *
	 * @return int Retorna 0 se a função foi executada com sucesso
	 **/
	extern void fimDoMenu();
	
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
	 * @return Nenhum.
	 **/
	extern void receberOpcaoMenu();
	
	/** 
	 * @brief Exibe uma mensagem de acordo com o código fornecido e chama a função de exibição da interface.
	 * @note Em seguida zera o valor da mensagem para indicar que a mensagem já foi exibida.
	 *
	 * @return Nenhum.
	 **/
	extern void exibirMensagem();


	/**
	 * @brief Exibe uma mensagem de erro de acordo com o código fornecido e chama a função de exibição da interface.
	 * Em seguida zera o valor do erro para indicar que o erro já foi exibido.
	 *
	 * @return Nenhum.
	 */
	extern void exibirErro();
	
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
	extern void receberOpcoesAlteracaoCadastro();
//

#endif
