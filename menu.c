#include "global/global.h"
#include "menu.h"

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
	
/** Para uso Posterior
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
**/
//

//Criação de variáveis de escopo global para manipulação em funções
	

	int *pEscolhaUser = &escolhaUser;
	
	int loopMenu = 1; //Variável responsável por controlar o loop do 'do while' dentro da função main, sendo o único jeito de encerrar o menu, caso seja digitado a opção 0 dentro do menu principal.
//

void main() {
	setlocale(LC_ALL, "Portuguese");
	
	menuAtual = menuPrincipal;

	do{
	    system("color E0"); //Definição da cor do sistema
	    
	    // Comente esse código para tirar a trava de tela
//		    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//			SMALL_RECT rect = {0, 0, 101, 42}; // Define o tamanho da janela
//			SetConsoleWindowInfo(hConsole, TRUE, &rect); // Define o tamanho da janela
//			SetWindowLong(GetConsoleWindow(), GWL_STYLE, GetWindowLong(GetConsoleWindow(), GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    	//Comente esse código para tirar a trava de tela
    	
		exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);		
		
		exibirMensagem(); //Exibindo eventuais mensagens, por padrão erro = 0, portanto, sem mensagens
		
		exibirErro(); //Exibindo eventuais erros, por padrão erro = 0, portanto, sem erros
		
		exibirInterfaceOpcoes();
		
		receberOpcaoMenu(); //Solicita a escolha do usuário e faz o tratamento de erros
		
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
			erro = 2; //Assume todos os valores retornando um erro de número inválido até que seja conferido pelo for
			for(i = 0; i < menuAtual.numeroDeOpcoes; i++) { // Laço para percorrer todas as opções do Menu e ver se existe a opção digitada
				if(menuAtual.opcoes[i].numeroDaOpcao == escolhaUser) { //Caso exista alguma opção que o usuário digitou
					erro = 0; //Reatribui o valor do erro
					menuAtual.opcoes[i].funcao(menuAtual); //Executa da função presente no item do menu
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
	
	if(mensagem != 0) exibirInterfaceInteracao(res);
	mensagem = 0;
}

void exibirErro() {
	char res[50];
	switch(erro) {
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
		case 5:
			strcpy(res, "Erro: Você ainda não digitou nenhum campo para poder alterar!");
			break;
		case 6:
			strcpy(res, "Erro: Campo inválido!");
			break;
		case 7:
			strcpy(res, "Erro: Você ainda não digitou esse campo!");
			break;
		case 8:
			strcpy(res, "Erro: Você só pode alterar o primeiro campo!");
			break;
		default:;
	}
	
	if(erro != 0) exibirInterfaceInteracao(res);
	erro = 0;
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
		**/
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
