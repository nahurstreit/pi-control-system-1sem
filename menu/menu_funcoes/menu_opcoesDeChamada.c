#include "../../global/global.h"
#include "../menu.h"

//Funções a serem executadas pelas opções dos Menus
	//Funções de chamada do Menu
		void exibirMenuPrincipal() {
			menuAtual = menuCadastro;
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
