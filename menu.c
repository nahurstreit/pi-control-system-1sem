#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM_TITULO_MENU 40

//Definição do tipo OpcaoDoMenu
typedef struct {
	char textoDaOpcao[50];
	int numeroDaOpcao;
	int (*funcao)();
} OpcaoDoMenu;

//Definição do tipo Menu
typedef struct {
	char tituloDoMenu[50];
	int numeroDeOpcoes;
	OpcaoDoMenu opcoes[10];
} Menu;


//Declaração das funções de chamada das opções
	int exibirMenuPrincipal();
		int exibirMenuCadastro();
			int exibirMenuNovoCadastro();
			int exibirMenuConsultarCadastro();
		
		int exibirMenuOrdemProducao();
			int exibirMenuNovaOrdemProducao();
			int exibirMenuConsultarOrdemProducao();
//

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
			"ORDEM PRODUÇÃO",
			3,
			{
				"Nova Ordem de Produção", 1, &exibirMenuNovaOrdemProducao,
				"Consultar Ordem de Produção", 2, &exibirMenuConsultarOrdemProducao,
				"Voltar", 0, &exibirMenuPrincipal	
			}
		};
		
			//Nova Ordem de Produção
				Menu menuNovaOrdemProducao = {
					"NOVA ORDEM DE PRODUÇÃO",
					1,
					{
						"Voltar", 0, &exibirMenuOrdemProducao,
					}
				};	
			//
			
			//Consultar Ordem de Produção
				Menu menuConsultarOrdemProducao = {
					"CONSULTAR ORDEM DE PRODUÇÃO",
					1,
					{
						"Voltar", 0, &exibirMenuOrdemProducao,
					}
				};
			//
	//
//


//Declaração de funções de uso
	//Usada para receber o input do usuário e retornar erro caso seja digitado uma letra, ou um número que não tem no menu
	int receberOpcaoMenu(int *pEscolhaUser, int *pErr, Menu *pMenuAtual);
	
	//Exibe uma mensagem de erro de acordo com o erro passado
	void exibirErro(int *pErr);
	
	//Exibe o título do Menu Atual com caracteres # do lado direito e lado esquerdo, para ficar mais bonito
	void exibirTituloMenuAtual(Menu *pMenuAtual);

	//Exibe as opções disponíveis no Menu Atual
	void exibirOpcoesMenuAtual(Menu *pMenuAtual);

//
	
	//Criação de variáveis de escopo global para manipulação em funções
		Menu menuAtual;
		int escolhaUser;
	//

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	
	//Setando valores genéricos para as variáveis importantes
	int erro = 0, a = 0;
	escolhaUser = 1;
	
	//Ponteiros das variáveis importantes
	int *pErro = &erro;
	int *pEscolhaUser = &escolhaUser;
	Menu *pMenuAtual = &menuAtual;
	
	//Estrutura de repetição do Menu
	do{
		system("cls"); //Limpando a tela do prompt
		
		exibirTituloMenuAtual(pMenuAtual);
		
		exibirErro(pErro); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirOpcoesMenuAtual(pMenuAtual);
		
		receberOpcaoMenu(pEscolhaUser, pErro, pMenuAtual); //Solicita a escolha do usuário e fazer o tratamento de erros
		
	} while (a != 1);
	
	printf("\n\nPrograma encerrado com sucesso!");
	return 0;
}

//Função que exibe o título do menuAtual, foi feita separada do resto para poder ser utilizada mesmo que não exista um menu.
void exibirTituloMenuAtual(Menu *pMenuAtual){
	
	//Vars
		int i;
		int limiteCharTitulo = (TAM_TITULO_MENU - strlen(pMenuAtual -> tituloDoMenu) - 2)/2; //limite de caracteres # = tamanho máximo do menu (definido no começo do código - o tamanho do titulo atual - 2(espaços em branco adicionados no printf(" %s ") tudo isso divido por 2, pois serão feitas duas vezes, para que fique a mesma quantidade de # do lado esquerdo e do lado direito
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

//Função que recebe o input do usuário e trata erros de entrada inválida ou opção inexistente
int receberOpcaoMenu(int *pEscolhaUser, int *pErro, Menu *pMenuAtual) {
	
	int i;
	
	printf("Opção: ");
	int valid = scanf("%d", pEscolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(*pEscolhaUser < 0 || *pEscolhaUser > pMenuAtual -> numeroDeOpcoes || *pEscolhaUser == pMenuAtual -> numeroDeOpcoes) {
			*pErro = 2;
			return 0;
		} else {
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // Laço para percorrer todas as opções do Menu e ver qual a correta
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) {
					pMenuAtual -> opcoes[i].funcao(); //Execução da função presente no item do menu
					return 0;
				}
			}
		}
	} else {
		*pErro = 1;
		return 0;
	}
}

//Função de exibição de erros
void exibirErro(int *pErro) {
	switch(*pErro) {
		case 0:
			break;
		case 1:
			printf("Digite apenas números!\n");
			break;
		case 2:
			printf("Opção inválida! Digite novamente!\n");
		break;
		default:
			break;
	}
	*pErro = 0;
}

//Funções a serem executadas pelas opções dos Menus
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
				
				int exibirMenuConsultarCadastro() {
					menuAtual = menuConsultarCadastro;
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
