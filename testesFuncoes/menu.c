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
			{"Texto da opção", numeroDaOpção, funçãoASerExecutada}, [String, Int, Function]
			...
			...
			{"Texto da opção", numeroDaOpção, funçãoASerExecutada}, [String, Int, Function]
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
				{"Modificar Cadastros", 2, &exibirMenuModificarCadastro},
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
				Menu menuModificarCadastro = {
					"MODIFICAR CADASTROS",
					5,
					{
						"Clientes", 1, &executarConsultaCadastro,
						"Funcionários", 2, & executarConsultaCadastro,
						"Fornecedores", 3, &executarConsultaCadastro,
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
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
	int escolhaUser; //Variável que armazenará qual é o valor digitado pelo usuário nas opções do Menu.
	int *pEscolhaUser = &escolhaUser;
	int loopMenu = 1; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.
//
	//Setando valores genéricos para as variáveis importantes
	int erro = 0;
	int mensagem = 0;
	
	//Ponteiros das variáveis importantes
	int *pErro = &erro;
	int *pMensagem = &mensagem;
	

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	Menu *pMenuAtual = &menuAtual;
	
	//Estrutura de repetição do Menu
	do{	
		
		exibirInterfaceTitulo(pMenuAtual -> tituloDoMenu, 1);
		
		exibirMensagem(pMensagem);
		
		exibirErro(pErro); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes(pMenuAtual);
		
		receberOpcaoMenu(pEscolhaUser, pErro, pMenuAtual); //Solicita a escolha do usuário e fazer o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
	return 0;
}

//Função que exibe o título do menuAtual, foi feita separada do resto para poder ser utilizada mesmo que não exista um menu.
void exibirTituloMenuAtual(Menu *pMenuAtual){
	
	//Vars
		int i;
		int limiteCharTitulo = (TAM_TITULO_MENU - strlen(pMenuAtual -> tituloDoMenu) - 2)/2; //limite de caracteres # = tamanho máximo do menu (definido no começo do código - o tamanho do titulo atual - 2(espaços em branco adicionados no printf(" %s ") tudo isso divido por 2, pois serão feitas duas vezes, para que fique a mesma quantidade de # do lado esquerdo e do lado direito
	//
	
	//For do lado esquerdo
	for(i = 0; i < limiteCharTitulo; i++) {
		putchar('#');
	}
	
	//Titulo do Menu
	printf(" %s ", pMenuAtual -> tituloDoMenu);
	
	//For do lado direito
	for(i = 0; i < limiteCharTitulo; i++) {
		putchar('#');
	}
	
	//Pulando linhas depois do titulo completo
	printf("\n\n");
}

//Função que exibe as opções dentro do menuAtual
void exibirOpcoesMenuAtual(Menu *pMenuAtual) {
	int i;
	
	for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) {
		printf("[%d] - %s\n", pMenuAtual -> opcoes[i].numeroDaOpcao, pMenuAtual -> opcoes[i].textoDaOpcao);
	}
}

//Função que recebe o input do usuário e trata erros de entrada inválida ou opção inexistente
int receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual) {
	
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
	return 0;
}

//Funçaõ de exibição de mensagens
void exibirMensagem(int *pMensagem) {
	switch(*pMensagem) {
		case 1:
			exibirInterfaceInteracao("Sucesso! Cadastro Concluído!");
			break;
		default:
			break;
	}
	
	*pMensagem = 0;
	
}

//Função de exibição de erros
void exibirErro(int *pErro) {
	char res[50] = {0};
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
		default:
			break;
	}
	
	if(*pErro != 0) exibirInterfaceInteracao(res);
	
	*pErro = 0;
}

/*
Coloquei system("cls"), para fazer a limpagem das telas, mas estou enfrentando dificuldades em manter alguns padrões
*/

//Funções a serem executadas pelas opções dos Menus
	//Funções de chamada do Menu
		int exibirMenuPrincipal() {
			menuAtual = menuPrincipal;
		}
		
			//Funções menuCadastro
				int exibirMenuCadastro() {
					menuAtual = menuCadastro;
				}
				
					int exibirMenuNovoCadastro() {
						menuAtual = menuNovoCadastro;
					}
						int executarNovoCadastro(Menu *pMenuAtual, int *pErro) {
							novoCadastro(pEscolhaUser, pMensagem, pErro);
						}
					
					int exibirMenuModificarCadastro() {
						menuAtual = menuModificarCadastro;
					}
						int executarConsultaCadastro(Menu *pMenuAtual, int *pErro) {
							exibirTituloMenuAtual(pMenuAtual);
							consultaCadastro(pEscolhaUser, pMensagem, pErro);
							menuAtual = menuModificarCadastro;
						}
			//
			
			//Funções menuOrdemProducao
				int exibirMenuOrdemProducao() {
					menuAtual = menuOrdemProducao;
				}
					int exibirMenuNovaOrdemProducao() {
						menuAtual = menuNovaOrdemProducao;
					}
					
					int exibirMenuConsultarOrdemProducao() {
						menuAtual = menuConsultarOrdemProducao;
					}
			//
	//
	
	//Função de fim do Menu
		int fimDoMenu() {
			loopMenu = 0;
			return 0;
		}
	//
	
//
