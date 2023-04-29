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
	//Opções do Menu
		int exibirMenuPrincipal();
			int exibirMenuCadastro();
				int exibirMenuNovoCadastro();
				int exibirMenuConsultarCadastro();
			
			int exibirMenuOrdemProducao();
				int exibirMenuNovaOrdemProducao();
				int exibirMenuConsultarOrdemProducao();
	//

	//Função de fim do Menu
		int fimDoMenu();
	//
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
		Menu menuAtual; //Variável do tipo Menu que armazenará qual é o Menu Atual do programa.
		int escolhaUser; //Variável que armazenará qual é o valor digitado pelo usuário nas opções do Menu.
		int loopMenu = 1; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.
	//

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;
	
	//Setando valores genéricos para as variáveis importantes
	int erro = 0;
	
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
	
	printf("Opção: ");
	int valid = scanf("%d", pEscolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(*pEscolhaUser < 0) {
			*pErro = 2;
			return 0;
		} else {
			*pErro = 2; //Assume todos os valores retornando um erro de número inválido até que seja conferido pelo for
			for(i = 0; i < pMenuAtual -> numeroDeOpcoes; i++) { // Laço para percorrer todas as opções do Menu e ver se existe a opção digitada
				if(pMenuAtual -> opcoes[i].numeroDaOpcao == *pEscolhaUser) { //Caso exista alguma opção que o usuário digitou
					*pErro = 0; //Reatribui o valor do erro
					pMenuAtual -> opcoes[i].funcao(); //Executa da função presente no item do menu
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
	
	//Função de fim do Menu
		int fimDoMenu() {
			loopMenu = 0;
			return 0;
		}
	//
	
//


