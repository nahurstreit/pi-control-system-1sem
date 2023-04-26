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
	int exibirMenuPrincipal();
		int exibirMenuCadastro();
			int exibirMenuNovoCadastro();
			int exibirMenuConsultarCadastro();
		
		int exibirMenuOrdemProducao();
			int exibirMenuNovaOrdemProducao();
			int exibirMenuConsultarOrdemProducao();
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
				{"Sair", 0, NULL},
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
				{"Voltar", 0, &exibirMenuPrincipal},
			}
		};
		
			//Criar novo Cadastro
				Menu menuNovoCadastro = {
					"NOVO CADASTRO",
					1,
					{
						"Voltar", 0, &exibirMenuCadastro,
					}
				};
			//
			
			//Consultar Cadastros
				Menu menuConsultarCadastro = {
					"CONSULTAR CADASTROS",
					1,
					{
						"Voltar", 0, &exibirMenuCadastro,
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
				"Voltar", 0, &exibirMenuPrincipal	
			}
		};
		
			//Nova Ordem de Produ��o
				Menu menuNovaOrdemProducao = {
					"NOVA ORDEM DE PRODU��O",
					1,
					{
						"Voltar", 0, &exibirMenuOrdemProducao,
					}
				};	
			//
			
			//Consultar Ordem de Produ��o
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODU��O",
					1,
					{
						"Voltar", 0, &exibirMenuOrdemProducao,
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
		Menu menuAtual;
		int escolhaUser;
	//

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	
	//Setando valores gen�ricos para as vari�veis importantes
	int erro = 0, a = 0;
	escolhaUser = 1;
	
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
		
	} while (a != 1);
	
	printf("\n\nPrograma encerrado com sucesso!");
	return 0;
}

//Fun��o que exibe o t�tulo do menuAtual, foi feita separada do resto para poder ser utilizada mesmo que n�o exista um menu.
void exibirTituloMenuAtual(Menu *pMenuAtual){
	
	//Vars
		int i;
		int limiteCharTitulo = (TAM_TITULO_MENU - strlen(pMenuAtual -> tituloDoMenu) - 2)/2; //limite de caracteres # = tamanho m�ximo do menu (definido no come�o do c�digo - o tamanho do titulo atual - 2(espa�os em branco adicionados no printf(" %s ") tudo isso divido por 2, pois ser�o feitas duas vezes, para que fique a mesma quantidade de # do lado esquerdo e do lado direito
	//
	
	//For do lado direito
	for(i = 0; i < limiteCharTitulo; i++) {
		putchar('#');
	}
	
	//Titulo do Menu
	printf(" %s ", pMenuAtual -> tituloDoMenu);
	
	//For do lado esquerdo
	for(i = 0; i < limiteCharTitulo; i++) {
		putchar('#');
	}
	
	//Pulando linhas depois do titulo completo
	printf("\n\n");
}

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
		if(*pEscolhaUser < 0 || *pEscolhaUser > pMenuAtual -> numeroDeOpcoes || *pEscolhaUser == pMenuAtual -> numeroDeOpcoes) {
			*pErro = 2;
			return 0;
		} else {
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // La�o para percorrer todas as op��es do Menu e ver qual a correta
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) {
					pMenuAtual -> opcoes[i].funcao(); //Execu��o da fun��o presente no item do menu
					return 0;
				}
			}
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
