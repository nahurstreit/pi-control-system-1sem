#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "cadastro.h"
#include "interface.h"

#define TAM_TITULO_MENU 40

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
			2,
			{
				{"Cadastros", 1, &exibirMenuCadastro},
//				{"Ordem de Produção", 2, &exibirMenuOrdemProducao},
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
						"Funcionários", 2, &executarNovoCadastro,
						"Fornecedores", 3, &executarNovoCadastro,
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
							"Voltar ao Menu Principal", 9, &exibirMenuPrincipal,
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
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};	
			//
			
			//Consultar Ordem de Produção
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODUÇÃO",
					2,
					{
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
			//
	//
//

//Criação de variáveis de escopo global para manipulação em funções
	Menu menuAtual; //Variável do tipo Menu que armazenará qual é o Menu Atual do programa.
	Menu *pMenuAtual = &menuAtual;
	
	int escolhaUser; //Variável que armazenará qual é o valor digitado pelo usuário nas opções do Menu.
	int *pEscolhaUser = &escolhaUser;
	
	int loopMenu = 1; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.

	int mensagem = 0; //Variável que armazena o valor atual de Mensagem
	int *pMensagem = &mensagem;	//Definição de ponteiro para poder passar a mensagem como parâmetro em funções
	
	int erro = 0; //Variável que armazena o valor atual de Erro
	int *pErro = &erro; //Definição de ponteiro para poder passar o erro como parâmetro em funções
//

void main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;

	do{
	    system("color E0");
	    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    	SMALL_RECT rect = {0, 0, 101, 42}; // Define o tamanho da janela

    	SetConsoleWindowInfo(hConsole, TRUE, &rect); // Define o tamanho da janela
    
    	SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
		exibirInterfaceTitulo(pMenuAtual -> tituloDoMenu, 1);		
		
		exibirMensagem(pMensagem); //Exibindo eventuais mensagens, por padrão erro = 0, portanto, sem mensagens
		
		exibirErro(pErro); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes(pMenuAtual);
		
		receberOpcaoMenu(pEscolhaUser, pErro, pMenuAtual); //Solicita a escolha do usuário e faz o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
}

void receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual) {
	
	int i;
	int valid = scanf("%d", pEscolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(*pEscolhaUser < 0) {
			*pErro = 2;
		} else {
			*pErro = 2; //Assume todos os valores retornando um erro de número inválido até que seja conferido pelo for
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // Laço para percorrer todas as opções do Menu e ver se existe a opção digitada
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) { //Caso exista alguma opção que o usuário digitou
					*pErro = 0; //Reatribui o valor do erro
					pMenuAtual -> opcoes[i].funcao(pMenuAtual, pErro); //Executa da função presente no item do menu
					break; //Encerra o for
				}
			}
		}
	} else {
		*pErro = 1;
	}
}

void exibirMensagem(int *pMensagem) {
	char res[50];
	
	switch(*pMensagem) {
		case 1:
			strcpy(res, "Sucesso! Cadastro Concluído!");
			break;
		case 2:
			strcpy(res, "Sucesso! Campo alterado!");
			break;
		case 3:
			strcpy(res, "Cadastro Excluído!");
			break;
		default:;
	}
	
	if(*pMensagem != 0) exibirInterfaceInteracao(res);
	*pMensagem = 0;
}

void exibirErro(int *pErro) {
	char res[50];
	switch(*pErro) {
		case 0:
			break;
		case 1:
			strcpy(res, "Erro: Digite apenas números!");
			break;
		case 2:
			strcpy(res, "Erro: Opção inválida! Digite novamente!");
		break;
		case 3:
			strcpy(res, "Erro: Não foi possível realizar sua consulta!");
			break;
		case 4:
			strcpy(res, "Erro: Não existe nenhum registro para esse Número de Cadastro!");
			break;
		default:;
	}
	
	if(*pErro != 0) exibirInterfaceInteracao(res);
	*pErro = 0;
}

//Funções a serem executadas pelas opções dos Menus
	//Funções de chamada do Menu
		void exibirMenuPrincipal() {
			menuAtual = menuPrincipal;
		}
		
			//Funções menuCadastro
				void exibirMenuCadastro() {
					menuAtual = menuCadastro;
				}
				
					void exibirMenuNovoCadastro() {
						menuAtual = menuNovoCadastro;
					}
						void executarNovoCadastro(Menu *pMenuAtual, int *pErro) {
							novoCadastro(pEscolhaUser, pMensagem, pErro);
						}
					
					void exibirMenuConsultarCadastro() {
						menuAtual = menuConsultarCadastro;
					}
						void executarConsultaCadastro(Menu *pMenuAtual, int *pErro) {
							int estado = 0;
							int *pEstado = &estado;
							consultaCadastro(pEscolhaUser, pMensagem, pErro, pEstado);
							if(estado == 1) {
								receberOpcoesAlteracaoCadastro();
							}
						}
							void executarAlterarCadastro() {
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								alterarCadastro(pEscolhaUser, pMensagem, pErro);
							}
						
			//
			
			//Funções menuOrdemProducao
				void exibirMenuOrdemProducao() {
					menuAtual = menuOrdemProducao;
				}
					void exibirMenuNovaOrdemProducao() {
						menuAtual = menuNovaOrdemProducao;
					}
					
					void exibirMenuConsultarOrdemProducao() {
						menuAtual = menuConsultarOrdemProducao;
					}
			//
	//
	
	//Função de fim do Menu
		void fimDoMenu() {
			loopMenu = 0;
		}
	//

//Função de recebimento de opções na parte de Alteração de cadastro
	void receberOpcoesAlteracaoCadastro() {
		int escolhaUserAlterar = 1;
		int *pEscolhaUserAlterar = &escolhaUserAlterar;
		
		while(escolhaUserAlterar == 1 || escolhaUserAlterar == 2 || escolhaUserAlterar == 3) {
			menuAtual = menuModificarCadastro;
			exibirInterfaceOpcoes(pMenuAtual);
			exibirMensagem(pMensagem);
			scanf("%d", &escolhaUserAlterar);
			fflush(stdin);
			
			switch(escolhaUserAlterar) {
				case 1:
					executarAlterarCadastro();
					break;
				case 2:
					executarExcluirCadastro(2, pEscolhaUserAlterar, pMensagem, pErro);
					if(escolhaUserAlterar == 0) {
						exibirMenuNovoCadastro();
						executarNovoCadastro(pMenuAtual, pErro);
						menuAtual = menuConsultarCadastro;
						executarConsultaCadastro(pMenuAtual, pErro);
					}
					break;
				case 3:
					executarExcluirCadastro(1, pEscolhaUserAlterar, pMensagem, pErro);
					if(escolhaUserAlterar == 0) {
						menuAtual = menuConsultarCadastro;
						executarConsultaCadastro(pMenuAtual, pErro);
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
//
