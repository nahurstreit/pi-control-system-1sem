#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "menu.h"
#include "cadastro.h"
#include "interface.h"

#define TAM_TITULO_MENU 40

//Cria��o dos Menus
/* A cria��o dos Menus segue a seguinte estrutura:

	Menu nomeDoMenu = {
		"tituloDoMenu", [String]
		numeroDeOp��esDesseMenu, [Int]
		{ //Inicializa��o das op��es do Menu
			{"Texto da op��o", numeroDaOp��o, fun��oASerExecutada}, [String, Int, Function]
			...
			...
			{"Texto da op��o", numeroDaOp��o, fun��oASerExecutada}, [String, Int, Function]
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
						"Funcion�rios", 2, & executarConsultaCadastro,
						"Fornecedores", 3, &executarConsultaCadastro,
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
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};	
			//
			
			//Consultar Ordem de Produ��o
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODU��O",
					2,
					{
						"Voltar ao Menu Anterior", 0, &exibirMenuOrdemProducao,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
			//
	//
//

//Cria��o de vari�veis de escopo global para manipula��o em fun��es
	Menu menuAtual; //Vari�vel do tipo Menu que armazenar� qual � o Menu Atual do programa.
	int escolhaUser; //Vari�vel que armazenar� qual � o valor digitado pelo usu�rio nas op��es do Menu.
	int *pEscolhaUser = &escolhaUser;
	int loopMenu = 1; //Vari�vel respons�vel por controlar o loop do 'do while' dentro da fun��o main, sendo o �nico jeito de encerrar o menu, caso seja digitado a op��o 0 dentro do menu principal.
//
	//Setando valores gen�ricos para as vari�veis importantes
	int erro = 0;
	int mensagem = 0;
	
	//Ponteiros das vari�veis importantes
	int *pErro = &erro;
	int *pMensagem = &mensagem;
	

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	Menu *pMenuAtual = &menuAtual;
	
	//Estrutura de repeti��o do Menu
	do{
		exibirInterfaceTitulo(pMenuAtual -> tituloDoMenu, 1);
		
		exibirMensagem(pMensagem);
		
		exibirErro(pErro); //Exibindo eventuais erros, por padr�o erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes(pMenuAtual);
		
		receberOpcaoMenu(pEscolhaUser, pErro, pMenuAtual); //Solicita a escolha do usu�rio e fazer o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
	return 0;
}

//Fun��o que exibe o t�tulo do menuAtual, foi feita separada do resto para poder ser utilizada mesmo que n�o exista um menu.
void exibirTituloMenuAtual(Menu *pMenuAtual){
	
	//Vars
		int i;
		int limiteCharTitulo = (TAM_TITULO_MENU - strlen(pMenuAtual -> tituloDoMenu) - 2)/2; //limite de caracteres # = tamanho m�ximo do menu (definido no come�o do c�digo - o tamanho do titulo atual - 2(espa�os em branco adicionados no printf(" %s ") tudo isso divido por 2, pois ser�o feitas duas vezes, para que fique a mesma quantidade de # do lado esquerdo e do lado direito
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

//Fun��o que exibe as op��es dentro do menuAtual
void exibirOpcoesMenuAtual(Menu *pMenuAtual) {
	int i;
	
	for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) {
		printf("[%d] - %s\n", pMenuAtual -> opcoes[i].numeroDaOpcao, pMenuAtual -> opcoes[i].textoDaOpcao);
	}
}

//Fun��o que recebe o input do usu�rio e trata erros de entrada inv�lida ou op��o inexistente
int receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual) {
	
	int i;
	int valid = scanf("%d", pEscolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(*pEscolhaUser < 0) {
			*pErro = 2;
		} else {
			*pErro = 2; //Assume todos os valores retornando um erro de n�mero inv�lido at� que seja conferido pelo for
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // La�o para percorrer todas as op��es do Menu e ver se existe a op��o digitada
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) { //Caso exista alguma op��o que o usu�rio digitou
					*pErro = 0; //Reatribui o valor do erro
					pMenuAtual -> opcoes[i].funcao(pMenuAtual, pErro); //Executa da fun��o presente no item do menu
					break; //Encerra o for
				}
			}
		}
	} else {
		*pErro = 1;
	}
	return 0;
}

//Fun�a� de exibi��o de mensagens
void exibirMensagem(int *pMensagem) {
	switch(*pMensagem) {
		case 1:
			exibirInterfaceInteracao("Sucesso! Cadastro Conclu�do!");
			break;
		case 2:
			exibirInterfaceInteracao("Sucesso! Campo alterado!");
			break;
		case 3:
			exibirInterfaceInteracao("Cadastro Exclu�do!");
		default: ;
	}
	
	*pMensagem = 0;
	
}

//Fun��o de exibi��o de erros
void exibirErro(int *pErro) {
	char res[50] = {0};
	switch(*pErro) {
		case 0:
			break;
		case 1:
			strcpy(res, "Erro: Digite apenas n�meros!");
			break;
		case 2:
			strcpy(res, "Erro: Op��o inv�lida! Digite novamente!");
		break;
		case 3:
			strcpy(res, "Erro: N�o foi poss�vel realizar sua consulta!");
			break;
		case 4:
			strcpy(res, "Erro: N�o existe nenhum registro para esse N�mero de Cadastro!");
		default:
			break;
	}
	
	if(*pErro != 0) exibirInterfaceInteracao(res);
	
	*pErro = 0;
}

//Fun��es a serem executadas pelas op��es dos Menus
	//Fun��es de chamada do Menu
		int exibirMenuPrincipal() {
			menuAtual = menuPrincipal;
		}
		
			//Fun��es menuCadastro
				int exibirMenuCadastro() {
					menuAtual = menuCadastro;
				}
				
					int exibirMenuNovoCadastro() {
						menuAtual = menuNovoCadastro;
					}
						int executarNovoCadastro(Menu *pMenuAtual, int *pErro) {
							novoCadastro(pEscolhaUser, pMensagem, pErro);
						}
					
					int exibirMenuConsultarCadastro() {
						menuAtual = menuConsultarCadastro;
					}
						int executarConsultaCadastro(Menu *pMenuAtual, int *pErro) {
							int estado = 0;
							int *pEstado = &estado;
							consultaCadastro(pEscolhaUser, pMensagem, pErro, pEstado);
							if(estado == 1) {
								receberOpcoesDeCadastro();
							}
						}
							int executarAlterarCadastro() {
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								alterarCadastro(pEscolhaUser, pMensagem, pErro);
							}
						
			//
			
			//Fun��es menuOrdemProducao
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
	
	//Fun��o de fim do Menu
		int fimDoMenu() {
			loopMenu = 0;
			return 0;
		}
	//
	
	void receberOpcoesDeCadastro() {
		int escolhaUserMod = 1;
		int *pEscolhaUserMod = &escolhaUserMod;
		Menu *pMenuAtual = &menuAtual;
		
		while(escolhaUserMod == 1 || escolhaUserMod == 2 || escolhaUserMod == 3) {
			menuAtual = menuModificarCadastro;
			exibirInterfaceOpcoes(pMenuAtual);
			exibirMensagem(pMensagem);
			scanf("%d", &escolhaUserMod);
			fflush(stdin);
			
			switch(escolhaUserMod) {
				case 1:
					executarAlterarCadastro();
					break;
				case 2:
					break;
				case 3:
					executarExcluirCadastro(1, pEscolhaUserMod, pMensagem, pErro);
					if(escolhaUserMod == 0) {
						exibirMenuConsultarCadastro();
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
