#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_TITULO_MENU 40

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
				int exibirMenuConsultarCadastro();
			
			int exibirMenuOrdemProducao();
				int exibirMenuNovaOrdemProducao();
				int exibirMenuConsultarOrdemProducao();
	//

	//Fun��o de fim do Menu
		int fimDoMenu();
	//
//

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
				{"Consultar Cadastros", 2, &exibirMenuConsultarCadastro},
				{"Voltar ao Menu Inicial", 0, &exibirMenuPrincipal},
			}
		};
		
			//Criar novo Cadastro
				Menu menuNovoCadastro = {
					"NOVO CADASTRO",
					2,
					{
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
					}
				};
			//
			
			//Consultar Cadastros
				Menu menuConsultarCadastro = {
					"CONSULTAR CADASTROS",
					2,
					{
						"Voltar ao Menu Anterior", 0, &exibirMenuCadastro,
						"Voltar ao Menu Inicial", 9, &exibirMenuPrincipal,
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


//Declara��o de fun��es de uso
	//Usada para receber o input do usu�rio e retornar erro caso seja digitado uma letra, ou um n�mero que n�o tem no menu
	int receberOpcaoMenu(int *pEscolhaUser, int *pErr, Menu *pMenuAtual);
	
	//Exibe uma mensagem de erro de acordo com o erro passado
	void exibirErro(int *pErr);
	
	//Exibe o t�tulo do Menu Atual com caracteres # do lado direito e lado esquerdo, para ficar mais bonito
	void exibirTituloMenuAtual(Menu *pMenuAtual);

	//Exibe as op��es dispon�veis no Menu Atual
	void exibirOpcoesMenuAtual(Menu *pMenuAtual);

//
	
	//Cria��o de vari�veis de escopo global para manipula��o em fun��es
		Menu menuAtual; //Vari�vel do tipo Menu que armazenar� qual � o Menu Atual do programa.
		int escolhaUser; //Vari�vel que armazenar� qual � o valor digitado pelo usu�rio nas op��es do Menu.
		int loopMenu = 1; //Vari�vel respons�vel por controlar o loop do 'do while' dentro da fun��o main, sendo o �nico jeito de encerrar o menu, caso seja digitado a op��o 0 dentro do menu principal.
	//

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	
	//Setando valores gen�ricos para as vari�veis importantes
	int erro = 0;
	
	//Ponteiros das vari�veis importantes
	int *pErro = &erro;
	int *pEscolhaUser = &escolhaUser;
	Menu *pMenuAtual = &menuAtual;
	
	//Estrutura de repeti��o do Menu
	do{
		system("cls"); //Limpando a tela do prompt
		
		exibirTituloMenuAtual(pMenuAtual);
		
		exibirErro(pErro); //Exibindo eventuais erros, por padr�o erro = 0, portanto, sem erros
		
		exibirOpcoesMenuAtual(pMenuAtual);
		
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
	
	printf("Op��o: ");
	int valid = scanf("%d", pEscolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(*pEscolhaUser < 0) {
			*pErro = 2;
			return 0;
		} else {
			*pErro = 2; //Assume todos os valores retornando um erro de n�mero inv�lido at� que seja conferido pelo for
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // La�o para percorrer todas as op��es do Menu e ver se existe a op��o digitada
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) { //Caso exista alguma op��o que o usu�rio digitou
					*pErro = 0; //Reatribui o valor do erro
					pMenuAtual -> opcoes[i].funcao(); //Executa da fun��o presente no item do menu
					break; //Encerra o for
				}
			}
			return 0;
		}
	} else {
		*pErro = 1;
		return 0;
	}
}

//Fun��o de exibi��o de erros
void exibirErro(int *pErro) {
	switch(*pErro) {
		case 0:
			break;
		case 1:
			printf("Digite apenas n�meros!\n");
			break;
		case 2:
			printf("Op��o inv�lida! Digite novamente!\n");
		break;
		default:
			break;
	}
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
					
					int exibirMenuConsultarCadastro() {
						menuAtual = menuConsultarCadastro;
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
	
//


