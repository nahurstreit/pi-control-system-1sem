#include "../../global/global.h"
#include "../../interface/interface.h"
#include "../../producao/producao.h"
#include "../menu.h"


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
			

			//Funções menuOrdemProducao
				void exibirMenuOrdemProducao() {
					menuAtual = menuOrdemProducao;
				}
					void exibirMenuNovaOrdemProducao() {
						escolhaUser = 5;
						novaOrdem();
						
					}
						void executarImpressaoOP() {
							imprimirOrdemProducao();
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
			//
	//
	
	//Função de fim do Menu
		void fimDoMenu() {
			loopMenu = 0;
		}
	//
