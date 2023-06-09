#include "menu_var.h"

//Cria��o dos Menus
/* A cria��o dos Menus segue a seguinte estrutura:

	Menu nomeDoMenu = {
		"tituloDoMenu", [String]
		numeroDeOp��esDesseMenu, [Int]
		{ //Inicializa��o das op��es do Menu
			{"Texto da op��o", numeroDaOp��o, &fun��oASerExecutada}, [String, Int, Function]
			...
			...
			{"Texto da op��o", numeroDaOp��o, &fun��oASerExecutada}, [String, Int, Function]
		}
	};
	
*/
	//menuPrincipal
		Menu menuPrincipal = {
			"MENU",
			3,
			{
				{"Cadastros", 1, &exibirMenuCadastro},
				{"Ordem de Produ��o", 2, &exibirMenuOrdemProducao},
				{"Sair", 0, &fimDoMenu},
			}
		};
	//
	
	//menuCadastros 
		Menu menuCadastro = {
			"CADASTROS",
			3,
			{
				{"Criar novo Cadastro", 1, &exibirMenuNovoCadastro},
				{"Consultar e Modificar Cadastros", 2, &exibirMenuConsultarCadastro},
				{"Voltar ao Menu Inicial", 0, &exibirMenuPrincipal},
			}
		};
		
			//Criar novo Cadastro
				Menu menuNovoCadastro = {
					"NOVO CADASTRO",
					5,
					{
						"Clientes", 1, &executarNovoCadastro,
						"Funcion�rios", 2, &executarNovoCadastro,
//						"Fornecedores", 3, &executarNovoCadastro,
						"Produtos", 3, &executarNovoCadastro,
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
			//
			
			//Consultar Cadastros
				Menu menuConsultarCadastro = {
					"CONSULTAR E MODIFICAR CADASTROS",
					5,
					{
						"Clientes", 1, &executarConsultaCadastro,
						"Funcion�rios", 2, & executarConsultaCadastro,
//						"Fornecedores", 3, &executarConsultaCadastro,
						"Produtos", 3, &executarConsultaCadastro,
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
				
				//Menu de modifica��es do cadastro
					Menu menuModificarCadastro = {
						"CONSULTAR E MODIFICAR CADASTROS",
						5,
						{
							"Alterar Campo Espec�fico do Cadastro", 1, &executarAlterarCadastro,
							"Alterar Todo o Cadastro", 2, &executarAlterarCadastroInteiro,
							"Deletar o Cadastro", 3, &executarExcluirCadastro,
							"Consultar Outro", 0, &exibirMenuConsultarCadastro,
							"Voltar ao Menu de Cadastros", 9, &exibirMenuCadastro,
						}
					};
			//
	//
	
	//menuOrdemProducao
		Menu menuOrdemProducao = {
			"ORDEM PRODU��O",
			3,
			{
				"Nova Ordem de Produ��o", 1, &exibirMenuNovaOrdemProducao,
				"Consultar Ordem de Produ��o", 2, &exibirMenuConsultarOrdemProducao,
				"Voltar ao Menu Inicial", 0, &exibirMenuPrincipal,
			}
		};
		
			//Nova Ordem de Produ��o
				Menu menuNovaOrdemProducao = {
					"NOVA ORDEM DE PRODU��O",
					2,
					{
						"Imprimir ordem de produ��o", 1, &executarImpressaoOP,
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};	
			//
			
			//Consultar Ordem de Produ��o
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODU��O",
					7,
					{
						"Alterar Campo Espec�fico da Ordem de Produ��o", 1, &executarAlterarOP,
						"Adicionar Novos Itens na Ordem de Produ��o", 2, &executarAdicionarNovosItensOP,
						"Excluir Item da Ordem de Produ��o", 3, &executarExcluirItemOP,
						"Excluir Ordem de Produ��o", 4, &executarExclusaoOP,
						"Imprimir Ordem de Produ��o", 5, &executarImpressaoOP,
						"Consultar Outro", 0, &executarConsultaOrdemProducao,
						"Voltar ao Menu de Ordem de Produ��o", 9, &exibirMenuOrdemProducao,
					}
				};
			//
	//
//

//Cria��o de vari�veis de escopo global para manipula��o em fun��es
	

	int *pEscolhaUser = &escolhaUser;
	
	int loopMenu = 1; //Vari�vel respons�vel por controlar o loop do 'do while' dentro da fun��o main, sendo o �nico jeito de encerrar o menu, caso seja digitado a op��o 0 dentro do menu principal.
//
