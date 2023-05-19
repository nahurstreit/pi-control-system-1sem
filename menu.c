#include "global/global.h"
#include "menu.h"

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
			2,
			{
				{"Cadastros", 1, &exibirMenuCadastro},
//				{"Ordem de Produ��o", 2, &exibirMenuOrdemProducao},
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
	
/** Para uso Posterior
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
**/
//

//Cria��o de vari�veis de escopo global para manipula��o em fun��es
	

	int *pEscolhaUser = &escolhaUser;
	
	int loopMenu = 1; //Vari�vel respons�vel por controlar o loop do 'do while' dentro da fun��o main, sendo o �nico jeito de encerrar o menu, caso seja digitado a op��o 0 dentro do menu principal.
//

void main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;

	do{
	    system("color E0"); //Defini��o da cor do sistema
	    
	    // Comente esse c�digo para tirar a trava de tela
//		    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//			SMALL_RECT rect = {0, 0, 101, 42}; // Define o tamanho da janela
//			SetConsoleWindowInfo(hConsole, TRUE, &rect); // Define o tamanho da janela
//			SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    	//Comente esse c�digo para tirar a trava de tela
    	
		exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);		
		
		exibirMensagem(); //Exibindo eventuais mensagens, por padr�o erro = 0, portanto, sem mensagens
		
		exibirErro(); //Exibindo eventuais erros, por padr�o erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes();
		
		receberOpcaoMenu(); //Solicita a escolha do usu�rio e faz o tratamento de erros
		
	} while (loopMenu != 0);
	
	printf("\n\nPrograma encerrado com sucesso!");
}

void receberOpcaoMenu() {
	
	int i;
	int valid = scanf("%d", &escolhaUser);
	fflush(stdin);
	
	if(valid == 1) {
		if(escolhaUser < 0) {
			erro = 2;
		} else {
			erro = 2; //Assume todos os valores retornando um erro de n�mero inv�lido at� que seja conferido pelo for
			for(i = 0; i < menuAtual.numeroDeOpcoes; i++) { // La�o para percorrer todas as op��es do Menu e ver se existe a op��o digitada
				if(menuAtual.opcoes[i].numeroDaOpcao == escolhaUser) { //Caso exista alguma op��o que o usu�rio digitou
					erro = 0; //Reatribui o valor do erro
					menuAtual.opcoes[i].funcao(menuAtual); //Executa da fun��o presente no item do menu
					break; //Encerra o for
				}
			}
		}
	} else {
		erro = 1;
	}
}

void exibirMensagem() {
	char res[50];
	
	switch(mensagem) {
		case 1:
			strcpy(res, "Sucesso! Cadastro Conclu�do!");
			break;
		case 2:
			strcpy(res, "Sucesso! Campo alterado!");
			break;
		case 3:
			strcpy(res, "Cadastro Exclu�do!");
			break;
		default:;
	}
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}

void exibirErro() {
	char res[50];
	switch(erro) {
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
			break;
		case 5:
			strcpy(res, "Erro: Voc� ainda n�o digitou nenhum campo para poder alterar!");
			break;
		case 6:
			strcpy(res, "Erro: Campo inv�lido!");
			break;
		case 7:
			strcpy(res, "Erro: Voc� ainda n�o digitou esse campo!");
			break;
		case 8:
			strcpy(res, "Erro: Voc� s� pode alterar o primeiro campo!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
}

//Fun��es a serem executadas pelas op��es dos Menus
	//Fun��es de chamada do Menu
		void exibirMenuPrincipal() {
			menuAtual = menuPrincipal;
		}
		
			//Fun��es menuCadastro
				void exibirMenuCadastro() {
					menuAtual = menuCadastro;
				}
				
					void exibirMenuNovoCadastro() {
						menuAtual = menuNovoCadastro;
					}
						void executarNovoCadastro() {
							novoCadastro();
						}
					
					void exibirMenuConsultarCadastro() {
						menuAtual = menuConsultarCadastro;
					}
						void executarConsultaCadastro() {
							int estado = 0;
							int *pEstado = &estado;
							consultaCadastro(pEstado);
							if(estado == 1) {
								receberOpcoesAlteracaoCadastro();
							}
						}
							void executarAlterarCadastro() {
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								alterarCadastro();
							}
						
			//
			
		/** Para uso posterior
			//Fun��es menuOrdemProducao
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
		**/
	//
	
	//Fun��o de fim do Menu
		void fimDoMenu() {
			loopMenu = 0;
		}
	//

//Fun��o de recebimento de op��es na parte de Altera��o de cadastro
	void receberOpcoesAlteracaoCadastro() {
		int escolhaUserAlterar = 1;
		int *pEscolhaUserAlterar = &escolhaUserAlterar;
		
		while(escolhaUserAlterar == 1 || escolhaUserAlterar == 2 || escolhaUserAlterar == 3) {
			menuAtual = menuModificarCadastro;
			exibirInterfaceOpcoes();
			exibirMensagem();
			scanf("%d", &escolhaUserAlterar);
			fflush(stdin);
			
			switch(escolhaUserAlterar) {
				case 1:
					executarAlterarCadastro();
					break;
				case 2:
					executarExcluirCadastro(2, pEscolhaUserAlterar);
					if(escolhaUserAlterar == 0) {
						exibirMenuNovoCadastro();
						mensagem = 0;
						executarNovoCadastro();
						menuAtual = menuConsultarCadastro;
						executarConsultaCadastro();
					}
					break;
				case 3:
					executarExcluirCadastro(1, pEscolhaUserAlterar);
					if(escolhaUserAlterar == 0) {
						menuAtual = menuConsultarCadastro;
						executarConsultaCadastro();
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
