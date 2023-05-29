#include "menu_var.h"

//Criação dos Menus
/* A criação dos Menus segue a seguinte estrutura:

	Menu nomeDoMenu = {
		"tituloDoMenu", [String]
		numeroDeOpçõesDesseMenu, [Int]
		{ //Inicialização das opções do Menu
			{"Texto da opção", numeroDaOpção, &funçãoASerExecutada}, [String, Int, Function]
			...
			...
			{"Texto da opção", numeroDaOpção, &funçãoASerExecutada}, [String, Int, Function]
		}
	};
	
*/
	//menuPrincipal
		Menu menuPrincipal = {
			"MENU",
			3,
			{
				{"Cadastros", 1, &exibirMenuCadastro},
				{"Ordem de Produção", 2, &exibirMenuOrdemProducao},
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
					6,
					{
						"Clientes", 1, &executarNovoCadastro,
						"Funcionários", 2, &executarNovoCadastro,
						"Fornecedores", 3, &executarNovoCadastro,
						"Produtos", 4, &executarNovoCadastro,
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
						"Funcionários", 2, & executarConsultaCadastro,
						"Fornecedores", 3, &executarConsultaCadastro,
						"Produtos", 4, &executarConsultaCadastro,
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
				
				//Menu de modificações do cadastro
					Menu menuModificarCadastro = {
						"CONSULTAR E MODIFICAR CADASTROS",
						5,
						{
							"Alterar Campo Específico do Cadastro", 1, &executarAlterarCadastro,
							"Alterar Todo o Cadastro", 2, &exibirMenuCadastro,
							"Deletar o Cadastro", 3, &exibirMenuCadastro,
							"Consultar Outro", 0, &exibirMenuConsultarCadastro,
							"Voltar ao Menu de Cadastros", 9, &exibirMenuPrincipal,
						}
					};
			//
	//
	
	//menuOrdemProducao
		Menu menuOrdemProducao = {
			"ORDEM PRODUÇÃO",
			3,
			{
				"Nova Ordem de Produção", 1, &exibirMenuNovaOrdemProducao,
				"Consultar Ordem de Produção", 2, &exibirMenuConsultarOrdemProducao,
				"Voltar ao Menu Inicial", 0, &exibirMenuPrincipal,
			}
		};
		
			//Nova Ordem de Produção
				Menu menuNovaOrdemProducao = {
					"NOVA ORDEM DE PRODUÇÃO",
					2,
					{
						"Imprimir ordem de produção", 1, &executarImpressaoOP,
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};	
			//
			
			//Consultar Ordem de Produção
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODUÇÃO",
					3,
					{
						"Imprimir Ordem de Produção", 1, &executarImpressaoOP,
						"Consultar Outro", 0, &executarConsultaOrdemProducao,
						"Voltar ao Menu de Ordem de Produção", 9, &exibirMenuOrdemProducao,
					}
				};
			//
	//
//

//Criação de variáveis de escopo global para manipulação em funções
	

	int *pEscolhaUser = &escolhaUser;
	
	int loopMenu = 1; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.
//
