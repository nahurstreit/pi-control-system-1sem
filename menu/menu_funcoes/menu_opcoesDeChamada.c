#include "../../global/global.h"
#include "../../interface/interface.h"
#include "../../producao/producao.h"
#include "../menu.h"


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
						
						void executarNovoProduto() {
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
			

			//Fun��es menuOrdemProducao
				void exibirMenuOrdemProducao() {
					menuAtual = menuOrdemProducao;
				}
					void exibirMenuNovaOrdemProducao() {
						escolhaUser = 5;
						novaOrdem(false);
						if(mensagem == Mensagem_Producao_Nova){ 
							do{
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								exibirMensagem();
								exibirErro();
								exibirInterfaceNovaProducao(producaoAtiva);
								exibirInterfaceOpcoes();
								receberOpcaoMenu();
							} while(escolhaUser != 0);
						}
					}
						void executarImpressaoOP() {
							imprimirOrdemProducao();
							printf("Impress�o em andamento. ");
							mensagem = Mensagem_Impressao_Concluida;
							system("pause");
						}
					
					void exibirMenuConsultarOrdemProducao() {
						menuAtual = menuConsultarOrdemProducao;
						executarConsultaOrdemProducao();
					}
					
					void executarConsultaOrdemProducao() {
						int estado = 0;
						int *pEstado = &estado;
						consultaProducoes(pEstado);
						if(estado == 1) {
							do{
								exibirInterfaceTitulo(menuAtual.tituloDoMenu, 1);
								exibirMensagem();
								exibirErro();
								exibirInterfaceNovaProducao(producaoAtiva);
								menuAtual = menuConsultarOrdemProducao;
								exibirInterfaceOpcoes();
								receberOpcaoMenu();
							} while(escolhaUser != 0 && escolhaUser != 9);
							remove("tempImpress.txt");
						} else if(estado == 0) {
							exibirMenuOrdemProducao();
						}
					}
						
						void executarAlterarOP() {
							alterarProducao();
						}
						
						void executarAdicionarNovosItensOP() {
							novaOrdem(true);
						}
						
						void executarExcluirItemOP() {
							excluirItemProducao();
						}
			//
	//
	
	//Fun��o de fim do Menu
		void fimDoMenu() {
			loopMenu = 0;
		}
	//
